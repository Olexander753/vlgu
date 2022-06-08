#pragma once
#include "Connection.h"
#include "Manager.h"

namespace Курсачпотп {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;

	/// <summary>
	/// Сводка для Add_manager_Form
	/// </summary>
	public ref class Add_manager_Form : public System::Windows::Forms::Form
	{
	public:
		Add_manager_Form(void)
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
		~Add_manager_Form()
		{
			if (components)
			{
				delete components;
			}
		}
	private: System::Windows::Forms::Button^ button_back;
	protected:
	private: System::Windows::Forms::Button^ button_exit;
	private: System::Windows::Forms::Label^ label1;
	private: System::Windows::Forms::Label^ label2;
	private: System::Windows::Forms::Label^ label3;
	private: System::Windows::Forms::Label^ label4;
	private: System::Windows::Forms::Label^ label5;
	private: System::Windows::Forms::TextBox^ textBox_Full_name;
	private: System::Windows::Forms::TextBox^ textBox_Passport_data;
	private: System::Windows::Forms::TextBox^ textBox_Number;
	private: System::Windows::Forms::TextBox^ textBox_Login;
	private: System::Windows::Forms::TextBox^ textBox_Password;











	private: System::Windows::Forms::Button^ button_add;


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
			this->button_back = (gcnew System::Windows::Forms::Button());
			this->button_exit = (gcnew System::Windows::Forms::Button());
			this->label1 = (gcnew System::Windows::Forms::Label());
			this->label2 = (gcnew System::Windows::Forms::Label());
			this->label3 = (gcnew System::Windows::Forms::Label());
			this->label4 = (gcnew System::Windows::Forms::Label());
			this->label5 = (gcnew System::Windows::Forms::Label());
			this->textBox_Full_name = (gcnew System::Windows::Forms::TextBox());
			this->textBox_Passport_data = (gcnew System::Windows::Forms::TextBox());
			this->textBox_Number = (gcnew System::Windows::Forms::TextBox());
			this->textBox_Login = (gcnew System::Windows::Forms::TextBox());
			this->textBox_Password = (gcnew System::Windows::Forms::TextBox());
			this->button_add = (gcnew System::Windows::Forms::Button());
			this->SuspendLayout();
			// 
			// button_back
			// 
			this->button_back->Location = System::Drawing::Point(15, 300);
			this->button_back->Name = L"button_back";
			this->button_back->Size = System::Drawing::Size(75, 23);
			this->button_back->TabIndex = 0;
			this->button_back->Text = L"Назад";
			this->button_back->UseVisualStyleBackColor = true;
			this->button_back->Click += gcnew System::EventHandler(this, &Add_manager_Form::button_back_Click);
			// 
			// button_exit
			// 
			this->button_exit->Location = System::Drawing::Point(195, 300);
			this->button_exit->Name = L"button_exit";
			this->button_exit->Size = System::Drawing::Size(75, 23);
			this->button_exit->TabIndex = 1;
			this->button_exit->Text = L"Выход";
			this->button_exit->UseVisualStyleBackColor = true;
			this->button_exit->Click += gcnew System::EventHandler(this, &Add_manager_Form::button_exit_Click);
			// 
			// label1
			// 
			this->label1->AutoSize = true;
			this->label1->Location = System::Drawing::Point(15, 15);
			this->label1->Name = L"label1";
			this->label1->Size = System::Drawing::Size(34, 13);
			this->label1->TabIndex = 2;
			this->label1->Text = L"ФИО";
			// 
			// label2
			// 
			this->label2->AutoSize = true;
			this->label2->Location = System::Drawing::Point(15, 65);
			this->label2->Name = L"label2";
			this->label2->Size = System::Drawing::Size(111, 13);
			this->label2->TabIndex = 3;
			this->label2->Text = L"Паспортные данные";
			// 
			// label3
			// 
			this->label3->AutoSize = true;
			this->label3->Location = System::Drawing::Point(15, 115);
			this->label3->Name = L"label3";
			this->label3->Size = System::Drawing::Size(93, 13);
			this->label3->TabIndex = 4;
			this->label3->Text = L"Номер телефона";
			// 
			// label4
			// 
			this->label4->AutoSize = true;
			this->label4->Location = System::Drawing::Point(15, 165);
			this->label4->Name = L"label4";
			this->label4->Size = System::Drawing::Size(38, 13);
			this->label4->TabIndex = 5;
			this->label4->Text = L"Логин";
			// 
			// label5
			// 
			this->label5->AutoSize = true;
			this->label5->Location = System::Drawing::Point(15, 215);
			this->label5->Name = L"label5";
			this->label5->Size = System::Drawing::Size(45, 13);
			this->label5->TabIndex = 6;
			this->label5->Text = L"Пароль";
			// 
			// textBox_Full_name
			// 
			this->textBox_Full_name->Location = System::Drawing::Point(15, 30);
			this->textBox_Full_name->Name = L"textBox_Full_name";
			this->textBox_Full_name->Size = System::Drawing::Size(255, 20);
			this->textBox_Full_name->TabIndex = 7;
			// 
			// textBox_Passport_data
			// 
			this->textBox_Passport_data->Location = System::Drawing::Point(15, 80);
			this->textBox_Passport_data->Name = L"textBox_Passport_data";
			this->textBox_Passport_data->Size = System::Drawing::Size(255, 20);
			this->textBox_Passport_data->TabIndex = 8;
			// 
			// textBox_Number
			// 
			this->textBox_Number->Location = System::Drawing::Point(15, 130);
			this->textBox_Number->Name = L"textBox_Number";
			this->textBox_Number->Size = System::Drawing::Size(255, 20);
			this->textBox_Number->TabIndex = 9;
			// 
			// textBox_Login
			// 
			this->textBox_Login->Location = System::Drawing::Point(15, 180);
			this->textBox_Login->Name = L"textBox_Login";
			this->textBox_Login->Size = System::Drawing::Size(255, 20);
			this->textBox_Login->TabIndex = 10;
			// 
			// textBox_Password
			// 
			this->textBox_Password->Location = System::Drawing::Point(15, 230);
			this->textBox_Password->Name = L"textBox_Password";
			this->textBox_Password->Size = System::Drawing::Size(255, 20);
			this->textBox_Password->TabIndex = 11;
			// 
			// button_add
			// 
			this->button_add->Location = System::Drawing::Point(16, 256);
			this->button_add->Name = L"button_add";
			this->button_add->Size = System::Drawing::Size(254, 26);
			this->button_add->TabIndex = 12;
			this->button_add->Text = L"Добавить";
			this->button_add->UseVisualStyleBackColor = true;
			this->button_add->Click += gcnew System::EventHandler(this, &Add_manager_Form::button_add_Click);
			// 
			// Add_manager_Form
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(284, 327);
			this->Controls->Add(this->button_add);
			this->Controls->Add(this->textBox_Password);
			this->Controls->Add(this->textBox_Login);
			this->Controls->Add(this->textBox_Number);
			this->Controls->Add(this->textBox_Passport_data);
			this->Controls->Add(this->textBox_Full_name);
			this->Controls->Add(this->label5);
			this->Controls->Add(this->label4);
			this->Controls->Add(this->label3);
			this->Controls->Add(this->label2);
			this->Controls->Add(this->label1);
			this->Controls->Add(this->button_exit);
			this->Controls->Add(this->button_back);
			this->Name = L"Add_manager_Form";
			this->Text = L"Add_manager_Form";
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion
private: System::Void button_back_Click(System::Object^ sender, System::EventArgs^ e);
private: System::Void button_exit_Click(System::Object^ sender, System::EventArgs^ e);
private: System::Void button_add_Click(System::Object^ sender, System::EventArgs^ e);
};
}
