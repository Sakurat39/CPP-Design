#pragma once

namespace ChesscppCLR {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;

	/// <summary>
	/// Summary for ipinput
	/// </summary>
	public ref class ipinput : public System::Windows::Forms::Form
	{
	public:
		static bool finish = false;
		static String^ ip;
		static int port;
		ipinput(void)
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
		~ipinput()
		{
			if (components)
			{
				delete components;
			}
		}
	private: System::Windows::Forms::Label^  label1;
	protected:
	private: System::Windows::Forms::TextBox^  textBox1;
	private: System::Windows::Forms::TextBox^  textBox2;
	private: System::Windows::Forms::Label^  label2;
	private: System::Windows::Forms::Button^  button1;

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
			this->label1 = (gcnew System::Windows::Forms::Label());
			this->textBox1 = (gcnew System::Windows::Forms::TextBox());
			this->textBox2 = (gcnew System::Windows::Forms::TextBox());
			this->label2 = (gcnew System::Windows::Forms::Label());
			this->button1 = (gcnew System::Windows::Forms::Button());
			this->SuspendLayout();
			// 
			// label1
			// 
			this->label1->AutoSize = true;
			this->label1->Location = System::Drawing::Point(12, 9);
			this->label1->Name = L"label1";
			this->label1->Size = System::Drawing::Size(17, 13);
			this->label1->TabIndex = 0;
			this->label1->Text = L"IP";
			// 
			// textBox1
			// 
			this->textBox1->Location = System::Drawing::Point(35, 6);
			this->textBox1->Name = L"textBox1";
			this->textBox1->Size = System::Drawing::Size(378, 20);
			this->textBox1->TabIndex = 1;
			// 
			// textBox2
			// 
			this->textBox2->Location = System::Drawing::Point(83, 44);
			this->textBox2->Name = L"textBox2";
			this->textBox2->Size = System::Drawing::Size(94, 20);
			this->textBox2->TabIndex = 3;
			// 
			// label2
			// 
			this->label2->AutoSize = true;
			this->label2->Location = System::Drawing::Point(51, 47);
			this->label2->Name = L"label2";
			this->label2->Size = System::Drawing::Size(26, 13);
			this->label2->TabIndex = 2;
			this->label2->Text = L"Port";
			// 
			// button1
			// 
			this->button1->Location = System::Drawing::Point(236, 32);
			this->button1->Name = L"button1";
			this->button1->Size = System::Drawing::Size(177, 43);
			this->button1->TabIndex = 4;
			this->button1->Text = L"È·¶¨";
			this->button1->UseVisualStyleBackColor = true;
			this->button1->Click += gcnew System::EventHandler(this, &ipinput::button1_Click);
			// 
			// ipinput
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(443, 91);
			this->Controls->Add(this->button1);
			this->Controls->Add(this->textBox2);
			this->Controls->Add(this->label2);
			this->Controls->Add(this->textBox1);
			this->Controls->Add(this->label1);
			this->Name = L"ipinput";
			this->Text = L"ipinput";
			this->FormClosed += gcnew System::Windows::Forms::FormClosedEventHandler(this, &ipinput::ipinput_FormClosed);
			this->Load += gcnew System::EventHandler(this, &ipinput::ipinput_Load);
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion
	private: System::Void ipinput_Load(System::Object^  sender, System::EventArgs^  e) {
		ip = "";
		port = 0;
	}
private: System::Void button1_Click(System::Object^  sender, System::EventArgs^  e) {
	ip = textBox1->Text;
	Int32::TryParse(textBox2->Text,port);
	finish = true;
	this->Close();
}
private: System::Void ipinput_FormClosed(System::Object^  sender, System::Windows::Forms::FormClosedEventArgs^  e) {

	finish = true;
}
};
}
