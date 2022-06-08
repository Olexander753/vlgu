#pragma once
#include "Menu_Director_Form.h"
#include "Menu_Employee_Form.h"
#include "Menu_Visitor_Form.h"
#include "Register_Form.h"
#include "Join.h"

namespace Zoo {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;

	/// <summary>
	/// Сводка для Log_In_Form
	/// </summary>
	public ref class Log_In_Form : public System::Windows::Forms::Form
	{
	public:
		Log_In_Form(void)
		{
			InitializeComponent();
			//
			//TODO: добавьте код конструктора
			//
		}

	protected:
		/// <summary>
		/// Освободить все используемые ресурсы.
		/// </summary>
		~Log_In_Form()
		{
			if (components)
			{
				delete components;
			}
		}
	private: System::Windows::Forms::Button^ button_log_in;
	private: System::Windows::Forms::LinkLabel^ linkLabel_sing_up;

	protected:

	protected:

	protected:

	private: System::Windows::Forms::Label^ label1;
	private: System::Windows::Forms::Label^ label2;
	private: System::Windows::Forms::TextBox^ textBox_login;
	private: System::Windows::Forms::TextBox^ textBox_password;

	protected:

	private:
		/// <summary>
		/// Обязательная переменная конструктора.
		/// </summary>
		System::ComponentModel::Container ^components;

#pragma region Windows Form Designer generated code
		/// <summary>
		/// Требуемый метод для поддержки конструктора — не изменяйте 
		/// содержимое этого метода с помощью редактора кода.
		/// </summary>
		void InitializeComponent(void)
		{
			this->button_log_in = (gcnew System::Windows::Forms::Button());
			this->linkLabel_sing_up = (gcnew System::Windows::Forms::LinkLabel());
			this->label1 = (gcnew System::Windows::Forms::Label());
			this->label2 = (gcnew System::Windows::Forms::Label());
			this->textBox_login = (gcnew System::Windows::Forms::TextBox());
			this->textBox_password = (gcnew System::Windows::Forms::TextBox());
			this->SuspendLayout();
			// 
			// button_log_in
			// 
			this->button_log_in->Location = System::Drawing::Point(100, 175);
			this->button_log_in->Name = L"button_log_in";
			this->button_log_in->Size = System::Drawing::Size(100, 25);
			this->button_log_in->TabIndex = 0;
			this->button_log_in->Text = L"Войти";
			this->button_log_in->UseVisualStyleBackColor = true;
			this->button_log_in->Click += gcnew System::EventHandler(this, &Log_In_Form::button_log_in_Click);
			// 
			// linkLabel_sing_up
			// 
			this->linkLabel_sing_up->AutoSize = true;
			this->linkLabel_sing_up->Location = System::Drawing::Point(53, 226);
			this->linkLabel_sing_up->Name = L"linkLabel_sing_up";
			this->linkLabel_sing_up->Size = System::Drawing::Size(195, 26);
			this->linkLabel_sing_up->TabIndex = 1;
			this->linkLabel_sing_up->TabStop = true;
			this->linkLabel_sing_up->Text = L"Зарегистрироваться как посетитель\r\n\r\n";
			this->linkLabel_sing_up->LinkClicked += gcnew System::Windows::Forms::LinkLabelLinkClickedEventHandler(this, &Log_In_Form::linkLabel_sing_up_LinkClicked);
			// 
			// label1
			// 
			this->label1->AutoSize = true;
			this->label1->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 14.25F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->label1->Location = System::Drawing::Point(118, 38);
			this->label1->Name = L"label1";
			this->label1->Size = System::Drawing::Size(64, 24);
			this->label1->TabIndex = 2;
			this->label1->Text = L"Логин";
			// 
			// label2
			// 
			this->label2->AutoSize = true;
			this->label2->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 14.25F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->label2->Location = System::Drawing::Point(112, 104);
			this->label2->Name = L"label2";
			this->label2->Size = System::Drawing::Size(76, 24);
			this->label2->TabIndex = 3;
			this->label2->Text = L"Пароль";
			// 
			// textBox_login
			// 
			this->textBox_login->Location = System::Drawing::Point(15, 63);
			this->textBox_login->Name = L"textBox_login";
			this->textBox_login->Size = System::Drawing::Size(255, 20);
			this->textBox_login->TabIndex = 4;
			// 
			// textBox_password
			// 
			this->textBox_password->Location = System::Drawing::Point(15, 129);
			this->textBox_password->Name = L"textBox_password";
			this->textBox_password->Size = System::Drawing::Size(255, 20);
			this->textBox_password->TabIndex = 5;
			// 
			// Log_In_Form
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(284, 261);
			this->Controls->Add(this->textBox_password);
			this->Controls->Add(this->textBox_login);
			this->Controls->Add(this->label2);
			this->Controls->Add(this->label1);
			this->Controls->Add(this->linkLabel_sing_up);
			this->Controls->Add(this->button_log_in);
			this->Name = L"Log_In_Form";
			this->Text = L"Log_In_Form";
			this->FormClosed += gcnew System::Windows::Forms::FormClosedEventHandler(this, &Log_In_Form::Log_In_Form_FormClosed);
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion
private: System::Void button_log_in_Click(System::Object^ sender, System::EventArgs^ e);
private: System::Void linkLabel_sing_up_LinkClicked(System::Object^ sender, System::Windows::Forms::LinkLabelLinkClickedEventArgs^ e);
private: System::Void Log_In_Form_FormClosed(System::Object^ sender, System::Windows::Forms::FormClosedEventArgs^ e);
};
}
