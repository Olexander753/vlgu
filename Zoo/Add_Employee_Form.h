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
	/// Сводка для Add_Employee_Form
	/// </summary>
	public ref class Add_Employee_Form : public System::Windows::Forms::Form
	{
	public:
		Add_Employee_Form(void)
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
		~Add_Employee_Form()
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
	private: System::Windows::Forms::Label^ label4;
	private: System::Windows::Forms::Button^ button_Add;
	private: System::Windows::Forms::TextBox^ textBox_Full_name;
	private: System::Windows::Forms::TextBox^ textBox_Passport_data;
	private: System::Windows::Forms::TextBox^ textBox_Login;
	private: System::Windows::Forms::TextBox^ textBox_Password;
	public: System::Windows::Forms::Label^ label5;

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
			this->label4 = (gcnew System::Windows::Forms::Label());
			this->button_Add = (gcnew System::Windows::Forms::Button());
			this->textBox_Full_name = (gcnew System::Windows::Forms::TextBox());
			this->textBox_Passport_data = (gcnew System::Windows::Forms::TextBox());
			this->textBox_Login = (gcnew System::Windows::Forms::TextBox());
			this->textBox_Password = (gcnew System::Windows::Forms::TextBox());
			this->label5 = (gcnew System::Windows::Forms::Label());
			this->SuspendLayout();
			// 
			// label1
			// 
			this->label1->AutoSize = true;
			this->label1->Location = System::Drawing::Point(15, 30);
			this->label1->Name = L"label1";
			this->label1->Size = System::Drawing::Size(34, 13);
			this->label1->TabIndex = 0;
			this->label1->Text = L"ФИО";
			// 
			// label2
			// 
			this->label2->AutoSize = true;
			this->label2->Location = System::Drawing::Point(15, 90);
			this->label2->Name = L"label2";
			this->label2->Size = System::Drawing::Size(111, 13);
			this->label2->TabIndex = 1;
			this->label2->Text = L"Паспортные данные";
			// 
			// label3
			// 
			this->label3->AutoSize = true;
			this->label3->Location = System::Drawing::Point(250, 30);
			this->label3->Name = L"label3";
			this->label3->Size = System::Drawing::Size(38, 13);
			this->label3->TabIndex = 2;
			this->label3->Text = L"Логин";
			// 
			// label4
			// 
			this->label4->AutoSize = true;
			this->label4->Location = System::Drawing::Point(250, 90);
			this->label4->Name = L"label4";
			this->label4->Size = System::Drawing::Size(45, 13);
			this->label4->TabIndex = 3;
			this->label4->Text = L"Пароль";
			// 
			// button_Add
			// 
			this->button_Add->Location = System::Drawing::Point(382, 150);
			this->button_Add->Name = L"button_Add";
			this->button_Add->Size = System::Drawing::Size(75, 23);
			this->button_Add->TabIndex = 4;
			this->button_Add->Text = L"Добавить";
			this->button_Add->UseVisualStyleBackColor = true;
			this->button_Add->Click += gcnew System::EventHandler(this, &Add_Employee_Form::button_Add_Click);
			// 
			// textBox_Full_name
			// 
			this->textBox_Full_name->Location = System::Drawing::Point(18, 47);
			this->textBox_Full_name->Name = L"textBox_Full_name";
			this->textBox_Full_name->Size = System::Drawing::Size(204, 20);
			this->textBox_Full_name->TabIndex = 5;
			// 
			// textBox_Passport_data
			// 
			this->textBox_Passport_data->Location = System::Drawing::Point(18, 106);
			this->textBox_Passport_data->Name = L"textBox_Passport_data";
			this->textBox_Passport_data->Size = System::Drawing::Size(204, 20);
			this->textBox_Passport_data->TabIndex = 6;
			// 
			// textBox_Login
			// 
			this->textBox_Login->Location = System::Drawing::Point(253, 47);
			this->textBox_Login->Name = L"textBox_Login";
			this->textBox_Login->Size = System::Drawing::Size(204, 20);
			this->textBox_Login->TabIndex = 7;
			// 
			// textBox_Password
			// 
			this->textBox_Password->Location = System::Drawing::Point(253, 106);
			this->textBox_Password->Name = L"textBox_Password";
			this->textBox_Password->Size = System::Drawing::Size(204, 20);
			this->textBox_Password->TabIndex = 8;
			// 
			// label5
			// 
			this->label5->AutoSize = true;
			this->label5->Location = System::Drawing::Point(91, 47);
			this->label5->Name = L"label5";
			this->label5->Size = System::Drawing::Size(35, 13);
			this->label5->TabIndex = 9;
			this->label5->Text = L"label5";
			// 
			// Add_Employee_Form
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(465, 185);
			this->Controls->Add(this->textBox_Password);
			this->Controls->Add(this->textBox_Login);
			this->Controls->Add(this->textBox_Passport_data);
			this->Controls->Add(this->textBox_Full_name);
			this->Controls->Add(this->button_Add);
			this->Controls->Add(this->label4);
			this->Controls->Add(this->label3);
			this->Controls->Add(this->label2);
			this->Controls->Add(this->label1);
			this->Controls->Add(this->label5);
			this->Name = L"Add_Employee_Form";
			this->Text = L"Add_Employee_Form";
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion
private: System::Void button_Add_Click(System::Object^ sender, System::EventArgs^ e);
};
}
