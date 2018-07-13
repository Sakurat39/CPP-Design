#include "chessDomin.h"
#include "socket.h"
#include "ipinput.h"
#include "ServerCreate.h"
#pragma once

namespace ChesscppCLR {
	//修复 1.悔棋功能
	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;
	using namespace System::Threading::Tasks;
	using namespace System::Xml;
	using namespace System::Xaml;
	using namespace System::Diagnostics;
	using namespace chessDom;
	using namespace Compitition;
	using namespace System::Net::Sockets;
	using namespace socketspace;
	
	/// <summary>
	/// Summary for MainForm
	/// </summary>
	enum net_type {
		colordistribution = 1,
		Clientjoin = 1,
		targetClick = 2,
		Clientrestract = 3,
		SocketleaveState = 4,
		restep = 5,
		sendmessage = 6,
	};
	
	
	public ref class MainForm : public System::Windows::Forms::Form
	{
	public:
		Form f1;
		bool select = 0;
		static fright^ currfright;
		static bool frighting = false;
		static bool netmode = false;
		static socketClient^ sc;
		static socketServer^ ss;
		
		//Net
		static ChessCorlor net_color;
		static bool servercreated = false;
		static bool net_netmode = false;
		static Socket^ targetsocket = nullptr;
		static bool begin = false;
	private: 
		Task^ blinktask;
			 bool isMouseDown = false;
			 int c_x; int c_y;
			 bool hasChessmanBeSelected = false;
			 static int times = 0;
			 bool taskrunning = false;
	public:
		
#pragma region picbox



	private: System::Windows::Forms::PictureBox^  pictureBox1;
	public:
	private: System::Windows::Forms::PictureBox^  pictureBox2;
	private: System::Windows::Forms::PictureBox^  pictureBox3;
	private: System::Windows::Forms::PictureBox^  pictureBox4;
	private: System::Windows::Forms::PictureBox^  pictureBox5;
	private: System::Windows::Forms::PictureBox^  pictureBox6;
	private: System::Windows::Forms::PictureBox^  pictureBox7;
	private: System::Windows::Forms::PictureBox^  pictureBox8;
	private: System::Windows::Forms::PictureBox^  pictureBox9;
	private: System::Windows::Forms::PictureBox^  pictureBox18;
	private: System::Windows::Forms::PictureBox^  pictureBox17;
	private: System::Windows::Forms::PictureBox^  pictureBox16;
	private: System::Windows::Forms::PictureBox^  pictureBox15;
	private: System::Windows::Forms::PictureBox^  pictureBox14;
	private: System::Windows::Forms::PictureBox^  pictureBox13;
	private: System::Windows::Forms::PictureBox^  pictureBox12;
	private: System::Windows::Forms::PictureBox^  pictureBox11;
	private: System::Windows::Forms::PictureBox^  pictureBox10;
	private: System::Windows::Forms::PictureBox^  pictureBox27;
	private: System::Windows::Forms::PictureBox^  pictureBox26;
	private: System::Windows::Forms::PictureBox^  pictureBox25;
	private: System::Windows::Forms::PictureBox^  pictureBox24;
	private: System::Windows::Forms::PictureBox^  pictureBox23;
	private: System::Windows::Forms::PictureBox^  pictureBox22;
	private: System::Windows::Forms::PictureBox^  pictureBox21;
	private: System::Windows::Forms::PictureBox^  pictureBox20;
	private: System::Windows::Forms::PictureBox^  pictureBox19;
	private: System::Windows::Forms::PictureBox^  pictureBox36;
	private: System::Windows::Forms::PictureBox^  pictureBox35;
	private: System::Windows::Forms::PictureBox^  pictureBox34;
	private: System::Windows::Forms::PictureBox^  pictureBox33;
	private: System::Windows::Forms::PictureBox^  pictureBox32;
	private: System::Windows::Forms::PictureBox^  pictureBox31;
	private: System::Windows::Forms::PictureBox^  pictureBox30;
	private: System::Windows::Forms::PictureBox^  pictureBox29;
	private: System::Windows::Forms::PictureBox^  pictureBox28;
	private: System::Windows::Forms::PictureBox^  pictureBox45;
	private: System::Windows::Forms::PictureBox^  pictureBox44;
	private: System::Windows::Forms::PictureBox^  pictureBox43;
	private: System::Windows::Forms::PictureBox^  pictureBox42;
	private: System::Windows::Forms::PictureBox^  pictureBox41;
	private: System::Windows::Forms::PictureBox^  pictureBox40;
	private: System::Windows::Forms::PictureBox^  pictureBox39;
	private: System::Windows::Forms::PictureBox^  pictureBox38;
	private: System::Windows::Forms::PictureBox^  pictureBox37;
	private: System::Windows::Forms::PictureBox^  pictureBox54;
	private: System::Windows::Forms::PictureBox^  pictureBox53;
	private: System::Windows::Forms::PictureBox^  pictureBox52;
	private: System::Windows::Forms::PictureBox^  pictureBox51;
	private: System::Windows::Forms::PictureBox^  pictureBox50;
	private: System::Windows::Forms::PictureBox^  pictureBox49;
	private: System::Windows::Forms::PictureBox^  pictureBox48;
	private: System::Windows::Forms::PictureBox^  pictureBox47;
	private: System::Windows::Forms::PictureBox^  pictureBox46;
	private: System::Windows::Forms::PictureBox^  pictureBox63;
	private: System::Windows::Forms::PictureBox^  pictureBox62;
	private: System::Windows::Forms::PictureBox^  pictureBox61;
	private: System::Windows::Forms::PictureBox^  pictureBox60;
	private: System::Windows::Forms::PictureBox^  pictureBox59;
	private: System::Windows::Forms::PictureBox^  pictureBox58;
	private: System::Windows::Forms::PictureBox^  pictureBox57;
	private: System::Windows::Forms::PictureBox^  pictureBox56;
	private: System::Windows::Forms::PictureBox^  pictureBox55;
	private: System::Windows::Forms::PictureBox^  pictureBox72;
	private: System::Windows::Forms::PictureBox^  pictureBox71;
	private: System::Windows::Forms::PictureBox^  pictureBox70;
	private: System::Windows::Forms::PictureBox^  pictureBox69;
	private: System::Windows::Forms::PictureBox^  pictureBox68;
	private: System::Windows::Forms::PictureBox^  pictureBox67;
	private: System::Windows::Forms::PictureBox^  pictureBox66;
	private: System::Windows::Forms::PictureBox^  pictureBox65;
	private: System::Windows::Forms::PictureBox^  pictureBox64;
	private: System::Windows::Forms::PictureBox^  pictureBox81;
	private: System::Windows::Forms::PictureBox^  pictureBox80;
	private: System::Windows::Forms::PictureBox^  pictureBox79;
	private: System::Windows::Forms::PictureBox^  pictureBox78;
	private: System::Windows::Forms::PictureBox^  pictureBox77;
	private: System::Windows::Forms::PictureBox^  pictureBox76;
	private: System::Windows::Forms::PictureBox^  pictureBox75;
	private: System::Windows::Forms::PictureBox^  pictureBox74;
	private: System::Windows::Forms::PictureBox^  pictureBox73;
	private: System::Windows::Forms::Panel^  panel1;
	private: System::Windows::Forms::PictureBox^  pictureBox82;
	private: System::Windows::Forms::PictureBox^  pictureBox83;
	private: System::Windows::Forms::PictureBox^  pictureBox84;
	private: System::Windows::Forms::PictureBox^  pictureBox85;
	private: System::Windows::Forms::PictureBox^  pictureBox86;
	private: System::Windows::Forms::PictureBox^  pictureBox87;
	private: System::Windows::Forms::PictureBox^  pictureBox88;
	private: System::Windows::Forms::PictureBox^  pictureBox89;
	private: System::Windows::Forms::PictureBox^  pictureBox90;
    private: System::Windows::Forms::Panel^  panel2;
#pragma endregion


	public:

		Image^ currselectchessima;
		     array<bool^, 2> ^clickabletable = gcnew array<bool^, 2>(10, 9);
private: System::Windows::Forms::Label^  label1;
private: System::Windows::Forms::Label^  label2;
private: System::Windows::Forms::Label^  label3;
private: System::Windows::Forms::Label^  label4;
private: System::Windows::Forms::Button^  button2;
private: System::Windows::Forms::Button^  button1;
private: System::Windows::Forms::Button^  button3;
private: System::Windows::Forms::Label^  label5;
private: System::Windows::Forms::Button^  button4;
private: System::Windows::Forms::Button^  button5;
private: System::Windows::Forms::Panel^  panel3;
private: System::Windows::Forms::Label^  label6;
private: System::Windows::Forms::RichTextBox^  richTextBox1;
private: System::Windows::Forms::TextBox^  textBox1;
public:

public:


		 array<PictureBox^, 2> ^ps = gcnew array<PictureBox^, 2>(10, 9);
		 void createserver(int cc,String^ ipstr) {
			 if (net_netmode) return;
			 ss = gcnew socketServer();
			 if (ss->createserver(ipstr)) { log("Server Created"); servercreated = true; net_netmode = true; 
			 button4->Enabled = false;
			 button5->Enabled = false;
			 button1->Enabled = false;
			 button2->Enabled = true;
			 };
			 
		 }
		 void serverreceive() {

		 }

		MainForm(void)
		{
			
			System::Windows::Forms::Control::CheckForIllegalCrossThreadCalls = false;
			InitializeComponent();
			setpicboxes();
			Height = 758;
			Width = 956;
			int avgw = Width / 9;
			int avgh = (Height) / 10;
			
			//
			//TODO: Add the constructor code here
			//
		}

	protected:  
		/// <summary>
		/// Clean up any resources being used.
		/// </summary>
		~MainForm()
		{
			if (components)
			{
				delete components;
			}
		}

	protected:
		
		
	private:
		/// <summary>
		/// Required designer variable.
		/// </summary>
		System::ComponentModel::Container ^components;

#pragma region Windows Form Designer generated code
		/// <summary>
		/// Required method for Designer support - do not modify
		/// the contents of this method with the code editor.
		/// </summary>
		void InitializeComponent(void)
		{
			System::ComponentModel::ComponentResourceManager^  resources = (gcnew System::ComponentModel::ComponentResourceManager(MainForm::typeid));
			this->pictureBox1 = (gcnew System::Windows::Forms::PictureBox());
			this->pictureBox2 = (gcnew System::Windows::Forms::PictureBox());
			this->pictureBox3 = (gcnew System::Windows::Forms::PictureBox());
			this->pictureBox4 = (gcnew System::Windows::Forms::PictureBox());
			this->pictureBox5 = (gcnew System::Windows::Forms::PictureBox());
			this->pictureBox6 = (gcnew System::Windows::Forms::PictureBox());
			this->pictureBox7 = (gcnew System::Windows::Forms::PictureBox());
			this->pictureBox8 = (gcnew System::Windows::Forms::PictureBox());
			this->pictureBox9 = (gcnew System::Windows::Forms::PictureBox());
			this->pictureBox18 = (gcnew System::Windows::Forms::PictureBox());
			this->pictureBox17 = (gcnew System::Windows::Forms::PictureBox());
			this->pictureBox16 = (gcnew System::Windows::Forms::PictureBox());
			this->pictureBox15 = (gcnew System::Windows::Forms::PictureBox());
			this->pictureBox14 = (gcnew System::Windows::Forms::PictureBox());
			this->pictureBox13 = (gcnew System::Windows::Forms::PictureBox());
			this->pictureBox12 = (gcnew System::Windows::Forms::PictureBox());
			this->pictureBox11 = (gcnew System::Windows::Forms::PictureBox());
			this->pictureBox10 = (gcnew System::Windows::Forms::PictureBox());
			this->pictureBox27 = (gcnew System::Windows::Forms::PictureBox());
			this->pictureBox26 = (gcnew System::Windows::Forms::PictureBox());
			this->pictureBox25 = (gcnew System::Windows::Forms::PictureBox());
			this->pictureBox24 = (gcnew System::Windows::Forms::PictureBox());
			this->pictureBox23 = (gcnew System::Windows::Forms::PictureBox());
			this->pictureBox22 = (gcnew System::Windows::Forms::PictureBox());
			this->pictureBox21 = (gcnew System::Windows::Forms::PictureBox());
			this->pictureBox20 = (gcnew System::Windows::Forms::PictureBox());
			this->pictureBox19 = (gcnew System::Windows::Forms::PictureBox());
			this->pictureBox36 = (gcnew System::Windows::Forms::PictureBox());
			this->pictureBox35 = (gcnew System::Windows::Forms::PictureBox());
			this->pictureBox34 = (gcnew System::Windows::Forms::PictureBox());
			this->pictureBox33 = (gcnew System::Windows::Forms::PictureBox());
			this->pictureBox32 = (gcnew System::Windows::Forms::PictureBox());
			this->pictureBox31 = (gcnew System::Windows::Forms::PictureBox());
			this->pictureBox30 = (gcnew System::Windows::Forms::PictureBox());
			this->pictureBox29 = (gcnew System::Windows::Forms::PictureBox());
			this->pictureBox28 = (gcnew System::Windows::Forms::PictureBox());
			this->pictureBox45 = (gcnew System::Windows::Forms::PictureBox());
			this->pictureBox44 = (gcnew System::Windows::Forms::PictureBox());
			this->pictureBox43 = (gcnew System::Windows::Forms::PictureBox());
			this->pictureBox42 = (gcnew System::Windows::Forms::PictureBox());
			this->pictureBox41 = (gcnew System::Windows::Forms::PictureBox());
			this->pictureBox40 = (gcnew System::Windows::Forms::PictureBox());
			this->pictureBox39 = (gcnew System::Windows::Forms::PictureBox());
			this->pictureBox38 = (gcnew System::Windows::Forms::PictureBox());
			this->pictureBox37 = (gcnew System::Windows::Forms::PictureBox());
			this->pictureBox54 = (gcnew System::Windows::Forms::PictureBox());
			this->pictureBox53 = (gcnew System::Windows::Forms::PictureBox());
			this->pictureBox52 = (gcnew System::Windows::Forms::PictureBox());
			this->pictureBox51 = (gcnew System::Windows::Forms::PictureBox());
			this->pictureBox50 = (gcnew System::Windows::Forms::PictureBox());
			this->pictureBox49 = (gcnew System::Windows::Forms::PictureBox());
			this->pictureBox48 = (gcnew System::Windows::Forms::PictureBox());
			this->pictureBox47 = (gcnew System::Windows::Forms::PictureBox());
			this->pictureBox46 = (gcnew System::Windows::Forms::PictureBox());
			this->pictureBox63 = (gcnew System::Windows::Forms::PictureBox());
			this->pictureBox62 = (gcnew System::Windows::Forms::PictureBox());
			this->pictureBox61 = (gcnew System::Windows::Forms::PictureBox());
			this->pictureBox60 = (gcnew System::Windows::Forms::PictureBox());
			this->pictureBox59 = (gcnew System::Windows::Forms::PictureBox());
			this->pictureBox58 = (gcnew System::Windows::Forms::PictureBox());
			this->pictureBox57 = (gcnew System::Windows::Forms::PictureBox());
			this->pictureBox56 = (gcnew System::Windows::Forms::PictureBox());
			this->pictureBox55 = (gcnew System::Windows::Forms::PictureBox());
			this->pictureBox72 = (gcnew System::Windows::Forms::PictureBox());
			this->pictureBox71 = (gcnew System::Windows::Forms::PictureBox());
			this->pictureBox70 = (gcnew System::Windows::Forms::PictureBox());
			this->pictureBox69 = (gcnew System::Windows::Forms::PictureBox());
			this->pictureBox68 = (gcnew System::Windows::Forms::PictureBox());
			this->pictureBox67 = (gcnew System::Windows::Forms::PictureBox());
			this->pictureBox66 = (gcnew System::Windows::Forms::PictureBox());
			this->pictureBox65 = (gcnew System::Windows::Forms::PictureBox());
			this->pictureBox64 = (gcnew System::Windows::Forms::PictureBox());
			this->pictureBox81 = (gcnew System::Windows::Forms::PictureBox());
			this->pictureBox80 = (gcnew System::Windows::Forms::PictureBox());
			this->pictureBox79 = (gcnew System::Windows::Forms::PictureBox());
			this->pictureBox78 = (gcnew System::Windows::Forms::PictureBox());
			this->pictureBox77 = (gcnew System::Windows::Forms::PictureBox());
			this->pictureBox76 = (gcnew System::Windows::Forms::PictureBox());
			this->pictureBox75 = (gcnew System::Windows::Forms::PictureBox());
			this->pictureBox74 = (gcnew System::Windows::Forms::PictureBox());
			this->pictureBox73 = (gcnew System::Windows::Forms::PictureBox());
			this->panel1 = (gcnew System::Windows::Forms::Panel());
			this->pictureBox83 = (gcnew System::Windows::Forms::PictureBox());
			this->pictureBox84 = (gcnew System::Windows::Forms::PictureBox());
			this->pictureBox85 = (gcnew System::Windows::Forms::PictureBox());
			this->pictureBox86 = (gcnew System::Windows::Forms::PictureBox());
			this->pictureBox87 = (gcnew System::Windows::Forms::PictureBox());
			this->pictureBox88 = (gcnew System::Windows::Forms::PictureBox());
			this->pictureBox89 = (gcnew System::Windows::Forms::PictureBox());
			this->pictureBox90 = (gcnew System::Windows::Forms::PictureBox());
			this->pictureBox82 = (gcnew System::Windows::Forms::PictureBox());
			this->panel2 = (gcnew System::Windows::Forms::Panel());
			this->button5 = (gcnew System::Windows::Forms::Button());
			this->button4 = (gcnew System::Windows::Forms::Button());
			this->label5 = (gcnew System::Windows::Forms::Label());
			this->button3 = (gcnew System::Windows::Forms::Button());
			this->button2 = (gcnew System::Windows::Forms::Button());
			this->button1 = (gcnew System::Windows::Forms::Button());
			this->label4 = (gcnew System::Windows::Forms::Label());
			this->label3 = (gcnew System::Windows::Forms::Label());
			this->label2 = (gcnew System::Windows::Forms::Label());
			this->label1 = (gcnew System::Windows::Forms::Label());
			this->panel3 = (gcnew System::Windows::Forms::Panel());
			this->textBox1 = (gcnew System::Windows::Forms::TextBox());
			this->richTextBox1 = (gcnew System::Windows::Forms::RichTextBox());
			this->label6 = (gcnew System::Windows::Forms::Label());
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox1))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox2))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox3))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox4))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox5))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox6))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox7))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox8))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox9))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox18))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox17))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox16))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox15))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox14))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox13))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox12))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox11))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox10))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox27))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox26))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox25))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox24))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox23))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox22))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox21))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox20))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox19))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox36))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox35))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox34))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox33))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox32))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox31))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox30))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox29))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox28))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox45))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox44))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox43))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox42))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox41))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox40))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox39))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox38))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox37))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox54))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox53))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox52))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox51))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox50))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox49))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox48))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox47))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox46))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox63))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox62))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox61))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox60))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox59))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox58))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox57))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox56))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox55))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox72))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox71))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox70))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox69))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox68))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox67))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox66))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox65))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox64))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox81))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox80))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox79))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox78))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox77))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox76))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox75))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox74))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox73))->BeginInit();
			this->panel1->SuspendLayout();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox83))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox84))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox85))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox86))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox87))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox88))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox89))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox90))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox82))->BeginInit();
			this->panel2->SuspendLayout();
			this->panel3->SuspendLayout();
			this->SuspendLayout();
			// 
			// pictureBox1
			// 
			this->pictureBox1->Image = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"pictureBox1.Image")));
			this->pictureBox1->Location = System::Drawing::Point(6, 8);
			this->pictureBox1->Name = L"pictureBox1";
			this->pictureBox1->Size = System::Drawing::Size(80, 58);
			this->pictureBox1->SizeMode = System::Windows::Forms::PictureBoxSizeMode::StretchImage;
			this->pictureBox1->TabIndex = 1;
			this->pictureBox1->TabStop = false;
			// 
			// pictureBox2
			// 
			this->pictureBox2->Image = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"pictureBox2.Image")));
			this->pictureBox2->Location = System::Drawing::Point(92, 8);
			this->pictureBox2->Name = L"pictureBox2";
			this->pictureBox2->Size = System::Drawing::Size(80, 58);
			this->pictureBox2->SizeMode = System::Windows::Forms::PictureBoxSizeMode::StretchImage;
			this->pictureBox2->TabIndex = 2;
			this->pictureBox2->TabStop = false;
			// 
			// pictureBox3
			// 
			this->pictureBox3->Image = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"pictureBox3.Image")));
			this->pictureBox3->Location = System::Drawing::Point(178, 8);
			this->pictureBox3->Name = L"pictureBox3";
			this->pictureBox3->Size = System::Drawing::Size(80, 58);
			this->pictureBox3->SizeMode = System::Windows::Forms::PictureBoxSizeMode::StretchImage;
			this->pictureBox3->TabIndex = 3;
			this->pictureBox3->TabStop = false;
			// 
			// pictureBox4
			// 
			this->pictureBox4->Image = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"pictureBox4.Image")));
			this->pictureBox4->Location = System::Drawing::Point(264, 8);
			this->pictureBox4->Name = L"pictureBox4";
			this->pictureBox4->Size = System::Drawing::Size(80, 58);
			this->pictureBox4->SizeMode = System::Windows::Forms::PictureBoxSizeMode::StretchImage;
			this->pictureBox4->TabIndex = 4;
			this->pictureBox4->TabStop = false;
			// 
			// pictureBox5
			// 
			this->pictureBox5->Image = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"pictureBox5.Image")));
			this->pictureBox5->Location = System::Drawing::Point(350, 8);
			this->pictureBox5->Name = L"pictureBox5";
			this->pictureBox5->Size = System::Drawing::Size(80, 58);
			this->pictureBox5->SizeMode = System::Windows::Forms::PictureBoxSizeMode::StretchImage;
			this->pictureBox5->TabIndex = 5;
			this->pictureBox5->TabStop = false;
			// 
			// pictureBox6
			// 
			this->pictureBox6->Image = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"pictureBox6.Image")));
			this->pictureBox6->Location = System::Drawing::Point(436, 8);
			this->pictureBox6->Name = L"pictureBox6";
			this->pictureBox6->Size = System::Drawing::Size(80, 58);
			this->pictureBox6->SizeMode = System::Windows::Forms::PictureBoxSizeMode::StretchImage;
			this->pictureBox6->TabIndex = 6;
			this->pictureBox6->TabStop = false;
			// 
			// pictureBox7
			// 
			this->pictureBox7->Image = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"pictureBox7.Image")));
			this->pictureBox7->Location = System::Drawing::Point(522, 8);
			this->pictureBox7->Name = L"pictureBox7";
			this->pictureBox7->Size = System::Drawing::Size(80, 58);
			this->pictureBox7->SizeMode = System::Windows::Forms::PictureBoxSizeMode::StretchImage;
			this->pictureBox7->TabIndex = 7;
			this->pictureBox7->TabStop = false;
			// 
			// pictureBox8
			// 
			this->pictureBox8->Image = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"pictureBox8.Image")));
			this->pictureBox8->Location = System::Drawing::Point(608, 8);
			this->pictureBox8->Name = L"pictureBox8";
			this->pictureBox8->Size = System::Drawing::Size(80, 58);
			this->pictureBox8->SizeMode = System::Windows::Forms::PictureBoxSizeMode::StretchImage;
			this->pictureBox8->TabIndex = 8;
			this->pictureBox8->TabStop = false;
			// 
			// pictureBox9
			// 
			this->pictureBox9->Image = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"pictureBox9.Image")));
			this->pictureBox9->Location = System::Drawing::Point(694, 8);
			this->pictureBox9->Name = L"pictureBox9";
			this->pictureBox9->Size = System::Drawing::Size(80, 58);
			this->pictureBox9->SizeMode = System::Windows::Forms::PictureBoxSizeMode::StretchImage;
			this->pictureBox9->TabIndex = 9;
			this->pictureBox9->TabStop = false;
			// 
			// pictureBox18
			// 
			this->pictureBox18->Location = System::Drawing::Point(6, 72);
			this->pictureBox18->Name = L"pictureBox18";
			this->pictureBox18->Size = System::Drawing::Size(80, 58);
			this->pictureBox18->TabIndex = 10;
			this->pictureBox18->TabStop = false;
			// 
			// pictureBox17
			// 
			this->pictureBox17->Location = System::Drawing::Point(92, 72);
			this->pictureBox17->Name = L"pictureBox17";
			this->pictureBox17->Size = System::Drawing::Size(80, 58);
			this->pictureBox17->TabIndex = 11;
			this->pictureBox17->TabStop = false;
			// 
			// pictureBox16
			// 
			this->pictureBox16->Location = System::Drawing::Point(178, 72);
			this->pictureBox16->Name = L"pictureBox16";
			this->pictureBox16->Size = System::Drawing::Size(80, 58);
			this->pictureBox16->TabIndex = 12;
			this->pictureBox16->TabStop = false;
			// 
			// pictureBox15
			// 
			this->pictureBox15->Location = System::Drawing::Point(264, 72);
			this->pictureBox15->Name = L"pictureBox15";
			this->pictureBox15->Size = System::Drawing::Size(80, 58);
			this->pictureBox15->TabIndex = 13;
			this->pictureBox15->TabStop = false;
			// 
			// pictureBox14
			// 
			this->pictureBox14->Location = System::Drawing::Point(350, 72);
			this->pictureBox14->Name = L"pictureBox14";
			this->pictureBox14->Size = System::Drawing::Size(80, 58);
			this->pictureBox14->TabIndex = 14;
			this->pictureBox14->TabStop = false;
			// 
			// pictureBox13
			// 
			this->pictureBox13->Location = System::Drawing::Point(436, 72);
			this->pictureBox13->Name = L"pictureBox13";
			this->pictureBox13->Size = System::Drawing::Size(80, 58);
			this->pictureBox13->TabIndex = 15;
			this->pictureBox13->TabStop = false;
			// 
			// pictureBox12
			// 
			this->pictureBox12->Location = System::Drawing::Point(522, 72);
			this->pictureBox12->Name = L"pictureBox12";
			this->pictureBox12->Size = System::Drawing::Size(80, 58);
			this->pictureBox12->TabIndex = 16;
			this->pictureBox12->TabStop = false;
			// 
			// pictureBox11
			// 
			this->pictureBox11->Location = System::Drawing::Point(608, 72);
			this->pictureBox11->Name = L"pictureBox11";
			this->pictureBox11->Size = System::Drawing::Size(80, 58);
			this->pictureBox11->TabIndex = 17;
			this->pictureBox11->TabStop = false;
			// 
			// pictureBox10
			// 
			this->pictureBox10->Location = System::Drawing::Point(694, 72);
			this->pictureBox10->Name = L"pictureBox10";
			this->pictureBox10->Size = System::Drawing::Size(80, 58);
			this->pictureBox10->TabIndex = 18;
			this->pictureBox10->TabStop = false;
			// 
			// pictureBox27
			// 
			this->pictureBox27->Location = System::Drawing::Point(6, 136);
			this->pictureBox27->Name = L"pictureBox27";
			this->pictureBox27->Size = System::Drawing::Size(80, 58);
			this->pictureBox27->TabIndex = 19;
			this->pictureBox27->TabStop = false;
			// 
			// pictureBox26
			// 
			this->pictureBox26->Image = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"pictureBox26.Image")));
			this->pictureBox26->Location = System::Drawing::Point(92, 136);
			this->pictureBox26->Name = L"pictureBox26";
			this->pictureBox26->Size = System::Drawing::Size(80, 58);
			this->pictureBox26->SizeMode = System::Windows::Forms::PictureBoxSizeMode::StretchImage;
			this->pictureBox26->TabIndex = 20;
			this->pictureBox26->TabStop = false;
			// 
			// pictureBox25
			// 
			this->pictureBox25->Location = System::Drawing::Point(178, 136);
			this->pictureBox25->Name = L"pictureBox25";
			this->pictureBox25->Size = System::Drawing::Size(80, 58);
			this->pictureBox25->TabIndex = 21;
			this->pictureBox25->TabStop = false;
			// 
			// pictureBox24
			// 
			this->pictureBox24->Location = System::Drawing::Point(264, 136);
			this->pictureBox24->Name = L"pictureBox24";
			this->pictureBox24->Size = System::Drawing::Size(80, 58);
			this->pictureBox24->TabIndex = 22;
			this->pictureBox24->TabStop = false;
			// 
			// pictureBox23
			// 
			this->pictureBox23->Location = System::Drawing::Point(350, 136);
			this->pictureBox23->Name = L"pictureBox23";
			this->pictureBox23->Size = System::Drawing::Size(80, 58);
			this->pictureBox23->TabIndex = 23;
			this->pictureBox23->TabStop = false;
			// 
			// pictureBox22
			// 
			this->pictureBox22->Location = System::Drawing::Point(436, 136);
			this->pictureBox22->Name = L"pictureBox22";
			this->pictureBox22->Size = System::Drawing::Size(80, 58);
			this->pictureBox22->TabIndex = 24;
			this->pictureBox22->TabStop = false;
			// 
			// pictureBox21
			// 
			this->pictureBox21->Location = System::Drawing::Point(522, 136);
			this->pictureBox21->Name = L"pictureBox21";
			this->pictureBox21->Size = System::Drawing::Size(80, 58);
			this->pictureBox21->TabIndex = 25;
			this->pictureBox21->TabStop = false;
			// 
			// pictureBox20
			// 
			this->pictureBox20->Image = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"pictureBox20.Image")));
			this->pictureBox20->Location = System::Drawing::Point(608, 136);
			this->pictureBox20->Name = L"pictureBox20";
			this->pictureBox20->Size = System::Drawing::Size(80, 58);
			this->pictureBox20->SizeMode = System::Windows::Forms::PictureBoxSizeMode::StretchImage;
			this->pictureBox20->TabIndex = 26;
			this->pictureBox20->TabStop = false;
			// 
			// pictureBox19
			// 
			this->pictureBox19->Location = System::Drawing::Point(694, 136);
			this->pictureBox19->Name = L"pictureBox19";
			this->pictureBox19->Size = System::Drawing::Size(80, 58);
			this->pictureBox19->TabIndex = 27;
			this->pictureBox19->TabStop = false;
			// 
			// pictureBox36
			// 
			this->pictureBox36->Image = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"pictureBox36.Image")));
			this->pictureBox36->Location = System::Drawing::Point(6, 200);
			this->pictureBox36->Name = L"pictureBox36";
			this->pictureBox36->Size = System::Drawing::Size(80, 58);
			this->pictureBox36->SizeMode = System::Windows::Forms::PictureBoxSizeMode::StretchImage;
			this->pictureBox36->TabIndex = 28;
			this->pictureBox36->TabStop = false;
			// 
			// pictureBox35
			// 
			this->pictureBox35->Location = System::Drawing::Point(92, 200);
			this->pictureBox35->Name = L"pictureBox35";
			this->pictureBox35->Size = System::Drawing::Size(80, 58);
			this->pictureBox35->TabIndex = 29;
			this->pictureBox35->TabStop = false;
			// 
			// pictureBox34
			// 
			this->pictureBox34->Image = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"pictureBox34.Image")));
			this->pictureBox34->Location = System::Drawing::Point(178, 200);
			this->pictureBox34->Name = L"pictureBox34";
			this->pictureBox34->Size = System::Drawing::Size(80, 58);
			this->pictureBox34->SizeMode = System::Windows::Forms::PictureBoxSizeMode::StretchImage;
			this->pictureBox34->TabIndex = 30;
			this->pictureBox34->TabStop = false;
			// 
			// pictureBox33
			// 
			this->pictureBox33->Location = System::Drawing::Point(264, 200);
			this->pictureBox33->Name = L"pictureBox33";
			this->pictureBox33->Size = System::Drawing::Size(80, 58);
			this->pictureBox33->TabIndex = 31;
			this->pictureBox33->TabStop = false;
			// 
			// pictureBox32
			// 
			this->pictureBox32->Image = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"pictureBox32.Image")));
			this->pictureBox32->Location = System::Drawing::Point(350, 200);
			this->pictureBox32->Name = L"pictureBox32";
			this->pictureBox32->Size = System::Drawing::Size(80, 58);
			this->pictureBox32->SizeMode = System::Windows::Forms::PictureBoxSizeMode::StretchImage;
			this->pictureBox32->TabIndex = 32;
			this->pictureBox32->TabStop = false;
			// 
			// pictureBox31
			// 
			this->pictureBox31->Location = System::Drawing::Point(436, 200);
			this->pictureBox31->Name = L"pictureBox31";
			this->pictureBox31->Size = System::Drawing::Size(80, 58);
			this->pictureBox31->TabIndex = 33;
			this->pictureBox31->TabStop = false;
			// 
			// pictureBox30
			// 
			this->pictureBox30->Image = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"pictureBox30.Image")));
			this->pictureBox30->Location = System::Drawing::Point(522, 200);
			this->pictureBox30->Name = L"pictureBox30";
			this->pictureBox30->Size = System::Drawing::Size(80, 58);
			this->pictureBox30->SizeMode = System::Windows::Forms::PictureBoxSizeMode::StretchImage;
			this->pictureBox30->TabIndex = 34;
			this->pictureBox30->TabStop = false;
			// 
			// pictureBox29
			// 
			this->pictureBox29->Location = System::Drawing::Point(608, 200);
			this->pictureBox29->Name = L"pictureBox29";
			this->pictureBox29->Size = System::Drawing::Size(80, 58);
			this->pictureBox29->TabIndex = 35;
			this->pictureBox29->TabStop = false;
			// 
			// pictureBox28
			// 
			this->pictureBox28->Image = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"pictureBox28.Image")));
			this->pictureBox28->Location = System::Drawing::Point(694, 200);
			this->pictureBox28->Name = L"pictureBox28";
			this->pictureBox28->Size = System::Drawing::Size(80, 58);
			this->pictureBox28->SizeMode = System::Windows::Forms::PictureBoxSizeMode::StretchImage;
			this->pictureBox28->TabIndex = 36;
			this->pictureBox28->TabStop = false;
			// 
			// pictureBox45
			// 
			this->pictureBox45->Location = System::Drawing::Point(6, 264);
			this->pictureBox45->Name = L"pictureBox45";
			this->pictureBox45->Size = System::Drawing::Size(80, 58);
			this->pictureBox45->TabIndex = 37;
			this->pictureBox45->TabStop = false;
			// 
			// pictureBox44
			// 
			this->pictureBox44->Location = System::Drawing::Point(92, 264);
			this->pictureBox44->Name = L"pictureBox44";
			this->pictureBox44->Size = System::Drawing::Size(80, 58);
			this->pictureBox44->TabIndex = 38;
			this->pictureBox44->TabStop = false;
			// 
			// pictureBox43
			// 
			this->pictureBox43->Location = System::Drawing::Point(178, 264);
			this->pictureBox43->Name = L"pictureBox43";
			this->pictureBox43->Size = System::Drawing::Size(80, 58);
			this->pictureBox43->TabIndex = 39;
			this->pictureBox43->TabStop = false;
			// 
			// pictureBox42
			// 
			this->pictureBox42->Location = System::Drawing::Point(264, 264);
			this->pictureBox42->Name = L"pictureBox42";
			this->pictureBox42->Size = System::Drawing::Size(80, 58);
			this->pictureBox42->TabIndex = 40;
			this->pictureBox42->TabStop = false;
			// 
			// pictureBox41
			// 
			this->pictureBox41->Location = System::Drawing::Point(350, 264);
			this->pictureBox41->Name = L"pictureBox41";
			this->pictureBox41->Size = System::Drawing::Size(80, 58);
			this->pictureBox41->TabIndex = 41;
			this->pictureBox41->TabStop = false;
			// 
			// pictureBox40
			// 
			this->pictureBox40->Location = System::Drawing::Point(436, 264);
			this->pictureBox40->Name = L"pictureBox40";
			this->pictureBox40->Size = System::Drawing::Size(80, 58);
			this->pictureBox40->TabIndex = 42;
			this->pictureBox40->TabStop = false;
			// 
			// pictureBox39
			// 
			this->pictureBox39->Location = System::Drawing::Point(522, 264);
			this->pictureBox39->Name = L"pictureBox39";
			this->pictureBox39->Size = System::Drawing::Size(80, 58);
			this->pictureBox39->TabIndex = 43;
			this->pictureBox39->TabStop = false;
			// 
			// pictureBox38
			// 
			this->pictureBox38->BackgroundImageLayout = System::Windows::Forms::ImageLayout::None;
			this->pictureBox38->Cursor = System::Windows::Forms::Cursors::Default;
			this->pictureBox38->Location = System::Drawing::Point(608, 264);
			this->pictureBox38->Name = L"pictureBox38";
			this->pictureBox38->Size = System::Drawing::Size(80, 58);
			this->pictureBox38->TabIndex = 44;
			this->pictureBox38->TabStop = false;
			// 
			// pictureBox37
			// 
			this->pictureBox37->Location = System::Drawing::Point(694, 264);
			this->pictureBox37->Name = L"pictureBox37";
			this->pictureBox37->Size = System::Drawing::Size(80, 58);
			this->pictureBox37->TabIndex = 45;
			this->pictureBox37->TabStop = false;
			// 
			// pictureBox54
			// 
			this->pictureBox54->Location = System::Drawing::Point(6, 328);
			this->pictureBox54->Name = L"pictureBox54";
			this->pictureBox54->Size = System::Drawing::Size(80, 58);
			this->pictureBox54->TabIndex = 46;
			this->pictureBox54->TabStop = false;
			// 
			// pictureBox53
			// 
			this->pictureBox53->Location = System::Drawing::Point(92, 328);
			this->pictureBox53->Name = L"pictureBox53";
			this->pictureBox53->Size = System::Drawing::Size(80, 58);
			this->pictureBox53->TabIndex = 47;
			this->pictureBox53->TabStop = false;
			// 
			// pictureBox52
			// 
			this->pictureBox52->Location = System::Drawing::Point(178, 328);
			this->pictureBox52->Name = L"pictureBox52";
			this->pictureBox52->Size = System::Drawing::Size(80, 58);
			this->pictureBox52->TabIndex = 48;
			this->pictureBox52->TabStop = false;
			// 
			// pictureBox51
			// 
			this->pictureBox51->Location = System::Drawing::Point(264, 328);
			this->pictureBox51->Name = L"pictureBox51";
			this->pictureBox51->Size = System::Drawing::Size(80, 58);
			this->pictureBox51->TabIndex = 49;
			this->pictureBox51->TabStop = false;
			// 
			// pictureBox50
			// 
			this->pictureBox50->Location = System::Drawing::Point(350, 328);
			this->pictureBox50->Name = L"pictureBox50";
			this->pictureBox50->Size = System::Drawing::Size(80, 58);
			this->pictureBox50->TabIndex = 50;
			this->pictureBox50->TabStop = false;
			// 
			// pictureBox49
			// 
			this->pictureBox49->Location = System::Drawing::Point(436, 328);
			this->pictureBox49->Name = L"pictureBox49";
			this->pictureBox49->Size = System::Drawing::Size(80, 58);
			this->pictureBox49->TabIndex = 51;
			this->pictureBox49->TabStop = false;
			// 
			// pictureBox48
			// 
			this->pictureBox48->Location = System::Drawing::Point(522, 328);
			this->pictureBox48->Name = L"pictureBox48";
			this->pictureBox48->Size = System::Drawing::Size(80, 58);
			this->pictureBox48->TabIndex = 52;
			this->pictureBox48->TabStop = false;
			// 
			// pictureBox47
			// 
			this->pictureBox47->Location = System::Drawing::Point(608, 328);
			this->pictureBox47->Name = L"pictureBox47";
			this->pictureBox47->Size = System::Drawing::Size(80, 58);
			this->pictureBox47->TabIndex = 53;
			this->pictureBox47->TabStop = false;
			// 
			// pictureBox46
			// 
			this->pictureBox46->Location = System::Drawing::Point(694, 328);
			this->pictureBox46->Name = L"pictureBox46";
			this->pictureBox46->Size = System::Drawing::Size(80, 58);
			this->pictureBox46->TabIndex = 54;
			this->pictureBox46->TabStop = false;
			// 
			// pictureBox63
			// 
			this->pictureBox63->Image = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"pictureBox63.Image")));
			this->pictureBox63->Location = System::Drawing::Point(6, 392);
			this->pictureBox63->Name = L"pictureBox63";
			this->pictureBox63->Size = System::Drawing::Size(80, 58);
			this->pictureBox63->SizeMode = System::Windows::Forms::PictureBoxSizeMode::StretchImage;
			this->pictureBox63->TabIndex = 55;
			this->pictureBox63->TabStop = false;
			// 
			// pictureBox62
			// 
			this->pictureBox62->Location = System::Drawing::Point(92, 392);
			this->pictureBox62->Name = L"pictureBox62";
			this->pictureBox62->Size = System::Drawing::Size(80, 58);
			this->pictureBox62->TabIndex = 56;
			this->pictureBox62->TabStop = false;
			// 
			// pictureBox61
			// 
			this->pictureBox61->Image = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"pictureBox61.Image")));
			this->pictureBox61->Location = System::Drawing::Point(178, 392);
			this->pictureBox61->Name = L"pictureBox61";
			this->pictureBox61->Size = System::Drawing::Size(80, 58);
			this->pictureBox61->SizeMode = System::Windows::Forms::PictureBoxSizeMode::StretchImage;
			this->pictureBox61->TabIndex = 57;
			this->pictureBox61->TabStop = false;
			// 
			// pictureBox60
			// 
			this->pictureBox60->Location = System::Drawing::Point(264, 392);
			this->pictureBox60->Name = L"pictureBox60";
			this->pictureBox60->Size = System::Drawing::Size(80, 58);
			this->pictureBox60->TabIndex = 58;
			this->pictureBox60->TabStop = false;
			// 
			// pictureBox59
			// 
			this->pictureBox59->Image = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"pictureBox59.Image")));
			this->pictureBox59->Location = System::Drawing::Point(350, 392);
			this->pictureBox59->Name = L"pictureBox59";
			this->pictureBox59->Size = System::Drawing::Size(80, 58);
			this->pictureBox59->SizeMode = System::Windows::Forms::PictureBoxSizeMode::StretchImage;
			this->pictureBox59->TabIndex = 59;
			this->pictureBox59->TabStop = false;
			// 
			// pictureBox58
			// 
			this->pictureBox58->Location = System::Drawing::Point(436, 392);
			this->pictureBox58->Name = L"pictureBox58";
			this->pictureBox58->Size = System::Drawing::Size(80, 58);
			this->pictureBox58->TabIndex = 60;
			this->pictureBox58->TabStop = false;
			// 
			// pictureBox57
			// 
			this->pictureBox57->Image = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"pictureBox57.Image")));
			this->pictureBox57->Location = System::Drawing::Point(522, 392);
			this->pictureBox57->Name = L"pictureBox57";
			this->pictureBox57->Size = System::Drawing::Size(80, 58);
			this->pictureBox57->SizeMode = System::Windows::Forms::PictureBoxSizeMode::StretchImage;
			this->pictureBox57->TabIndex = 61;
			this->pictureBox57->TabStop = false;
			// 
			// pictureBox56
			// 
			this->pictureBox56->Location = System::Drawing::Point(608, 392);
			this->pictureBox56->Name = L"pictureBox56";
			this->pictureBox56->Size = System::Drawing::Size(80, 58);
			this->pictureBox56->TabIndex = 62;
			this->pictureBox56->TabStop = false;
			// 
			// pictureBox55
			// 
			this->pictureBox55->Image = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"pictureBox55.Image")));
			this->pictureBox55->Location = System::Drawing::Point(694, 392);
			this->pictureBox55->Name = L"pictureBox55";
			this->pictureBox55->Size = System::Drawing::Size(80, 58);
			this->pictureBox55->SizeMode = System::Windows::Forms::PictureBoxSizeMode::StretchImage;
			this->pictureBox55->TabIndex = 63;
			this->pictureBox55->TabStop = false;
			// 
			// pictureBox72
			// 
			this->pictureBox72->Location = System::Drawing::Point(6, 456);
			this->pictureBox72->Name = L"pictureBox72";
			this->pictureBox72->Size = System::Drawing::Size(80, 58);
			this->pictureBox72->TabIndex = 64;
			this->pictureBox72->TabStop = false;
			// 
			// pictureBox71
			// 
			this->pictureBox71->Image = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"pictureBox71.Image")));
			this->pictureBox71->Location = System::Drawing::Point(92, 456);
			this->pictureBox71->Name = L"pictureBox71";
			this->pictureBox71->Size = System::Drawing::Size(80, 58);
			this->pictureBox71->SizeMode = System::Windows::Forms::PictureBoxSizeMode::StretchImage;
			this->pictureBox71->TabIndex = 65;
			this->pictureBox71->TabStop = false;
			// 
			// pictureBox70
			// 
			this->pictureBox70->Location = System::Drawing::Point(178, 456);
			this->pictureBox70->Name = L"pictureBox70";
			this->pictureBox70->Size = System::Drawing::Size(80, 58);
			this->pictureBox70->TabIndex = 66;
			this->pictureBox70->TabStop = false;
			// 
			// pictureBox69
			// 
			this->pictureBox69->Location = System::Drawing::Point(264, 456);
			this->pictureBox69->Name = L"pictureBox69";
			this->pictureBox69->Size = System::Drawing::Size(80, 58);
			this->pictureBox69->TabIndex = 67;
			this->pictureBox69->TabStop = false;
			// 
			// pictureBox68
			// 
			this->pictureBox68->Location = System::Drawing::Point(350, 456);
			this->pictureBox68->Name = L"pictureBox68";
			this->pictureBox68->Size = System::Drawing::Size(80, 58);
			this->pictureBox68->TabIndex = 68;
			this->pictureBox68->TabStop = false;
			// 
			// pictureBox67
			// 
			this->pictureBox67->Location = System::Drawing::Point(436, 456);
			this->pictureBox67->Name = L"pictureBox67";
			this->pictureBox67->Size = System::Drawing::Size(80, 58);
			this->pictureBox67->TabIndex = 69;
			this->pictureBox67->TabStop = false;
			// 
			// pictureBox66
			// 
			this->pictureBox66->Location = System::Drawing::Point(522, 456);
			this->pictureBox66->Name = L"pictureBox66";
			this->pictureBox66->Size = System::Drawing::Size(80, 58);
			this->pictureBox66->TabIndex = 70;
			this->pictureBox66->TabStop = false;
			// 
			// pictureBox65
			// 
			this->pictureBox65->Image = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"pictureBox65.Image")));
			this->pictureBox65->Location = System::Drawing::Point(608, 456);
			this->pictureBox65->Name = L"pictureBox65";
			this->pictureBox65->Size = System::Drawing::Size(80, 58);
			this->pictureBox65->SizeMode = System::Windows::Forms::PictureBoxSizeMode::StretchImage;
			this->pictureBox65->TabIndex = 71;
			this->pictureBox65->TabStop = false;
			// 
			// pictureBox64
			// 
			this->pictureBox64->Location = System::Drawing::Point(694, 456);
			this->pictureBox64->Name = L"pictureBox64";
			this->pictureBox64->Size = System::Drawing::Size(80, 58);
			this->pictureBox64->TabIndex = 72;
			this->pictureBox64->TabStop = false;
			// 
			// pictureBox81
			// 
			this->pictureBox81->Location = System::Drawing::Point(6, 520);
			this->pictureBox81->Name = L"pictureBox81";
			this->pictureBox81->Size = System::Drawing::Size(80, 58);
			this->pictureBox81->TabIndex = 73;
			this->pictureBox81->TabStop = false;
			// 
			// pictureBox80
			// 
			this->pictureBox80->Location = System::Drawing::Point(92, 520);
			this->pictureBox80->Name = L"pictureBox80";
			this->pictureBox80->Size = System::Drawing::Size(80, 58);
			this->pictureBox80->TabIndex = 74;
			this->pictureBox80->TabStop = false;
			// 
			// pictureBox79
			// 
			this->pictureBox79->Location = System::Drawing::Point(178, 520);
			this->pictureBox79->Name = L"pictureBox79";
			this->pictureBox79->Size = System::Drawing::Size(80, 58);
			this->pictureBox79->TabIndex = 75;
			this->pictureBox79->TabStop = false;
			// 
			// pictureBox78
			// 
			this->pictureBox78->Location = System::Drawing::Point(264, 520);
			this->pictureBox78->Name = L"pictureBox78";
			this->pictureBox78->Size = System::Drawing::Size(80, 58);
			this->pictureBox78->TabIndex = 76;
			this->pictureBox78->TabStop = false;
			// 
			// pictureBox77
			// 
			this->pictureBox77->Location = System::Drawing::Point(350, 520);
			this->pictureBox77->Name = L"pictureBox77";
			this->pictureBox77->Size = System::Drawing::Size(80, 58);
			this->pictureBox77->TabIndex = 77;
			this->pictureBox77->TabStop = false;
			// 
			// pictureBox76
			// 
			this->pictureBox76->Location = System::Drawing::Point(436, 520);
			this->pictureBox76->Name = L"pictureBox76";
			this->pictureBox76->Size = System::Drawing::Size(80, 58);
			this->pictureBox76->TabIndex = 78;
			this->pictureBox76->TabStop = false;
			// 
			// pictureBox75
			// 
			this->pictureBox75->Location = System::Drawing::Point(522, 520);
			this->pictureBox75->Name = L"pictureBox75";
			this->pictureBox75->Size = System::Drawing::Size(80, 58);
			this->pictureBox75->TabIndex = 79;
			this->pictureBox75->TabStop = false;
			// 
			// pictureBox74
			// 
			this->pictureBox74->Location = System::Drawing::Point(608, 520);
			this->pictureBox74->Name = L"pictureBox74";
			this->pictureBox74->Size = System::Drawing::Size(80, 58);
			this->pictureBox74->TabIndex = 80;
			this->pictureBox74->TabStop = false;
			// 
			// pictureBox73
			// 
			this->pictureBox73->Location = System::Drawing::Point(694, 520);
			this->pictureBox73->Name = L"pictureBox73";
			this->pictureBox73->Size = System::Drawing::Size(80, 58);
			this->pictureBox73->TabIndex = 81;
			this->pictureBox73->TabStop = false;
			// 
			// panel1
			// 
			this->panel1->BackColor = System::Drawing::Color::Transparent;
			this->panel1->BackgroundImage = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"panel1.BackgroundImage")));
			this->panel1->BackgroundImageLayout = System::Windows::Forms::ImageLayout::Stretch;
			this->panel1->Controls->Add(this->pictureBox83);
			this->panel1->Controls->Add(this->pictureBox84);
			this->panel1->Controls->Add(this->pictureBox85);
			this->panel1->Controls->Add(this->pictureBox86);
			this->panel1->Controls->Add(this->pictureBox87);
			this->panel1->Controls->Add(this->pictureBox88);
			this->panel1->Controls->Add(this->pictureBox89);
			this->panel1->Controls->Add(this->pictureBox90);
			this->panel1->Controls->Add(this->pictureBox82);
			this->panel1->Controls->Add(this->pictureBox73);
			this->panel1->Controls->Add(this->pictureBox74);
			this->panel1->Controls->Add(this->pictureBox75);
			this->panel1->Controls->Add(this->pictureBox76);
			this->panel1->Controls->Add(this->pictureBox77);
			this->panel1->Controls->Add(this->pictureBox78);
			this->panel1->Controls->Add(this->pictureBox79);
			this->panel1->Controls->Add(this->pictureBox80);
			this->panel1->Controls->Add(this->pictureBox81);
			this->panel1->Controls->Add(this->pictureBox64);
			this->panel1->Controls->Add(this->pictureBox65);
			this->panel1->Controls->Add(this->pictureBox66);
			this->panel1->Controls->Add(this->pictureBox67);
			this->panel1->Controls->Add(this->pictureBox68);
			this->panel1->Controls->Add(this->pictureBox69);
			this->panel1->Controls->Add(this->pictureBox70);
			this->panel1->Controls->Add(this->pictureBox71);
			this->panel1->Controls->Add(this->pictureBox72);
			this->panel1->Controls->Add(this->pictureBox55);
			this->panel1->Controls->Add(this->pictureBox56);
			this->panel1->Controls->Add(this->pictureBox57);
			this->panel1->Controls->Add(this->pictureBox58);
			this->panel1->Controls->Add(this->pictureBox59);
			this->panel1->Controls->Add(this->pictureBox60);
			this->panel1->Controls->Add(this->pictureBox61);
			this->panel1->Controls->Add(this->pictureBox62);
			this->panel1->Controls->Add(this->pictureBox63);
			this->panel1->Controls->Add(this->pictureBox46);
			this->panel1->Controls->Add(this->pictureBox47);
			this->panel1->Controls->Add(this->pictureBox48);
			this->panel1->Controls->Add(this->pictureBox49);
			this->panel1->Controls->Add(this->pictureBox50);
			this->panel1->Controls->Add(this->pictureBox51);
			this->panel1->Controls->Add(this->pictureBox52);
			this->panel1->Controls->Add(this->pictureBox53);
			this->panel1->Controls->Add(this->pictureBox54);
			this->panel1->Controls->Add(this->pictureBox37);
			this->panel1->Controls->Add(this->pictureBox38);
			this->panel1->Controls->Add(this->pictureBox39);
			this->panel1->Controls->Add(this->pictureBox40);
			this->panel1->Controls->Add(this->pictureBox41);
			this->panel1->Controls->Add(this->pictureBox42);
			this->panel1->Controls->Add(this->pictureBox43);
			this->panel1->Controls->Add(this->pictureBox44);
			this->panel1->Controls->Add(this->pictureBox45);
			this->panel1->Controls->Add(this->pictureBox28);
			this->panel1->Controls->Add(this->pictureBox29);
			this->panel1->Controls->Add(this->pictureBox30);
			this->panel1->Controls->Add(this->pictureBox31);
			this->panel1->Controls->Add(this->pictureBox32);
			this->panel1->Controls->Add(this->pictureBox33);
			this->panel1->Controls->Add(this->pictureBox34);
			this->panel1->Controls->Add(this->pictureBox35);
			this->panel1->Controls->Add(this->pictureBox36);
			this->panel1->Controls->Add(this->pictureBox19);
			this->panel1->Controls->Add(this->pictureBox20);
			this->panel1->Controls->Add(this->pictureBox21);
			this->panel1->Controls->Add(this->pictureBox22);
			this->panel1->Controls->Add(this->pictureBox23);
			this->panel1->Controls->Add(this->pictureBox24);
			this->panel1->Controls->Add(this->pictureBox25);
			this->panel1->Controls->Add(this->pictureBox26);
			this->panel1->Controls->Add(this->pictureBox27);
			this->panel1->Controls->Add(this->pictureBox10);
			this->panel1->Controls->Add(this->pictureBox11);
			this->panel1->Controls->Add(this->pictureBox12);
			this->panel1->Controls->Add(this->pictureBox13);
			this->panel1->Controls->Add(this->pictureBox14);
			this->panel1->Controls->Add(this->pictureBox15);
			this->panel1->Controls->Add(this->pictureBox16);
			this->panel1->Controls->Add(this->pictureBox17);
			this->panel1->Controls->Add(this->pictureBox18);
			this->panel1->Controls->Add(this->pictureBox9);
			this->panel1->Controls->Add(this->pictureBox8);
			this->panel1->Controls->Add(this->pictureBox7);
			this->panel1->Controls->Add(this->pictureBox6);
			this->panel1->Controls->Add(this->pictureBox5);
			this->panel1->Controls->Add(this->pictureBox4);
			this->panel1->Controls->Add(this->pictureBox3);
			this->panel1->Controls->Add(this->pictureBox2);
			this->panel1->Controls->Add(this->pictureBox1);
			this->panel1->Location = System::Drawing::Point(6, 4);
			this->panel1->Name = L"panel1";
			this->panel1->Size = System::Drawing::Size(782, 654);
			this->panel1->TabIndex = 91;
			// 
			// pictureBox83
			// 
			this->pictureBox83->Image = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"pictureBox83.Image")));
			this->pictureBox83->Location = System::Drawing::Point(608, 584);
			this->pictureBox83->Name = L"pictureBox83";
			this->pictureBox83->Size = System::Drawing::Size(80, 58);
			this->pictureBox83->SizeMode = System::Windows::Forms::PictureBoxSizeMode::StretchImage;
			this->pictureBox83->TabIndex = 107;
			this->pictureBox83->TabStop = false;
			// 
			// pictureBox84
			// 
			this->pictureBox84->Image = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"pictureBox84.Image")));
			this->pictureBox84->Location = System::Drawing::Point(522, 584);
			this->pictureBox84->Name = L"pictureBox84";
			this->pictureBox84->Size = System::Drawing::Size(80, 58);
			this->pictureBox84->SizeMode = System::Windows::Forms::PictureBoxSizeMode::StretchImage;
			this->pictureBox84->TabIndex = 106;
			this->pictureBox84->TabStop = false;
			// 
			// pictureBox85
			// 
			this->pictureBox85->Image = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"pictureBox85.Image")));
			this->pictureBox85->Location = System::Drawing::Point(436, 584);
			this->pictureBox85->Name = L"pictureBox85";
			this->pictureBox85->Size = System::Drawing::Size(80, 58);
			this->pictureBox85->SizeMode = System::Windows::Forms::PictureBoxSizeMode::StretchImage;
			this->pictureBox85->TabIndex = 105;
			this->pictureBox85->TabStop = false;
			// 
			// pictureBox86
			// 
			this->pictureBox86->Image = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"pictureBox86.Image")));
			this->pictureBox86->Location = System::Drawing::Point(350, 584);
			this->pictureBox86->Name = L"pictureBox86";
			this->pictureBox86->Size = System::Drawing::Size(80, 58);
			this->pictureBox86->SizeMode = System::Windows::Forms::PictureBoxSizeMode::StretchImage;
			this->pictureBox86->TabIndex = 104;
			this->pictureBox86->TabStop = false;
			// 
			// pictureBox87
			// 
			this->pictureBox87->Image = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"pictureBox87.Image")));
			this->pictureBox87->Location = System::Drawing::Point(264, 584);
			this->pictureBox87->Name = L"pictureBox87";
			this->pictureBox87->Size = System::Drawing::Size(80, 58);
			this->pictureBox87->SizeMode = System::Windows::Forms::PictureBoxSizeMode::StretchImage;
			this->pictureBox87->TabIndex = 103;
			this->pictureBox87->TabStop = false;
			// 
			// pictureBox88
			// 
			this->pictureBox88->Image = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"pictureBox88.Image")));
			this->pictureBox88->Location = System::Drawing::Point(178, 584);
			this->pictureBox88->Name = L"pictureBox88";
			this->pictureBox88->Size = System::Drawing::Size(80, 58);
			this->pictureBox88->SizeMode = System::Windows::Forms::PictureBoxSizeMode::StretchImage;
			this->pictureBox88->TabIndex = 102;
			this->pictureBox88->TabStop = false;
			// 
			// pictureBox89
			// 
			this->pictureBox89->Image = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"pictureBox89.Image")));
			this->pictureBox89->Location = System::Drawing::Point(92, 584);
			this->pictureBox89->Name = L"pictureBox89";
			this->pictureBox89->Size = System::Drawing::Size(80, 58);
			this->pictureBox89->SizeMode = System::Windows::Forms::PictureBoxSizeMode::StretchImage;
			this->pictureBox89->TabIndex = 101;
			this->pictureBox89->TabStop = false;
			// 
			// pictureBox90
			// 
			this->pictureBox90->BackColor = System::Drawing::Color::Transparent;
			this->pictureBox90->Image = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"pictureBox90.Image")));
			this->pictureBox90->Location = System::Drawing::Point(6, 584);
			this->pictureBox90->Name = L"pictureBox90";
			this->pictureBox90->Size = System::Drawing::Size(80, 58);
			this->pictureBox90->SizeMode = System::Windows::Forms::PictureBoxSizeMode::StretchImage;
			this->pictureBox90->TabIndex = 100;
			this->pictureBox90->TabStop = false;
			// 
			// pictureBox82
			// 
			this->pictureBox82->Image = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"pictureBox82.Image")));
			this->pictureBox82->Location = System::Drawing::Point(694, 584);
			this->pictureBox82->Name = L"pictureBox82";
			this->pictureBox82->Size = System::Drawing::Size(80, 58);
			this->pictureBox82->SizeMode = System::Windows::Forms::PictureBoxSizeMode::StretchImage;
			this->pictureBox82->TabIndex = 99;
			this->pictureBox82->TabStop = false;
			// 
			// panel2
			// 
			this->panel2->BackColor = System::Drawing::Color::DodgerBlue;
			this->panel2->Controls->Add(this->button5);
			this->panel2->Controls->Add(this->button4);
			this->panel2->Controls->Add(this->label5);
			this->panel2->Controls->Add(this->button3);
			this->panel2->Controls->Add(this->button2);
			this->panel2->Controls->Add(this->button1);
			this->panel2->Controls->Add(this->label4);
			this->panel2->Controls->Add(this->label3);
			this->panel2->Controls->Add(this->label2);
			this->panel2->Controls->Add(this->label1);
			this->panel2->Location = System::Drawing::Point(794, 21);
			this->panel2->Name = L"panel2";
			this->panel2->Size = System::Drawing::Size(197, 390);
			this->panel2->TabIndex = 92;
			// 
			// button5
			// 
			this->button5->BackColor = System::Drawing::Color::LightSkyBlue;
			this->button5->FlatAppearance->BorderSize = 0;
			this->button5->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
			this->button5->Font = (gcnew System::Drawing::Font(L"Viner Hand ITC", 14.25F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->button5->Location = System::Drawing::Point(0, 323);
			this->button5->Name = L"button5";
			this->button5->Size = System::Drawing::Size(197, 36);
			this->button5->TabIndex = 9;
			this->button5->Text = L"连接服务器";
			this->button5->UseVisualStyleBackColor = false;
			this->button5->Click += gcnew System::EventHandler(this, &MainForm::button5_Click);
			// 
			// button4
			// 
			this->button4->BackColor = System::Drawing::Color::LightSkyBlue;
			this->button4->FlatAppearance->BorderSize = 0;
			this->button4->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
			this->button4->Font = (gcnew System::Drawing::Font(L"Viner Hand ITC", 14.25F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->button4->Location = System::Drawing::Point(0, 291);
			this->button4->Name = L"button4";
			this->button4->Size = System::Drawing::Size(197, 36);
			this->button4->TabIndex = 8;
			this->button4->Text = L"创建服务器";
			this->button4->UseVisualStyleBackColor = false;
			this->button4->Click += gcnew System::EventHandler(this, &MainForm::button4_Click);
			// 
			// label5
			// 
			this->label5->AutoSize = true;
			this->label5->Font = (gcnew System::Drawing::Font(L"Adobe Fan Heiti Std B", 15.75F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->label5->ForeColor = System::Drawing::Color::Red;
			this->label5->Location = System::Drawing::Point(-1, 162);
			this->label5->Name = L"label5";
			this->label5->Size = System::Drawing::Size(0, 26);
			this->label5->TabIndex = 7;
			// 
			// button3
			// 
			this->button3->BackColor = System::Drawing::Color::LightSkyBlue;
			this->button3->Enabled = false;
			this->button3->FlatAppearance->BorderSize = 0;
			this->button3->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
			this->button3->Font = (gcnew System::Drawing::Font(L"Viner Hand ITC", 14.25F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->button3->Location = System::Drawing::Point(0, 259);
			this->button3->Name = L"button3";
			this->button3->Size = System::Drawing::Size(197, 35);
			this->button3->TabIndex = 6;
			this->button3->Text = L"悔棋";
			this->button3->UseVisualStyleBackColor = false;
			this->button3->Click += gcnew System::EventHandler(this, &MainForm::button3_Click);
			// 
			// button2
			// 
			this->button2->BackColor = System::Drawing::Color::LightSkyBlue;
			this->button2->Enabled = false;
			this->button2->FlatAppearance->BorderSize = 0;
			this->button2->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
			this->button2->Font = (gcnew System::Drawing::Font(L"Viner Hand ITC", 14.25F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->button2->Location = System::Drawing::Point(0, 225);
			this->button2->Name = L"button2";
			this->button2->Size = System::Drawing::Size(197, 34);
			this->button2->TabIndex = 5;
			this->button2->Text = L"结束";
			this->button2->UseVisualStyleBackColor = false;
			this->button2->Click += gcnew System::EventHandler(this, &MainForm::button2_Click);
			// 
			// button1
			// 
			this->button1->BackColor = System::Drawing::Color::LightSkyBlue;
			this->button1->FlatAppearance->BorderSize = 0;
			this->button1->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
			this->button1->Font = (gcnew System::Drawing::Font(L"Viner Hand ITC", 14.25F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->button1->Location = System::Drawing::Point(0, 194);
			this->button1->Name = L"button1";
			this->button1->Size = System::Drawing::Size(197, 36);
			this->button1->TabIndex = 4;
			this->button1->Text = L"单机开始";
			this->button1->UseVisualStyleBackColor = false;
			this->button1->Click += gcnew System::EventHandler(this, &MainForm::button1_Click);
			// 
			// label4
			// 
			this->label4->AutoSize = true;
			this->label4->Font = (gcnew System::Drawing::Font(L"Adobe Fan Heiti Std B", 12, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(128)));
			this->label4->Location = System::Drawing::Point(3, 27);
			this->label4->Name = L"label4";
			this->label4->Size = System::Drawing::Size(79, 20);
			this->label4->TabIndex = 3;
			this->label4->Text = L"当前时间:";
			// 
			// label3
			// 
			this->label3->AutoSize = true;
			this->label3->Font = (gcnew System::Drawing::Font(L"Adobe Gothic Std B", 24, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(128)));
			this->label3->Location = System::Drawing::Point(45, 55);
			this->label3->Name = L"label3";
			this->label3->Size = System::Drawing::Size(143, 40);
			this->label3->TabIndex = 2;
			this->label3->Text = L"00:00:00";
			// 
			// label2
			// 
			this->label2->AutoSize = true;
			this->label2->Font = (gcnew System::Drawing::Font(L"Adobe Fan Heiti Std B", 15.75F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->label2->Location = System::Drawing::Point(0, 130);
			this->label2->Name = L"label2";
			this->label2->Size = System::Drawing::Size(80, 26);
			this->label2->TabIndex = 1;
			this->label2->Text = L"行动方:";
			// 
			// label1
			// 
			this->label1->AutoSize = true;
			this->label1->Font = (gcnew System::Drawing::Font(L"Adobe Fan Heiti Std B", 15.75F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->label1->Location = System::Drawing::Point(0, 98);
			this->label1->Name = L"label1";
			this->label1->Size = System::Drawing::Size(59, 26);
			this->label1->TabIndex = 0;
			this->label1->Text = L"回合:";
			// 
			// panel3
			// 
			this->panel3->BackColor = System::Drawing::Color::Tomato;
			this->panel3->Controls->Add(this->textBox1);
			this->panel3->Controls->Add(this->richTextBox1);
			this->panel3->Controls->Add(this->label6);
			this->panel3->Location = System::Drawing::Point(794, 417);
			this->panel3->Name = L"panel3";
			this->panel3->Size = System::Drawing::Size(214, 219);
			this->panel3->TabIndex = 93;
			this->panel3->Paint += gcnew System::Windows::Forms::PaintEventHandler(this, &MainForm::panel3_Paint);
			// 
			// textBox1
			// 
			this->textBox1->Location = System::Drawing::Point(0, 196);
			this->textBox1->Name = L"textBox1";
			this->textBox1->Size = System::Drawing::Size(188, 20);
			this->textBox1->TabIndex = 2;
			this->textBox1->TextChanged += gcnew System::EventHandler(this, &MainForm::textBox1_TextChanged);
			this->textBox1->KeyDown += gcnew System::Windows::Forms::KeyEventHandler(this, &MainForm::textBox1_KeyDown);
			// 
			// richTextBox1
			// 
			this->richTextBox1->BackColor = System::Drawing::Color::Tomato;
			this->richTextBox1->BorderStyle = System::Windows::Forms::BorderStyle::None;
			this->richTextBox1->Font = (gcnew System::Drawing::Font(L"Microsoft YaHei", 9.75F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(134)));
			this->richTextBox1->ForeColor = System::Drawing::Color::MidnightBlue;
			this->richTextBox1->Location = System::Drawing::Point(3, 30);
			this->richTextBox1->Name = L"richTextBox1";
			this->richTextBox1->ScrollBars = System::Windows::Forms::RichTextBoxScrollBars::Vertical;
			this->richTextBox1->Size = System::Drawing::Size(185, 174);
			this->richTextBox1->TabIndex = 1;
			this->richTextBox1->Text = L"";
			// 
			// label6
			// 
			this->label6->AutoSize = true;
			this->label6->Font = (gcnew System::Drawing::Font(L"Microsoft YaHei", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(134)));
			this->label6->Location = System::Drawing::Point(3, 6);
			this->label6->Name = L"label6";
			this->label6->Size = System::Drawing::Size(74, 21);
			this->label6->TabIndex = 0;
			this->label6->Text = L"聊天界面";
			// 
			// MainForm
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->BackColor = System::Drawing::Color::Bisque;
			this->ClientSize = System::Drawing::Size(990, 670);
			this->Controls->Add(this->panel3);
			this->Controls->Add(this->panel2);
			this->Controls->Add(this->panel1);
			this->Name = L"MainForm";
			this->Opacity = 0;
			this->Text = L"Chess Main";
			this->FormClosing += gcnew System::Windows::Forms::FormClosingEventHandler(this, &MainForm::MainForm_FormClosing);
			this->Load += gcnew System::EventHandler(this, &MainForm::MainForm_Load);
			this->SizeChanged += gcnew System::EventHandler(this, &MainForm::MainForm_SizeChanged);
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox1))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox2))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox3))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox4))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox5))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox6))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox7))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox8))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox9))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox18))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox17))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox16))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox15))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox14))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox13))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox12))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox11))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox10))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox27))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox26))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox25))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox24))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox23))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox22))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox21))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox20))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox19))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox36))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox35))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox34))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox33))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox32))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox31))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox30))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox29))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox28))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox45))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox44))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox43))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox42))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox41))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox40))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox39))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox38))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox37))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox54))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox53))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox52))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox51))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox50))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox49))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox48))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox47))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox46))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox63))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox62))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox61))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox60))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox59))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox58))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox57))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox56))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox55))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox72))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox71))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox70))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox69))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox68))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox67))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox66))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox65))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox64))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox81))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox80))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox79))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox78))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox77))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox76))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox75))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox74))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox73))->EndInit();
			this->panel1->ResumeLayout(false);
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox83))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox84))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox85))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox86))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox87))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox88))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox89))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox90))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox82))->EndInit();
			this->panel2->ResumeLayout(false);
			this->panel2->PerformLayout();
			this->panel3->ResumeLayout(false);
			this->panel3->PerformLayout();
			this->ResumeLayout(false);

		}
