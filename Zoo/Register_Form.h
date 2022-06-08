#pragma once
#include <iostream>
#include "Connection.h"
#include "Visitor.h"
#include "User.h"

namespace Zoo {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;

	/// <summary>
	/// Сводка для Register_Form
	/// </summary>
	public ref class Register_Form : public System::Windows::Forms::Form
	{
	public:
		Register_Form(void)
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
		~Register_Form()
		{
			if (components)
			{
				delete components;
			}
		}
	private: System::Windows::Forms::TextBox^ textBox_phone_number;
	protected:

	protected:

	protected:

	protected:

	private: System::Windows::Forms::Label^ label1;
	private: System::Windows::Forms::Label^ label2;
	private: System::Windows::Forms::Label^ label3;
	private: System::Windows::Forms::TextBox^ textBox_full_name;
	private: System::Windows::Forms::TextBox^ textBox_password;



	private: System::Windows::Forms::Button^ button_register;

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
			this->textBox_phone_number = (gcnew System::Windows::Forms::TextBox());
			this->label1 = (gcnew System::Windows::Forms::Label());
			this->label2 = (gcnew System::Windows::Forms::Label());
			this->label3 = (gcnew System::Windows::Forms::Label());
			this->textBox_full_name = (gcnew System::Windows::Forms::TextBox());
			this->textBox_password = (gcnew System::Windows::Forms::TextBox());
			this->button_register = (gcnew System::Windows::Forms::Button());
			this->SuspendLayout();
			// 
			// textBox_phone_number
			// 
			this->textBox_phone_number->Location = System::Drawing::Point(15, 40);
			this->textBox_phone_number->Name = L"textBox_phone_number";
			this->textBox_phone_number->Size = System::Drawing::Size(255, 20);
			this->textBox_phone_number->TabIndex = 0;
			// 
			// label1
			// 
			this->label1->AutoSize = true;
			this->label1->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 14.25F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->label1->Location = System::Drawing::Point(15, 15);
			this->label1->Name = L"label1";
			this->label1->Size = System::Drawing::Size(151, 24);
			this->label1->TabIndex = 1;
			this->label1->Text = L"Номер телфона";
			// 
			// label2
			// 
			this->label2->AutoSize = true;
			this->label2->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 14.25F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->label2->Location = System::Drawing::Point(15, 75);
			this->label2->Name = L"label2";
			this->label2->Size = System::Drawing::Size(54, 24);
			this->label2->TabIndex = 2;
			this->label2->Text = L"ФИО";
			// 
			// label3
			// 
			this->label3->AutoSize = true;
			this->label3->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 14.25F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->label3->Location = System::Drawing::Point(15, 135);
			this->label3->Name = L"label3";
			this->label3->Size = System::Drawing::Size(76, 24);
			this->label3->TabIndex = 3;
			this->label3->Text = L"Пароль";
			// 
			// textBox_full_name
			// 
			this->textBox_full_name->Location = System::Drawing::Point(15, 100);
			this->textBox_full_name->Name = L"textBox_full_name";
			this->textBox_full_name->Size = System::Drawing::Size(255, 20);
			this->textBox_full_name->TabIndex = 4;
			// 
			// textBox_password
			// 
			this->textBox_password->Location = System::Drawing::Point(15, 160);
			this->textBox_password->Name = L"textBox_password";
			this->textBox_password->Size = System::Drawing::Size(255, 20);
			this->textBox_password->TabIndex = 5;
			// 
			// button_register
			// 
			this->button_register->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 14.25F, System::Drawing::FontStyle::Regular,
				System::Drawing::GraphicsUnit::Point, static_cast<System::Byte>(204)));
			this->button_register->Location = System::Drawing::Point(15, 206);
			this->button_register->Name = L"button_register";
			this->button_register->Size = System::Drawing::Size(255, 33);
			this->button_register->TabIndex = 6;
			this->button_register->Text = L"Зарегистрироваться";
			this->button_register->UseVisualStyleBackColor = true;
			this->button_register->Click += gcnew System::EventHandler(this, &Register_Form::button_register_Click);
			// 
			// Register_Form
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(284, 261);
			this->Controls->Add(this->button_register);
			this->Controls->Add(this->textBox_password);
			this->Controls->Add(this->textBox_full_name);
			this->Controls->Add(this->label3);
			this->Controls->Add(this->label2);
			this->Controls->Add(this->label1);
			this->Controls->Add(this->textBox_phone_number);
			this->Name = L"Register_Form";
			this->Text = L"Регистрация";
			this->FormClosed += gcnew System::Windows::Forms::FormClosedEventHandler(this, &Register_Form::Register_Form_FormClosed);
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion
private: System::Void Register_Form_FormClosed(System::Object^ sender, System::Windows::Forms::FormClosedEventArgs^ e);
private: System::Void button_register_Click(System::Object^ sender, System::EventArgs^ e);
};
}
