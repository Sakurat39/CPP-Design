#pragma once
#include "socket.h"

namespace ChesscppCLR {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;
	using namespace socketspace;
	using namespace ChesscppCLR;
	/// <summary>
	/// Summary for ServerCreate
	/// </summary>
	public ref class ServerCreate : public System::Windows::Forms::Form
	{
	public:
		static bool finish = false;
		static String^ restr;
		static int cc;
		ServerCreate(void)
		{
			InitializeComponent();
			//
			//TODO: Add the constructor code here
			//
		}

	protected:
		/// <summary>
		/// Clean up any resources being used.
		/// </summary>
		~ServerCreate()
		{
			if (components)
			{
				delete components;
			}
		}
	private: System::Windows::Forms::Button^  button1;
	private: System::Windows::Forms::Button^  button2;
	private: System::Windows::Forms::Label^  label1;
	private: System::Windows::Forms::ComboBox^  comboBox1;

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
			this->button1 = (gcnew System::Windows::Forms::Button());
			this->button2 = (gcnew System::Windows::Forms::Button());
			this->label1 = (gcnew System::Windows::Forms::Label());
			this->comboBox1 = (gcnew System::Windows::Forms::ComboBox());
			this->SuspendLayout();
			// 
			// button1
			// 
			this->button1->BackColor = System::Drawing::Color::Red;
			this->button1->FlatAppearance->BorderSize = 0;
			this->button1->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
			this->button1->ForeColor = System::Drawing::SystemColors::Desktop;
			this->button1->Location = System::Drawing::Point(-1, -1);
			this->button1->Name = L"button1";
			this->button1->Size = System::Drawing::Size(285, 91);
			this->button1->TabIndex = 0;
			this->button1->Text = L"Red";
			this->button1->UseVisualStyleBackColor = false;
			this->button1->Click += gcnew System::EventHandler(this, &ServerCreate::button1_Click);
			// 
			// button2
			// 
			this->button2->BackColor = System::Drawing::SystemColors::ActiveCaptionText;
			this->button2->FlatAppearance->BorderSize = 0;
			this->button2->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
			this->button2->ForeColor = System::Drawing::SystemColors::MenuHighlight;
			this->button2->Location = System::Drawing::Point(0, 85);
			this->button2->Name = L"button2";
			this->button2->Size = System::Drawing::Size(285, 91);
			this->button2->TabIndex = 1;
			this->button2->Text = L"Black";
			this->button2->UseVisualStyleBackColor = false;
			this->button2->Click += gcnew System::EventHandler(this, &ServerCreate::button2_Click);
			// 
			// label1
			// 
			this->label1->AutoSize = true;
			this->label1->Location = System::Drawing::Point(12, 179);
			this->label1->Name = L"label1";
			this->label1->Size = System::Drawing::Size(20, 13);
			this->label1->TabIndex = 2;
			this->label1->Text = L"IP:";
			// 
			// comboBox1
			// 
			this->comboBox1->FormattingEnabled = true;
			this->comboBox1->Location = System::Drawing::Point(9, 195);
			this->comboBox1->Name = L"comboBox1";
			this->comboBox1->Size = System::Drawing::Size(263, 21);
			this->comboBox1->TabIndex = 3;
			// 
			// ServerCreate
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(284, 230);
			this->Controls->Add(this->comboBox1);
			this->Controls->Add(this->label1);
			this->Controls->Add(this->button2);
			this->Controls->Add(this->button1);
			this->Name = L"ServerCreate";
			this->Text = L"ServerCreate";
			this->TopMost = true;
			this->FormClosed += gcnew System::Windows::Forms::FormClosedEventHandler(this, &ServerCreate::ServerCreate_FormClosed);
			this->Load += gcnew System::EventHandler(this, &ServerCreate::ServerCreate_Load);
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion
	private: System::Void ServerCreate_Load(System::Object^  sender, System::EventArgs^  e) {
		try {
			array<IPAddress^,1>^ ips= socketServer::getIP();
			//textBox1->Text = 
			for (int i = 0; i < (ips->Length); i++) {
				comboBox1->Items->Add(ips[i]->ToString());
			}
			comboBox1->SelectedIndex = 0;
		}catch(Exception^ e){}
	}
private: System::Void button1_Click(System::Object^  sender, System::EventArgs^  e) {
	
	cc = 0;
	restr =comboBox1->Text ;
	finish = true;
	//MainForm::createserver(0, restr);
	this->Close();
}
private: System::Void button2_Click(System::Object^  sender, System::EventArgs^  e) {
	//MainForm::CreateServer(1, comboBox1->Text);
	cc = 1;
	restr = comboBox1->Text;
	finish = true;
	//MainForm::createserver(1, restr);
	this->Close();
}
private: System::Void ServerCreate_FormClosed(System::Object^  sender, System::Windows::Forms::FormClosedEventArgs^  e) {
	finish = true;
	restr = "";
}
};
}