#pragma endregion
	private: System::Void MainForm_Load(System::Object^  sender, System::EventArgs^  e) {

				Task^ t = Task::Factory->StartNew(gcnew Action(this, &MainForm::setop));


		System::ComponentModel::ComponentResourceManager^  resources = (gcnew System::ComponentModel::ComponentResourceManager(MainForm::typeid));
		trapic=(cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"tra")));
		kiban::getInstance()->setcanclicklist();
		//setcursor();
		try {
			MainForm::Text = "Chess Main-" + socketServer::getIP();
		}catch(Exception^ e){}


		//设置服务器socket收到数据的委托函数
		socketServer::MessageRec = gcnew MsgIn(this,&MainForm::server_msgin);
		socketClient::Message_Receive = gcnew ReceiveMsg(this,&MainForm::client_msgin);
		socketClient::leave = gcnew nulldelegate(this,&MainForm::socketleave);
		socketServer::clientleavefun=gcnew clientleave(this, &MainForm::socketleave);
	}
			 void socketleave() {
				 end();
			 }
			 void setcursorcannot() {
				 for (int i = 0; i < 10; i++) {
					 for (int j = 0; j < 9; j++) {
						 ((PictureBox^)ps->GetValue(i, j))->Cursor = Cursors::Default;
					 }
				 }
			 }
			 void begingame_netmode() {
				 begin = true;
				 times = 0;
				 netmode = true;
				 kiban::getInstance()->setcanclicklist(Red);
				 if(net_color==Red){ setcursor(); }
				 button2->Enabled = true;
				 button3->Enabled = true;
				 button1->Enabled = false;
				 button4->Enabled = false;
				 button5->Enabled = false;
				 frighting = true;
				 currfright = gcnew fright();
				 Task::Factory->StartNew(gcnew Action(this, &MainForm::timeingfunc));



			 }
			 //服务器收到数据
			 void server_msgin(String^ str, Socket^ soc) {
				 //MessageBox::Show(str);
				 //协议设计:   ;号分隔，第一位类型(int);后面具体信息
				 int type;
				 array<String^, 1>^ datastrs=str->Split(';');
				 if (datastrs->Length== 0) return;
				 if(!Int32::TryParse(datastrs[0],type)) return;
				 switch (type)
				 {
				 case Clientjoin: {  //客户端连接,此时给客户端返回棋子颜色分配信息,并开始游戏
					 sendtosocket("1;"+((int)(net_color==Red?Black:Red)).ToString(), soc);
					 if (targetsocket == nullptr) targetsocket = soc;

					 begingame_netmode(); //开始游戏
				 }
								  break;
				 case targetClick: {
					 int r, c;
					 r = Int32::Parse(datastrs[1]);
					 c= Int32::Parse(datastrs[2]);
					 clickprocess(r, c);
				 }
							break;
				 case SocketleaveState: {
					 end();
				 }
					break;
				 case restep: {
					 button3_Click(nullptr, nullptr);
				 }
							  break;
				 case sendmessage: {
					 String^ str = "";
					 for (int j = 1; j < datastrs->Length; j++) {
						 str += datastrs->GetValue(j);
					 }
					 log("From:" + ((net_color==Red)?"Black":"Red")+"\n" + str);
				 }
								   break;
				 default:
					 break;
				 }
			 }
			 static void sendtosocket(String^ str, Socket^ soc) {
				 try
				 {
					 array<unsigned char, 1>^ td = Encoding::UTF8->GetBytes(str);
					 soc->Send(td);
				 }
				 catch (Exception^ e)
				 {

				 }
			 }
			 //客户端收到信息
			 void client_msgin(String^ str) {
				 //MessageBox::Show(str);
				 int type;
				 array<String^, 1>^ datastrs = str->Split(';');
				 if (datastrs->Length == 0) return;
				 if (!Int32::TryParse(datastrs[0], type)) return;
				 switch (type)
				 {
				    case colordistribution://颜色分配
				    {
						net_color = (ChessCorlor)Int32::Parse(datastrs[1]);
						begingame_netmode();
				    }
				     break;
					case targetClick: {
						int r, c;
						r = Int32::Parse(datastrs[1]);
						c = Int32::Parse(datastrs[2]);
						clickprocess(r, c);
					}
					 break;
					case SocketleaveState: {
						end();
					}
		            break;
					case restep: {
						button3_Click(nullptr, nullptr);
					}
								 break;
					case sendmessage: {
						String^ str = "";
						for (int j = 1; j < datastrs->Length; j++) {
							str += datastrs->GetValue(j);
						}
						log("From:" + ((net_color == Red) ? "Black" : "Red") +"\n"+ str);
					}
									  break;
				 default:
					 break;
				 }
			 }
			 void setop() {
				 for (int i = 0; i <= 20; i++) {
					 Opacity = 0.05*i;
					 Left += 2;
					 Top += 2;
					 System::Threading::Thread::Sleep(20);
					 
				 }
			}
			 private:void setpicboxes() {
                       #pragma region putpicboxes
				 ps->SetValue(pictureBox1, 0, 0);
				 ps->SetValue(pictureBox2, 0, 1);
				 ps->SetValue(pictureBox3, 0, 2);
				 ps->SetValue(pictureBox4, 0, 3);
				 ps->SetValue(pictureBox5, 0, 4);
				 ps->SetValue(pictureBox6, 0, 5);
				 ps->SetValue(pictureBox7, 0, 6);
				 ps->SetValue(pictureBox8, 0, 7);
				 ps->SetValue(pictureBox9, 0, 8);

				 ps->SetValue(pictureBox18, 1, 0);
				 ps->SetValue(pictureBox17, 1, 1);
				 ps->SetValue(pictureBox16, 1, 2);
				 ps->SetValue(pictureBox15, 1, 3);
				 ps->SetValue(pictureBox14, 1, 4);
				 ps->SetValue(pictureBox13, 1, 5);
				 ps->SetValue(pictureBox12, 1, 6);
				 ps->SetValue(pictureBox11, 1, 7);
				 ps->SetValue(pictureBox10, 1, 8);

				 ps->SetValue(pictureBox27, 2, 0);
				 ps->SetValue(pictureBox26, 2, 1);
				 ps->SetValue(pictureBox25, 2, 2);
				 ps->SetValue(pictureBox24, 2, 3);
				 ps->SetValue(pictureBox23, 2, 4);
				 ps->SetValue(pictureBox22, 2, 5);
				 ps->SetValue(pictureBox21, 2, 6);
				 ps->SetValue(pictureBox20, 2, 7);
				 ps->SetValue(pictureBox19, 2, 8);

				 ps->SetValue(pictureBox36, 3, 0);
				 ps->SetValue(pictureBox35, 3, 1);
				 ps->SetValue(pictureBox34, 3, 2);
				 ps->SetValue(pictureBox33, 3, 3);
				 ps->SetValue(pictureBox32, 3, 4);
				 ps->SetValue(pictureBox31, 3, 5);
				 ps->SetValue(pictureBox30, 3, 6);
				 ps->SetValue(pictureBox29, 3, 7);
				 ps->SetValue(pictureBox28, 3, 8);

				 ps->SetValue(pictureBox45, 4, 0);
				 ps->SetValue(pictureBox44, 4, 1);
				 ps->SetValue(pictureBox43, 4, 2);
				 ps->SetValue(pictureBox42, 4, 3);
				 ps->SetValue(pictureBox41, 4, 4);
				 ps->SetValue(pictureBox40, 4, 5);
				 ps->SetValue(pictureBox39, 4, 6);
				 ps->SetValue(pictureBox38, 4, 7);
				 ps->SetValue(pictureBox37, 4, 8);

				 ps->SetValue(pictureBox54, 5, 0);
				 ps->SetValue(pictureBox53, 5, 1);
				 ps->SetValue(pictureBox52, 5, 2);
				 ps->SetValue(pictureBox51, 5, 3);
				 ps->SetValue(pictureBox50, 5, 4);
				 ps->SetValue(pictureBox49, 5, 5);
				 ps->SetValue(pictureBox48, 5, 6);
				 ps->SetValue(pictureBox47, 5, 7);
				 ps->SetValue(pictureBox46, 5, 8);

				 ps->SetValue(pictureBox63, 6, 0);
				 ps->SetValue(pictureBox62, 6, 1);
				 ps->SetValue(pictureBox61, 6, 2);
				 ps->SetValue(pictureBox60, 6, 3);
				 ps->SetValue(pictureBox59, 6, 4);
				 ps->SetValue(pictureBox58, 6, 5);
				 ps->SetValue(pictureBox57, 6, 6);
				 ps->SetValue(pictureBox56, 6, 7);
				 ps->SetValue(pictureBox55, 6, 8);

				 ps->SetValue(pictureBox72, 7, 0);
				 ps->SetValue(pictureBox71, 7, 1);
				 ps->SetValue(pictureBox70, 7, 2);
				 ps->SetValue(pictureBox69, 7, 3);
				 ps->SetValue(pictureBox68, 7, 4);
				 ps->SetValue(pictureBox67, 7, 5);
				 ps->SetValue(pictureBox66, 7, 6);
				 ps->SetValue(pictureBox65, 7, 7);
				 ps->SetValue(pictureBox64, 7, 8);

				 ps->SetValue(pictureBox81, 8, 0);
				 ps->SetValue(pictureBox80, 8, 1);
				 ps->SetValue(pictureBox79, 8, 2);
				 ps->SetValue(pictureBox78, 8, 3);
				 ps->SetValue(pictureBox77, 8, 4);
				 ps->SetValue(pictureBox76, 8, 5);
				 ps->SetValue(pictureBox75, 8, 6);
				 ps->SetValue(pictureBox74, 8, 7);
				 ps->SetValue(pictureBox73, 8, 8);

				 ps->SetValue(pictureBox90, 9, 0);
				 ps->SetValue(pictureBox89, 9, 1);
				 ps->SetValue(pictureBox88, 9, 2);
				 ps->SetValue(pictureBox87, 9, 3);
				 ps->SetValue(pictureBox86, 9, 4);
				 ps->SetValue(pictureBox85, 9, 5);
				 ps->SetValue(pictureBox84, 9, 6);
				 ps->SetValue(pictureBox83, 9, 7);
				 ps->SetValue(pictureBox82, 9, 8);
				 for (int i = 0; i < 10; i++) {
					 for (int j = 0; j < 9; j++) {
						 //((PictureBox^)ps->GetValue(i, j))->BackColor = Drawing::Color::FromArgb(i * 10, j * 10, 70);
						 ((PictureBox^)ps->GetValue(i, j))->Tag = i.ToString() + ","+j.ToString();
						 ((PictureBox^)ps->GetValue(i, j))->Parent = panel1;
						 ((PictureBox^)ps->GetValue(i,j))->Click += gcnew System::EventHandler(this, &MainForm::Chess_click);
						 ((PictureBox^)ps->GetValue(i, j))->SizeMode = PictureBoxSizeMode::StretchImage;
					 }
				 }
#pragma endregion
			 }
		void log(String^ str){
			DateTime^ dt = DateTime::Now;
			richTextBox1->Text += dt->ToString("hh:mm:ss")+":->"+str+"\n";
		}
	private:void refreshcomplements() {
		panel1->Top = 0;
		panel1->Left = 0;
		panel1->Width = Width*0.731;
		panel1->Height = Height*0.95;
		int avgw = (panel1->Width / 9);

		int avgh = panel1->Height / 10;
		for (int i = 0; i < 10; i++) {
			for (int j = 0; j < 9; j++) {
				//((PictureBox^)ps->GetValue(i, j))->BackColor = Drawing::Color::FromArgb(i * 10, j * 10, 70);
				((PictureBox^)ps->GetValue(i, j))->Width = avgw;
				((PictureBox^)ps->GetValue(i, j))->Height = avgh;
				((PictureBox^)ps->GetValue(i, j))->Left = avgw*j;
				((PictureBox^)ps->GetValue(i, j))->Top = i*avgh;
			}
		}
		panel2->Left = panel1->Width;
		panel2->Top = 0;
		panel2->Width = Width- panel1->Width;
		panel2->Height = panel1->Height/2;
		button1->Width = panel2->Width;
		button2->Width = panel2->Width;
		button3->Width = panel2->Width;
		button4->Width = panel2->Width;
		button5->Width = panel2->Width;
		panel3->Top= panel1->Height / 2;
		panel3->Width = panel2->Width;
		panel3->Left = panel2->Left;
		panel3->Height = panel2->Height;
		//button1->Top = panel2->Height*0.4;
		richTextBox1->Top = label6->Top + label6->Height;
		richTextBox1->Left = 0;
		richTextBox1->Width = panel3->Width;
		richTextBox1->Height=panel3->Height- label6->Top -label6->Height;
		//输入框
		textBox1->Left = richTextBox1->Left+1;
		textBox1->Width = richTextBox1->Width-5;
		textBox1->Top = richTextBox1->Top + richTextBox1->Height - textBox1->Height-2;
		
	}
	private: System::Void MainForm_SizeChanged(System::Object^  sender, System::EventArgs^  e) {
		
		refreshcomplements();
		kiban* k = kiban::getInstance();
		k->getInstance();
	}
    public:
		
		Image^ trapic;
		static void IntoNetmode() {
			
			
			
			//gcnew Action(this, &MainForm::chessmanblink));
		}
		
		
		
		void setcursor() {
			
				
				for (int i = 0; i < 10; i++) {
					for (int j = 0; j < 9; j++) {
						if (kiban::getInstance()->canbeclick[i][j]) {
							((PictureBox^)ps->GetValue(i, j))->Cursor = Cursors::Hand;
						}
						else {
							((PictureBox^)ps->GetValue(i, j))->Cursor = Cursors::Default;
						}
					}
				}
		
			



		}
		
		void clickprocess(int x1, int y1) {
			if (!(kiban::getInstance()->canbeclick[x1][y1])) {  //坐标不在选择列表内
				return;
			}

			if (!hasChessmanBeSelected) {  //还没有被选中的旗子时，只有可行动方可选择棋子
										   //记录选中棋子坐标
				c_x = x1;
				c_y = y1;
				currselectchessima = ((PictureBox^)ps->GetValue(x1,y1))->Image;  //记录选中棋子图片
				hasChessmanBeSelected = 1;
				kiban::getInstance()->setcanclicklist(x1, y1);
				//设置光标

				setcursor();
				blinktask = Task::Factory->StartNew(gcnew Action(this, &MainForm::chessmanblink));
			}
			else {
				//已选择一个棋子，有3种情况 
				//0:空位
				if (kiban::getInstance()->isEmptyposition(x1, y1)) {
					if (!hasChessmanBeSelected) return;
					//选择空位: (移动过去即可)
					hasChessmanBeSelected = false;
					//恢复图片
					while (taskrunning)
					{

					}
					currfright->addstep(c_x, c_y, x1, y1, kiban::getInstance()->getcolor(c_x, c_y), currselectchessima, nullptr);
					((PictureBox^)ps->GetValue(x1, y1))->Image = ((PictureBox^)ps->GetValue(c_x, c_y))->Image;
					((PictureBox^)ps->GetValue(c_x, c_y))->Image = trapic;
					//更改相关信息
					int truimph = kiban::getInstance()->move(c_x, c_y, x1, y1);
					if (truimph == 2) {
						label5->Text = "Red be threadened";
					}
					else if (truimph == 3) {
						label5->Text = "Black be threadened";
					}
					else {
						label5->Text = "";
					}
					if (truimph == 1) {
						MessageBox::Show("End");
						//重置
						end();
						return;
					}
					times++;
					kiban::getInstance()->setcanclicklist((ChessCorlor)(times % 2));
					if (net_netmode) {
						if(times%2==net_color){
							setcursor();
						}
						else {
							setcursorcannot();
						}
						
					}
					else {
						setcursor();
					}
					//setcursor();
					//times++;

					return;
				}

				ChessCorlor selectedcolor = kiban::getInstance()->getcolor(c_x, c_y);
				ChessCorlor taigetcolor = kiban::getInstance()->getcolor(x1, y1);
				//1.选择相同颜色
				if (selectedcolor == taigetcolor) {
					hasChessmanBeSelected = false;
					//线程同步
					while (taskrunning)
					{


					}
					((PictureBox^)ps->GetValue(c_x, c_y))->Image = currselectchessima;
					//选择新的
					if (c_x == x1 && c_y == y1) return;
					c_x = x1;
					c_y = y1;
					currselectchessima = ((PictureBox^)ps->GetValue(x1, y1))->Image;  //记录选中棋子图片
					hasChessmanBeSelected = 1;
					kiban::getInstance()->setcanclicklist(x1, y1);
					setcursor();
					blinktask = Task::Factory->StartNew(gcnew Action(this, &MainForm::chessmanblink));
					return;
				}

				//2.吃子
				hasChessmanBeSelected = false;
				//恢复图片
				while (taskrunning)
				{

				}
				currfright->addstep(c_x, c_y, x1, y1, kiban::getInstance()->getcolor(c_x, c_y), currselectchessima, ((PictureBox^)ps->GetValue(x1, y1))->Image);
				((PictureBox^)ps->GetValue(x1, y1))->Image = ((PictureBox^)ps->GetValue(c_x, c_y))->Image;
				((PictureBox^)ps->GetValue(c_x, c_y))->Image = trapic;
				//更改相关信息
				int truimph = kiban::getInstance()->move(c_x, c_y, x1, y1);
				if (truimph == 2) {
					label5->Text = "Red be threadened";
				}
				else if (truimph == 3) {
					label5->Text = "Black be threadened";
				}
				else {
					label5->Text = "";
				}

				if (truimph == 1) {
					MessageBox::Show("End");
					//重置
					end();
					return;
				}
				times++;
				kiban::getInstance()->setcanclicklist((ChessCorlor)(times % 2));
				if (times % 2 == net_color) {
					setcursor();
				}
				else {
					setcursorcannot();
				}
			}
		}
		private:System::Void Chess_click(System::Object^  sender, System::EventArgs^  e) {
			//单击有3种情况要处理:一是未选择棋子时选中一个棋子  二是已选择一个棋子时再选择同一个棋子 3是吃旗
			if (begin && net_netmode) {
				if (times % 2 != (net_color)) return;
			}

			int x1=Convert::ToInt32(((((PictureBox^)sender)->Tag)->ToString()->Split(','))->GetValue(0));
			int y1 = Convert::ToInt32(((((PictureBox^)sender)->Tag)->ToString()->Split(','))->GetValue(1));
			clickprocess(x1, y1);
			sendtosocket("2;" + x1.ToString() + ";" + y1.ToString(), targetsocket);
		}
				void tobenobeginstate() {
					kiban::getInstance()->setcanclicklist();
				}
				void resetpicboxpic() {
					System::ComponentModel::ComponentResourceManager^  resources = (gcnew System::ComponentModel::ComponentResourceManager(MainForm::typeid));
					for (int i = 0; i < 10; i++) {
						for (int j = 0; j < 9; j++) {
							((PictureBox^)ps->GetValue(i,j))->Image = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"tra")));
						}
					}
					pictureBox1->Image = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"pictureBox1.Image")));
					pictureBox2->Image = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"pictureBox2.Image")));
					pictureBox20->Image = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"pictureBox20.Image")));
					pictureBox26->Image = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"pictureBox26.Image")));
					pictureBox28->Image = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"pictureBox28.Image")));
					pictureBox3->Image = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"pictureBox3.Image")));
					pictureBox30->Image = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"pictureBox30.Image")));
					pictureBox32->Image = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"pictureBox32.Image")));
					pictureBox34->Image = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"pictureBox34.Image")));
					pictureBox36->Image = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"pictureBox36.Image")));
					pictureBox4->Image = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"pictureBox4.Image")));
					pictureBox5->Image = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"pictureBox5.Image")));
					pictureBox55->Image = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"pictureBox55.Image")));
					pictureBox57->Image = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"pictureBox57.Image")));
					pictureBox59->Image = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"pictureBox59.Image")));
					pictureBox6->Image = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"pictureBox6.Image")));
					pictureBox61->Image = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"pictureBox61.Image")));
					pictureBox63->Image = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"pictureBox63.Image")));
					pictureBox65->Image = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"pictureBox65.Image")));
					pictureBox7->Image = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"pictureBox7.Image")));
					pictureBox71->Image = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"pictureBox71.Image")));
					pictureBox8->Image = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"pictureBox8.Image")));
					pictureBox82->Image = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"pictureBox82.Image")));
					pictureBox83->Image = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"pictureBox83.Image")));
					pictureBox84->Image = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"pictureBox84.Image")));
					pictureBox85->Image = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"pictureBox85.Image")));
					pictureBox86->Image = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"pictureBox86.Image")));
					pictureBox87->Image = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"pictureBox87.Image")));
					pictureBox88->Image = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"pictureBox88.Image")));
					pictureBox89->Image = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"pictureBox89.Image")));
					pictureBox9->Image = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"pictureBox9.Image")));
					pictureBox90->Image = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"pictureBox90.Image")));
				}
				void chessmanblink() {
					taskrunning = true;
					System::ComponentModel::ComponentResourceManager^  resources = (gcnew System::ComponentModel::ComponentResourceManager(MainForm::typeid));
					while (hasChessmanBeSelected) {
						((PictureBox^)ps->GetValue(c_x, c_y))->Image = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"tra")));
						System::Threading::Thread::Sleep(500);
						((PictureBox^)ps->GetValue(c_x, c_y))->Image = currselectchessima;
						if (!hasChessmanBeSelected) break;
						System::Threading::Thread::Sleep(500);
						
					}
					((PictureBox^)ps->GetValue(c_x, c_y))->Image = currselectchessima;
					taskrunning = false;
		        }
			
				void end() {
					hasChessmanBeSelected = false;
					//线程同步
					while (taskrunning)
					{


					}
					if (net_netmode) {
						try {
							sendtosocket("4", targetsocket);
							ss->close();
						}catch(Exception^ e){}
					}
					kiban::getInstance()->resetkiban();
					resetpicboxpic();
					times = 0; hasChessmanBeSelected = false;
					tobenobeginstate();
					setcursor();
					button1->Enabled = true;
					button2->Enabled = false;
					button3->Enabled = false;
					button4->Enabled = true;
					button5->Enabled = true;
					frighting = false;
					label2->Text = "回合:";
					label1->Text = "行动方:";
					label3->Text = "00:00:00";
					label5->Text = "";
					net_netmode = false;
					targetsocket = nullptr;
				}
