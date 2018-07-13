#pragma once
namespace socketspace{
	using namespace System;
	using namespace System::Net;
	using namespace System::Text;
	using namespace System::Threading;
	using namespace System::Threading::Tasks;
	using namespace System::Net::Sockets;
	using namespace System::Windows::Forms;
	delegate void listen();
	delegate void MsgIn(String^ str, Socket^ soc);
	delegate void ReceiveMsg(String^ str);   //�յ���Ϣ
	public delegate void clientleave();
	public delegate void nulldelegate();
	ref class socketClient {
	public:
		//�¼�ί��
		delegate void Connected();           //�ɹ�����
		static Connected^ Server_Connected =gcnew Connected(socketClient::nullfunc);
		static nulldelegate^ leave = gcnew nulldelegate(nullfunc);
		static ReceiveMsg^ Message_Receive = gcnew ReceiveMsg(socketClient::nullfunc2); //�յ���Ϣ
		Socket^ clientSocket = gcnew Socket(AddressFamily::InterNetwork, SocketType::Stream, ProtocolType::Tcp);
		bool isConnected;
		int port;
		String^ recmessstr;
		IPAddress^ server_ip;
		socketClient(IPAddress^ _ip, int _port)
		{
			server_ip = _ip;
			port = _port;
		}
		bool Connect() {
			try
			{
				clientSocket->Connect(server_ip, port);
			}
			catch(Exception^ e)
			{
				return false;
			}
			Server_Connected(); //�ɹ�����
			isConnected = true;
			Task^ t = Task::Factory->StartNew(gcnew Action(this,&socketClient::startrecieve));
			return true;

		}
		EndPoint^ getEndpoint()
		{
			if (isConnected)
				return clientSocket->LocalEndPoint;
			else
				return nullptr;
		}
		void send(String^ str) {
			if (isConnected) {
				try
				{
					array<unsigned char,1>^ td= Encoding::UTF8->GetBytes(str);
					clientSocket->Send(td);
				}
				catch(Exception^ e)
				{

				}
			}
		}
		static void nullfunc(){}
		static void nullfunc2(String^ str) {}
	private:
		void startrecieve() {
			ReceiveMessage();
		}
		void ReceiveMessage() {
			array<unsigned char,1> ^arrb = gcnew array<unsigned char, 1>(1024);
			Socket^ myClientSocket = clientSocket;
			while (true)
			{
				try
				{

					//Debug.WriteLine("�ȴ���Ϣ�ִ�." + AppDomain.GetCurrentThreadId().ToString());
					//ͨ��clientSocket��������  
					int receiveNumber = myClientSocket->Receive(arrb);
					if (receiveNumber <= 0)
					{
						leave();
						break;
					}

					array<unsigned char,1>^ factarr = gcnew array<unsigned char,1>(receiveNumber);
					recmessstr = Encoding::UTF8->GetString(arrb);
					//Task^ te =Task::Factory->StartNew(gcnew Action(this,&socketClient::messarrive));
					messarrive();
					//Debug.WriteLine("��Ϣ�ִ�." + Encoding.ASCII.GetString(result)+" "+ AppDomain.GetCurrentThreadId().ToString());

				}
				catch (Exception^ ex)
				{
					leave();
					break;
				}
			}

		}

		void messarrive() {
			Message_Receive(recmessstr);
			recmessstr="";
		}
	};
	ref class socketServer {
	public:
		static MsgIn^ MessageRec=gcnew MsgIn(socketServer::nullfun3);   //��Ϣ�ִ�
		static listen^ listenaction = gcnew listen(socketServer::nullfun);
		static Socket^ serverSocket;
		
		static String^ recstr;
		bool isCreated = false;
		static Socket^ client;
		static clientleave^ clientleavefun = gcnew clientleave(socketServer::nullfun);  //�ͻ����뿪
		static array<IPAddress^,1>^ getIP() {
			String^ name = Dns::GetHostName();
			IPHostEntry^ localhost = Dns::GetHostByName(name);
			
			return localhost->AddressList;
		}
		static void ReceiveMessage(Object^ clientSocket)
		{
			array<unsigned char, 1>^ arrb = gcnew array<unsigned char, 1>(1024);
			//byte[] arrb = new byte[1024];
			Socket^ myClientSocket = (Socket^)clientSocket;			
			while (true)
			{
				try
				{
					//Debug.WriteLine("�ȴ���Ϣ�ִ�." + AppDomain.GetCurrentThreadId().ToString());
					//ͨ��clientSocket��������  
					int receiveNumber = myClientSocket->Receive(arrb);
					
					if (receiveNumber <= 0) {
						//�ͻ����뿪
						serverSocket->Close();
						clientleavefun();
						break;
					}
					array<unsigned char, 1>^ factarr = gcnew array<unsigned char, 1>(receiveNumber);
					//byte[] factarr = new byte[receiveNumber];
					Array::Copy(arrb, factarr, receiveNumber);
					//Debug::WriteLine(Encoding::UTF8::GetString(factarr));
					//Console.WriteLine("���տͻ���{0}��Ϣ{1}", myClientSocket.RemoteEndPoint.ToString(), Encoding.ASCII.GetString(result, 0, receiveNumber));
					//Task^ t=Task::Factory->StartNew(gcnew Action(this,&socketServer::messagerec));
					

					//Thread te = new Thread(() = >{ MessageRec(Encoding::UTF8::GetString(factarr), myClientSocket);
					recstr = Encoding::UTF8->GetString(factarr);
					client = myClientSocket;
					messagerec();
					//});
					
					//Debug.WriteLine("��Ϣ�ִ�." + Encoding.ASCII.GetString(result)+" "+ AppDomain.GetCurrentThreadId().ToString());

				}
				catch (Exception^ ex)
				{

					serverSocket->Close();
					clientleavefun();
					break;
				}
			}
		}
		static void messagerec() {
			MessageRec(recstr,client);
		}
		bool createserver(String^ ipstr) {
			if (isCreated) return false;
			try {
				serverSocket = gcnew Socket(AddressFamily::InterNetwork, SocketType::Stream, ProtocolType::Tcp);
				IPAddress^ localip = IPAddress::Parse(ipstr);
				IPEndPoint^ point = gcnew IPEndPoint(localip, 9239);
				serverSocket->Bind(point);
				serverSocket->Listen(10);
				Task^ t = Task::Factory->StartNew(gcnew Action(this, &socketServer::listenFun));  //���������߳�
				isCreated = true;
				return true;
			}
			catch (Exception^ e) { return false; }
		}

		void close() {
			serverSocket->Shutdown(SocketShutdown::Both);
			serverSocket->Close();
			isCreated = false;
			
		}
		void listenFun() {
			//MessageBox::Show("��ʼ����");
			while (true) {
				try
				{
					Socket^ temp = serverSocket->Accept();
					//MessageBox::Show("Client entered");
					
					
					
						//ͬ��ģʽ
					    
						Thread^ MsgThread = gcnew Thread(gcnew ParameterizedThreadStart(socketServer::ReceiveMessage));
						MsgThread->Start(temp);
						//MsgThread.Start(temp);
					
					
				}
				catch(Exception^ e)
				{
					isCreated = false;
					break;
				}
			}
			//listenaction();
		}

	private:
		static void nullfun() {

		}
		static void nullfun3(String^ str, Socket^ soc) {
			
		}
	};
}