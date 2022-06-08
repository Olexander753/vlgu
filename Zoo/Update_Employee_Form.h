#pragma once
#include "Employee.h"
#include "User.h"

namespace Zoo {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;

	/// <summary>
	/// Сводка для Update_Employee_Form
	/// </summary>
	public ref class Update_Employee_Form : public System::Windows::Forms::Form
	{
	public:
		Update_Employee_Form(void)
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
		~Update_Employee_Form()
		{
			if (components)
			{
				delete components;
			}
		}
	public: System::Windows::Forms::TextBox^ textBox_Password;
	protected:
	public: System::Windows::Forms::TextBox^ textBox_Login;
	public: System::Windows::Forms::TextBox^ textBox_Passport_data;
	public: System::Windows::Forms::TextBox^ textBox_Full_name;
	private: System::Windows::Forms::Button^ button_Update;

	private: System::Windows::Forms::Label^ label4;
	private: System::Windows::Forms::Label^ label3;
	private: System::Windows::Forms::Label^ label2;
	private: System::Windows::Forms::Label^ label1;
	private: System::Windows::Forms::Label^ label5;
	public: System::Windows::Forms::Label^ label6;
	public: System::Windows::Forms::Label^ label7;
	public:

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
			this->textBox_Password = (gcnew System::Windows::Forms::TextBox());
			this->textBox_Login = (gcnew System::Windows::Forms::TextBox());
			this->textBox_Passport_data = (gcnew System::Windows::Forms::TextBox());
			this->textBox_Full_name = (gcnew System::Windows::Forms::TextBox());
			this->button_Update = (gcnew System::Windows::Forms::Button());
			this->label4 = (gcnew System::Windows::Forms::Label());
			this->label3 = (gcnew System::Windows::Forms::Label());
			this->label2 = (gcnew System::Windows::Forms::Label());
			this->label1 = (gcnew System::Windows::Forms::Label());
			this->label5 = (gcnew System::Windows::Forms::Label());
			this->label6 = (gcnew System::Windows::Forms::Label());
			this->label7 = (gcnew System::Windows::Forms::Label());
			this->SuspendLayout();
			// 
			// textBox_Password
			// 
			this->textBox_Password->Location = System::Drawing::Point(253, 116);
			this->textBox_Password->Name = L"textBox_Password";
			this->textBox_Password->Size = System::Drawing::Size(204, 20);
			this->textBox_Password->TabIndex = 17;
			// 
			// textBox_Login
			// 
			this->textBox_Login->Location = System::Drawing::Point(253, 57);
			this->textBox_Login->Name = L"textBox_Login";
			this->textBox_Login->Size = System::Drawing::Size(204, 20);
			this->textBox_Login->TabIndex = 16;
			// 
			// textBox_Passport_data
			// 
			this->textBox_Passport_data->Location = System::Drawing::Point(18, 116);
			this->textBox_Passport_data->Name = L"textBox_Passport_data";
			this->textBox_Passport_data->Size = System::Drawing::Size(204, 20);
			this->textBox_Passport_data->TabIndex = 15;
			// 
			// textBox_Full_name
			// 
			this->textBox_Full_name->Location = System::Drawing::Point(18, 57);
			this->textBox_Full_name->Name = L"textBox_Full_name";
			this->textBox_Full_name->Size = System::Drawing::Size(204, 20);
			this->textBox_Full_name->TabIndex = 14;
			// 
			// button_Update
			// 
			this->button_Update->Location = System::Drawing::Point(382, 160);
			this->button_Update->Name = L"button_Update";
			this->button_Update->Size = System::Drawing::Size(75, 23);
			this->button_Update->TabIndex = 13;
			this->button_Update->Text = L"Добавить";
			this->button_Update->UseVisualStyleBackColor = true;
			this->button_Update->Click += gcnew System::EventHandler(this, &Update_Employee_Form::button_Update_Click);
			// 
			// label4
			// 
			this->label4->AutoSize = true;
			this->label4->Location = System::Drawing::Point(250, 100);
			this->label4->Name = L"label4";
			this->label4->Size = System::Drawing::Size(45, 13);
			this->label4->TabIndex = 12;
			this->label4->Text = L"Пароль";
			// 
			// label3
			// 
			this->label3->AutoSize = true;
			this->label3->Location = System::Drawing::Point(250, 40);
			this->label3->Name = L"label3";
			this->label3->Size = System::Drawing::Size(38, 13);
			this->label3->TabIndex = 11;
			this->label3->Text = L"Логин";
			// 
			// label2
			// 
			this->label2->AutoSize = true;
			this->label2->Location = System::Drawing::Point(15, 100);
			this->label2->Name = L"label2";
			this->label2->Size = System::Drawing::Size(111, 13);
			this->label2->TabIndex = 10;
			this->label2->Text = L"Паспортные данные";
			// 
			// label1
			// 
			this->label1->AutoSize = true;
			this->label1->Location = System::Drawing::Point(15, 40);
			this->label1->Name = L"label1";
			this->label1->Size = System::Drawing::Size(34, 13);
			this->label1->TabIndex = 9;
			this->label1->Text = L"ФИО";
			// 
			// label5
			// 
			this->label5->AutoSize = true;
			this->label5->Location = System::Drawing::Point(18, 13);
			this->label5->Name = L"label5";
			this->label5->Size = System::Drawing::Size(74, 13);
			this->label5->TabIndex = 18;
			this->label5->Text = L"Сотрудник №";
			// 
			// label6
			// 
			this->label6->AutoSize = true;
			this->label6->Location = System::Drawing::Point(89, 13);
			this->label6->Name = L"label6";
			this->label6->Size = System::Drawing::Size(35, 13);
			this->label6->TabIndex = 19;
			this->label6->Text = L"label6";
			// 
			// label7
			// 
			this->label7->AutoSize = true;
			this->label7->Location = System::Drawing::Point(108, 60);
			this->label7->Name = L"label7";
			this->label7->Size = System::Drawing::Size(35, 13);
			this->label7->TabIndex = 20;
			this->label7->Text = L"label7";
			// 
			// Update_Employee_Form
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(476, 202);
			this->Controls->Add(this->label6);
			this->Controls->Add(this->label5);
			this->Controls->Add(this->textBox_Password);
			this->Controls->Add(this->textBox_Login);
			this->Controls->Add(this->textBox_Passport_data);
			this->Controls->Add(this->textBox_Full_name);
			this->Controls->Add(this->button_Update);
			this->Controls->Add(this->label4);
			this->Controls->Add(this->label3);
			this->Controls->Add(this->label2);
			this->Controls->Add(this->label1);
			this->Controls->Add(this->label7);
			this->Name = L"Update_Employee_Form";
			this->Text = L"Update_Employee_Form";
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion
private: System::Void button_Update_Click(System::Object^ sender, System::EventArgs^ e);
};
}