private: System::Void button1_Click(System::Object^  sender, System::EventArgs^  e) {
	times = 0;
	netmode = false;
	kiban::getInstance()->setcanclicklist(Red);
	setcursor();
	button2->Enabled = true;
	button3->Enabled = true;
	button1->Enabled = false;
	button4->Enabled = false;
	button5->Enabled = false;
	frighting = true;
	currfright = gcnew fright();
	Task::Factory->StartNew(gcnew Action(this, &MainForm::timeingfunc));
	log("单击启动");
}
		 void timeingfunc() {
			 while (frighting) {
				 DateTime^ d2 = DateTime::Now;
				 DateTime^ d3 = currfright->dt;
				 TimeSpan^ ts1 = gcnew TimeSpan(d2->Ticks);
				 TimeSpan^ ts2 = gcnew TimeSpan(d3->Ticks);

				 TimeSpan r = ts1->Subtract(*ts2);


				 label3->Text = r.Hours.ToString("00") + ":" + r.Minutes.ToString("00") + ":"+r.Seconds.ToString("00");
				 label2->Text = "回合:"+times.ToString();
				 label1->Text = "行动方:" + ((times%2==0)?"红":"黑");
			 }
		 }
private: System::Void MainForm_FormClosing(System::Object^  sender, System::Windows::Forms::FormClosingEventArgs^  e) {
	frighting = false;
}
private: System::Void button2_Click(System::Object^  sender, System::EventArgs^  e) {
	end();
	if (net_netmode) {
		sendtosocket(((int)SocketleaveState).ToString(), targetsocket);
	}
	resetpicboxpic();
}
		 void resetpchess() {
			 step^ s = currfright->steps[currfright->steps->Count - 1];
			 //恢复图片
			 ((PictureBox^)ps->GetValue(s->startr1, s->startc1))->Image = s->sima;
			 ((PictureBox^)ps->GetValue(s->endr2, s->endc2))->Image = s->eima;
			 int truimph = kiban::getInstance()->move(s->endr2, s->endc2, s->startr1, s->startc1);
			 if (truimph == 2) {
				 label5->Text = "Red be threadened";
			 }
			 else if (truimph == 3) {
				 label5->Text = "Black be threadened";
			 }
			 else {
				 label5->Text = "";
			 }
			 times--;
			 kiban::getInstance()->setcanclicklist(s->co);
			 currfright->steps->RemoveAt(currfright->steps->Count - 1);
			 setcursor();
		 }
