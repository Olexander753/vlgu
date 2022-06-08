#pragma once
#include "Mechanic.h"
#include "Connection.h"

namespace Курсачпотп {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;

	/// <summary>
	/// Сводка для Add_mechanic_Form
	/// </summary>
	public ref class Add_mechanic_Form : public System::Windows::Forms::Form
	{
	public:
		Add_mechanic_Form(void)
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
		~Add_mechanic_Form()
		{
			if (components)
			{
				delete components;
			}
		}
	private: System::Windows::Forms::Button^ button_add;
	protected:
	private: System::Windows::Forms::TextBox^ textBox_Password;
	private: System::Windows::Forms::TextBox^ textBox_Login;
	private: System::Windows::Forms::TextBox^ textBox_Number;
	private: System::Windows::Forms::TextBox^ textBox_Passport_data;
	private: System::Windows::Forms::TextBox^ textBox_Qulification;
	private: System::Windows::Forms::Label^ label5;
	private: System::Windows::Forms::Label^ label4;
	private: System::Windows::Forms::Label^ label3;
	private: System::Windows::Forms::Label^ label2;
	private: System::Windows::Forms::Label^ label1;
	private: System::Windows::Forms::Button^ button_exit;
	private: System::Windows::Forms::Button^ button_back;
	private: System::Windows::Forms::TextBox^ textBox_Full_name;
	private: System::Windows::Forms::Label^ label6;

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
			this->button_add = (gcnew System::Windows::Forms::Button());
			this->textBox_Password = (gcnew System::Windows::Forms::TextBox());
			this->textBox_Login = (gcnew System::Windows::Forms::TextBox());
			this->textBox_Number = (gcnew System::Windows::Forms::TextBox());
			this->textBox_Passport_data = (gcnew System::Windows::Forms::TextBox());
			this->textBox_Qulification = (gcnew System::Windows::Forms::TextBox());
			this->label5 = (gcnew System::Windows::Forms::Label());
			this->label4 = (gcnew System::Windows::Forms::Label());
			this->label3 = (gcnew System::Windows::Forms::Label());
			this->label2 = (gcnew System::Windows::Forms::Label());
			this->label1 = (gcnew System::Windows::Forms::Label());
			this->button_exit = (gcnew System::Windows::Forms::Button());
			this->button_back = (gcnew System::Windows::Forms::Button());
			this->textBox_Full_name = (gcnew System::Windows::Forms::TextBox());
			this->label6 = (gcnew System::Windows::Forms::Label());
			this->SuspendLayout();
			// 
			// button_add
			// 
			this->button_add->Location = System::Drawing::Point(16, 321);
			this->button_add->Name = L"button_add";
			this->button_add->Size = System::Drawing::Size(254, 26);
			this->button_add->TabIndex = 25;
			this->button_add->Text = L"Добавить";
			this->button_add->UseVisualStyleBackColor = true;
			this->button_add->Click += gcnew System::EventHandler(this, &Add_mechanic_Form::button_add_Click);
			// 
			// textBox_Password
			// 
			this->textBox_Password->Location = System::Drawing::Point(15, 295);
			this->textBox_Password->Name = L"textBox_Password";
			this->textBox_Password->Size = System::Drawing::Size(255, 20);
			this->textBox_Password->TabIndex = 24;
			// 
			// textBox_Login
			// 
			this->textBox_Login->Location = System::Drawing::Point(15, 245);
			this->textBox_Login->Name = L"textBox_Login";
			this->textBox_Login->Size = System::Drawing::Size(255, 20);
			this->textBox_Login->TabIndex = 23;
			// 
			// textBox_Number
			// 
			this->textBox_Number->Location = System::Drawing::Point(15, 195);
			this->textBox_Number->Name = L"textBox_Number";
			this->textBox_Number->Size = System::Drawing::Size(255, 20);
			this->textBox_Number->TabIndex = 22;
			// 
			// textBox_Passport_data
			// 
			this->textBox_Passport_data->Location = System::Drawing::Point(15, 145);
			this->textBox_Passport_data->Name = L"textBox_Passport_data";
			this->textBox_Passport_data->Size = System::Drawing::Size(255, 20);
			this->textBox_Passport_data->TabIndex = 21;
			// 
			// textBox_Qulification
			// 
			this->textBox_Qulification->Location = System::Drawing::Point(15, 95);
			this->textBox_Qulification->Name = L"textBox_Qulification";
			this->textBox_Qulification->Size = System::Drawing::Size(255, 20);
			this->textBox_Qulification->TabIndex = 20;
			// 
			// label5
			// 
			this->label5->AutoSize = true;
			this->label5->Location = System::Drawing::Point(15, 280);
			this->label5->Name = L"label5";
			this->label5->Size = System::Drawing::Size(45, 13);
			this->label5->TabIndex = 19;
			this->label5->Text = L"Пароль";
			// 
			// label4
			// 
			this->label4->AutoSize = true;
			this->label4->Location = System::Drawing::Point(15, 230);
			this->label4->Name = L"label4";
			this->label4->Size = System::Drawing::Size(38, 13);
			this->label4->TabIndex = 18;
			this->label4->Text = L"Логин";
			// 
			// label3
			// 
			this->label3->AutoSize = true;
			this->label3->Location = System::Drawing::Point(15, 180);
			this->label3->Name = L"label3";
			this->label3->Size = System::Drawing::Size(93, 13);
			this->label3->TabIndex = 17;
			this->label3->Text = L"Номер телефона";
			// 
			// label2
			// 
			this->label2->AutoSize = true;
			this->label2->Location = System::Drawing::Point(15, 130);
			this->label2->Name = L"label2";
			this->label2->Size = System::Drawing::Size(111, 13);
			this->label2->TabIndex = 16;
			this->label2->Text = L"Паспортные данные";
			// 
			// label1
			// 
			this->label1->AutoSize = true;
			this->label1->Location = System::Drawing::Point(15, 80);
			this->label1->Name = L"label1";
			this->label1->Size = System::Drawing::Size(82, 13);
			this->label1->TabIndex = 15;
			this->label1->Text = L"Квалификация";
			// 
			// button_exit
			// 
			this->button_exit->Location = System::Drawing::Point(195, 365);
			this->button_exit->Name = L"button_exit";
			this->button_exit->Size = System::Drawing::Size(75, 23);
			this->button_exit->TabIndex = 14;
			this->button_exit->Text = L"Выход";
			this->button_exit->UseVisualStyleBackColor = true;
			this->button_exit->Click += gcnew System::EventHandler(this, &Add_mechanic_Form::button_exit_Click);
			// 
			// button_back
			// 
			this->button_back->Location = System::Drawing::Point(15, 365);
			this->button_back->Name = L"button_back";
			this->button_back->Size = System::Drawing::Size(75, 23);
			this->button_back->TabIndex = 13;
			this->button_back->Text = L"Назад";
			this->button_back->UseVisualStyleBackColor = true;
			this->button_back->Click += gcnew System::EventHandler(this, &Add_mechanic_Form::button_back_Click);
			// 
			// textBox_Full_name
			// 
			this->textBox_Full_name->Location = System::Drawing::Point(15, 45);
			this->textBox_Full_name->Name = L"textBox_Full_name";
			this->textBox_Full_name->Size = System::Drawing::Size(255, 20);
			this->textBox_Full_name->TabIndex = 27;
			// 
			// label6
			// 
			this->label6->AutoSize = true;
			this->label6->Location = System::Drawing::Point(15, 30);
			this->label6->Name = L"label6";
			this->label6->Size = System::Drawing::Size(34, 13);
			this->label6->TabIndex = 26;
			this->label6->Text = L"ФИО";
			// 
			// Add_mechanic_Form
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(284, 400);
			this->Controls->Add(this->textBox_Full_name);
			this->Controls->Add(this->label6);
			this->Controls->Add(this->button_add);
			this->Controls->Add(this->textBox_Password);
			this->Controls->Add(this->textBox_Login);
			this->Controls->Add(this->textBox_Number);
			this->Controls->Add(this->textBox_Passport_data);
			this->Controls->Add(this->textBox_Qulification);
			this->Controls->Add(this->label5);
			this->Controls->Add(this->label4);
			this->Controls->Add(this->label3);
			this->Controls->Add(this->label2);
			this->Controls->Add(this->label1);
			this->Controls->Add(this->button_exit);
			this->Controls->Add(this->button_back);
			this->Name = L"Add_mechanic_Form";
			this->Text = L"Add_mechanic_Form";
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion
private: System::Void button_back_Click(System::Object^ sender, System::EventArgs^ e);
private: System::Void button_add_Click(System::Object^ sender, System::EventArgs^ e);
private: System::Void button_exit_Click(System::Object^ sender, System::EventArgs^ e);
};
}
