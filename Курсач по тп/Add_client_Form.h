#pragma once
#include "Connection.h"
#include "Client.h"

namespace Курсачпотп {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;

	/// <summary>
	/// Сводка для Add_client_Form
	/// </summary>
	public ref class Add_client_Form : public System::Windows::Forms::Form
	{
	public:
		Add_client_Form(void)
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
		~Add_client_Form()
		{
			if (components)
			{
				delete components;
			}
		}
	private: System::Windows::Forms::Label^ label1;
	protected:
	private: System::Windows::Forms::Label^ label2;
	private: System::Windows::Forms::Label^ label3;
	private: System::Windows::Forms::TextBox^ textBox_Full_name;

	public: System::Windows::Forms::TextBox^ textBox_DLN;
	private: System::Windows::Forms::TextBox^ textBox_Phone_number;
	private: System::Windows::Forms::TextBox^ textBox_Password;
	private: System::Windows::Forms::TextBox^ textBox_Login;
	private: System::Windows::Forms::Label^ label4;
	private: System::Windows::Forms::Label^ label5;
	private: System::Windows::Forms::Button^ button_Enter;
	private: System::Windows::Forms::Button^ button_Back;
	private: System::Windows::Forms::Button^ button_Exit;



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
			this->label1 = (gcnew System::Windows::Forms::Label());
			this->label2 = (gcnew System::Windows::Forms::Label());
			this->label3 = (gcnew System::Windows::Forms::Label());
			this->textBox_Full_name = (gcnew System::Windows::Forms::TextBox());
			this->textBox_DLN = (gcnew System::Windows::Forms::TextBox());
			this->textBox_Phone_number = (gcnew System::Windows::Forms::TextBox());
			this->textBox_Password = (gcnew System::Windows::Forms::TextBox());
			this->textBox_Login = (gcnew System::Windows::Forms::TextBox());
			this->label4 = (gcnew System::Windows::Forms::Label());
			this->label5 = (gcnew System::Windows::Forms::Label());
			this->button_Enter = (gcnew System::Windows::Forms::Button());
			this->button_Back = (gcnew System::Windows::Forms::Button());
			this->button_Exit = (gcnew System::Windows::Forms::Button());
			this->SuspendLayout();
			// 
			// label1
			// 
			this->label1->AutoSize = true;
			this->label1->Location = System::Drawing::Point(15, 15);
			this->label1->Name = L"label1";
			this->label1->Size = System::Drawing::Size(34, 13);
			this->label1->TabIndex = 1;
			this->label1->Text = L"ФИО";
			// 
			// label2
			// 
			this->label2->AutoSize = true;
			this->label2->Location = System::Drawing::Point(15, 60);
			this->label2->Name = L"label2";
			this->label2->Size = System::Drawing::Size(68, 13);
			this->label2->TabIndex = 2;
			this->label2->Text = L"Номер прав";
			// 
			// label3
			// 
			this->label3->AutoSize = true;
			this->label3->Location = System::Drawing::Point(15, 105);
			this->label3->Name = L"label3";
			this->label3->Size = System::Drawing::Size(93, 13);
			this->label3->TabIndex = 3;
			this->label3->Text = L"Номер телефона";
			// 
			// textBox_Full_name
			// 
			this->textBox_Full_name->Location = System::Drawing::Point(15, 30);
			this->textBox_Full_name->Name = L"textBox_Full_name";
			this->textBox_Full_name->Size = System::Drawing::Size(230, 20);
			this->textBox_Full_name->TabIndex = 4;
			// 
			// textBox_DLN
			// 
			this->textBox_DLN->Location = System::Drawing::Point(15, 75);
			this->textBox_DLN->Name = L"textBox_DLN";
			this->textBox_DLN->Size = System::Drawing::Size(230, 20);
			this->textBox_DLN->TabIndex = 5;
			// 
			// textBox_Phone_number
			// 
			this->textBox_Phone_number->Location = System::Drawing::Point(15, 120);
			this->textBox_Phone_number->Name = L"textBox_Phone_number";
			this->textBox_Phone_number->Size = System::Drawing::Size(230, 20);
			this->textBox_Phone_number->TabIndex = 6;
			// 
			// textBox_Password
			// 
			this->textBox_Password->Location = System::Drawing::Point(15, 210);
			this->textBox_Password->Name = L"textBox_Password";
			this->textBox_Password->Size = System::Drawing::Size(230, 20);
			this->textBox_Password->TabIndex = 10;
			// 
			// textBox_Login
			// 
			this->textBox_Login->Location = System::Drawing::Point(15, 165);
			this->textBox_Login->Name = L"textBox_Login";
			this->textBox_Login->Size = System::Drawing::Size(230, 20);
			this->textBox_Login->TabIndex = 9;
			// 
			// label4
			// 
			this->label4->AutoSize = true;
			this->label4->Location = System::Drawing::Point(15, 195);
			this->label4->Name = L"label4";
			this->label4->Size = System::Drawing::Size(45, 13);
			this->label4->TabIndex = 8;
			this->label4->Text = L"Пароль";
			// 
			// label5
			// 
			this->label5->AutoSize = true;
			this->label5->Location = System::Drawing::Point(15, 150);
			this->label5->Name = L"label5";
			this->label5->Size = System::Drawing::Size(38, 13);
			this->label5->TabIndex = 7;
			this->label5->Text = L"Логин";
			// 
			// button_Enter
			// 
			this->button_Enter->Location = System::Drawing::Point(80, 245);
			this->button_Enter->Name = L"button_Enter";
			this->button_Enter->Size = System::Drawing::Size(100, 30);
			this->button_Enter->TabIndex = 11;
			this->button_Enter->Text = L"Ввод";
			this->button_Enter->UseVisualStyleBackColor = true;
			this->button_Enter->Click += gcnew System::EventHandler(this, &Add_client_Form::button_Enter_Click);
			// 
			// button_Back
			// 
			this->button_Back->Location = System::Drawing::Point(15, 290);
			this->button_Back->Name = L"button_Back";
			this->button_Back->Size = System::Drawing::Size(100, 30);
			this->button_Back->TabIndex = 12;
			this->button_Back->Text = L"Назад";
			this->button_Back->UseVisualStyleBackColor = true;
			this->button_Back->Click += gcnew System::EventHandler(this, &Add_client_Form::button_Back_Click);
			// 
			// button_Exit
			// 
			this->button_Exit->Location = System::Drawing::Point(145, 290);
			this->button_Exit->Name = L"button_Exit";
			this->button_Exit->Size = System::Drawing::Size(100, 30);
			this->button_Exit->TabIndex = 13;
			this->button_Exit->Text = L"Назад";
			this->button_Exit->UseVisualStyleBackColor = true;
			this->button_Exit->Click += gcnew System::EventHandler(this, &Add_client_Form::button_Exit_Click);
			// 
			// Add_client_Form
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(259, 329);
			this->Controls->Add(this->button_Exit);
			this->Controls->Add(this->button_Back);
			this->Controls->Add(this->button_Enter);
			this->Controls->Add(this->textBox_Password);
			this->Controls->Add(this->textBox_Login);
			this->Controls->Add(this->label4);
			this->Controls->Add(this->label5);
			this->Controls->Add(this->textBox_Phone_number);
			this->Controls->Add(this->textBox_DLN);
			this->Controls->Add(this->textBox_Full_name);
			this->Controls->Add(this->label3);
			this->Controls->Add(this->label2);
			this->Controls->Add(this->label1);
			this->Name = L"Add_client_Form";
			this->Text = L"Add_client_Form";
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion
private: System::Void button_Enter_Click(System::Object^ sender, System::EventArgs^ e);
private: System::Void button_Back_Click(System::Object^ sender, System::EventArgs^ e);
private: System::Void button_Exit_Click(System::Object^ sender, System::EventArgs^ e);
};
}