private: System::Void button3_Click(System::Object^  sender, System::EventArgs^  e) {
	if (currfright->steps->Count == 0) return;
	if (net_netmode) {
		if (times % 2 != net_color) {  //在对方行动时自己可以悔棋
			sendtosocket(((int)restep).ToString(), targetsocket);
			resetpchess();
		}
		else {
			return;
		}
		
	}
	else {
		resetpchess();
	}
	
	
}
private: System::Void button4_Click(System::Object^  sender, System::EventArgs^  e) {
	ServerCreate::finish = false;
	Task^ t = Task::Factory->StartNew(gcnew Action(this, &MainForm::loadServerCreate));
	while (!ServerCreate::finish) {

	}
	if (ServerCreate::restr == "") {
		return;
	}
	net_color = (ChessCorlor)Convert::ToInt32(ServerCreate::cc);
	this->Text = "ChessMain-" + ServerCreate::restr;
	createserver((ChessCorlor)ServerCreate::cc, ServerCreate::restr);

}
		 void loadServerCreate() {
			 ServerCreate^ sct = gcnew ServerCreate();
			 sct->ShowDialog();
		 }
private: System::Void button5_Click(System::Object^  sender, System::EventArgs^  e) {
	if (net_netmode) return;
	ipinput::finish = false;
	ipinput^ ipw = gcnew ipinput();
	ipw->ShowDialog();
	while (!ipinput::finish) {

	}
	if (ipinput::port == 0 || ipinput::ip == "") { MessageBox::Show("信息输入错误"); return; }
	clientconnect();
}
		 void clientconnect() {
			 sc = gcnew socketClient(IPAddress::Parse(ipinput::ip),9239);
			 if (sc->Connect()) {
				 //连接成功
				 log("Connected to the server");
				 net_netmode = true;
				 button4->Enabled = false;
				 button5->Enabled = false;
				 button1->Enabled = false;
				 button2->Enabled = true;
				 targetsocket = sc->clientSocket;
				 sendtosocket("1", targetsocket); //给服务器发送客户端连接信息
			}
		 }
private: System::Void panel3_Paint(System::Object^  sender, System::Windows::Forms::PaintEventArgs^  e) {
}
private: System::Void textBox1_KeyDown(System::Object^  sender, System::Windows::Forms::KeyEventArgs^  e) {
	if (net_netmode && e->KeyValue == 13 && targetsocket!=nullptr) {
		sendtosocket("6;"+textBox1->Text, targetsocket);
	}
	
}
private: System::Void textBox1_TextChanged(System::Object^  sender, System::EventArgs^  e) {
}
};


}


