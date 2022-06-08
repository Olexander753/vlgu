#pragma once
#include "Request.h"
#include "Connection.h"
#include "Repair.h"
#include "Detal.h"
#include "Mechanic.h"
#include "Add_client_Form.h"

namespace Курсачпотп {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;

	/// <summary>
	/// Сводка для Add_request_Form
	/// </summary>
	public ref class Add_request_Form : public System::Windows::Forms::Form
	{
	public:
		Add_request_Form(void)
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
		~Add_request_Form()
		{
			if (components)
			{
				delete components;
			}
		}
	private: System::Windows::Forms::Label^ label1;
	public: System::Windows::Forms::TextBox^ textBox_DLN;
	protected:
	private: System::Windows::Forms::Label^ label2;
	private: System::Windows::Forms::Label^ label3;
	private: System::Windows::Forms::Label^ label4;
	private: System::Windows::Forms::Label^ label5;
	private: System::Windows::Forms::TextBox^ textBox_Number_of_car;
	private: System::Windows::Forms::TextBox^ textBox_Brand_of_car;
	private: System::Windows::Forms::TextBox^ textBox_Mode_of_car;
	public: System::Windows::Forms::ComboBox^ comboBox_Repair;
	private: System::Windows::Forms::Label^ label6;
	public: System::Windows::Forms::ComboBox^ comboBox_Detal;
	private: System::Windows::Forms::Label^ label7;
	private: System::Windows::Forms::TextBox^ textBox_Quantity_detals;
	private: System::Windows::Forms::Label^ label8;
	private: System::Windows::Forms::Button^ button_back;
	private: System::Windows::Forms::Button^ button_exit;
	private: System::Windows::Forms::Button^ button_Add;
	public: System::Windows::Forms::ComboBox^ comboBox_Mechanics;
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
			this->textBox_DLN = (gcnew System::Windows::Forms::TextBox());
			this->label2 = (gcnew System::Windows::Forms::Label());
			this->label3 = (gcnew System::Windows::Forms::Label());
			this->label4 = (gcnew System::Windows::Forms::Label());
			this->label5 = (gcnew System::Windows::Forms::Label());
			this->textBox_Number_of_car = (gcnew System::Windows::Forms::TextBox());
			this->textBox_Brand_of_car = (gcnew System::Windows::Forms::TextBox());
			this->textBox_Mode_of_car = (gcnew System::Windows::Forms::TextBox());
			this->comboBox_Repair = (gcnew System::Windows::Forms::ComboBox());
			this->label6 = (gcnew System::Windows::Forms::Label());
			this->comboBox_Detal = (gcnew System::Windows::Forms::ComboBox());
			this->label7 = (gcnew System::Windows::Forms::Label());
			this->textBox_Quantity_detals = (gcnew System::Windows::Forms::TextBox());
			this->label8 = (gcnew System::Windows::Forms::Label());
			this->button_back = (gcnew System::Windows::Forms::Button());
			this->button_exit = (gcnew System::Windows::Forms::Button());
			this->button_Add = (gcnew System::Windows::Forms::Button());
			this->comboBox_Mechanics = (gcnew System::Windows::Forms::ComboBox());
			this->SuspendLayout();
			// 
			// label1
			// 
			this->label1->AutoSize = true;
			this->label1->Location = System::Drawing::Point(15, 15);
			this->label1->Name = L"label1";
			this->label1->Size = System::Drawing::Size(141, 13);
			this->label1->TabIndex = 0;
			this->label1->Text = L"Номер водительских прав";
			// 
			// textBox_DLN
			// 
			this->textBox_DLN->Location = System::Drawing::Point(15, 30);
			this->textBox_DLN->Name = L"textBox_DLN";
			this->textBox_DLN->Size = System::Drawing::Size(140, 20);
			this->textBox_DLN->TabIndex = 1;
			// 
			// label2
			// 
			this->label2->AutoSize = true;
			this->label2->Location = System::Drawing::Point(15, 65);
			this->label2->Name = L"label2";
			this->label2->Size = System::Drawing::Size(86, 13);
			this->label2->TabIndex = 2;
			this->label2->Text = L"Номер машины";
			// 
			// label3
			// 
			this->label3->AutoSize = true;
			this->label3->Location = System::Drawing::Point(15, 115);
			this->label3->Name = L"label3";
			this->label3->Size = System::Drawing::Size(85, 13);
			this->label3->TabIndex = 3;
			this->label3->Text = L"Марка машины";
			// 
			// label4
			// 
			this->label4->AutoSize = true;
			this->label4->Location = System::Drawing::Point(15, 165);
			this->label4->Name = L"label4";
			this->label4->Size = System::Drawing::Size(91, 13);
			this->label4->TabIndex = 4;
			this->label4->Text = L"Модель машины";
			// 
			// label5
			// 
			this->label5->AutoSize = true;
			this->label5->Location = System::Drawing::Point(180, 16);
			this->label5->Name = L"label5";
			this->label5->Size = System::Drawing::Size(51, 13);
			this->label5->TabIndex = 5;
			this->label5->Text = L"Механик";
			// 
			// textBox_Number_of_car
			// 
			this->textBox_Number_of_car->Location = System::Drawing::Point(15, 80);
			this->textBox_Number_of_car->Name = L"textBox_Number_of_car";
			this->textBox_Number_of_car->Size = System::Drawing::Size(140, 20);
			this->textBox_Number_of_car->TabIndex = 6;
			// 
			// textBox_Brand_of_car
			// 
			this->textBox_Brand_of_car->Location = System::Drawing::Point(15, 130);
			this->textBox_Brand_of_car->Name = L"textBox_Brand_of_car";
			this->textBox_Brand_of_car->Size = System::Drawing::Size(140, 20);
			this->textBox_Brand_of_car->TabIndex = 7;
			// 
			// textBox_Mode_of_car
			// 
			this->textBox_Mode_of_car->Location = System::Drawing::Point(15, 180);
			this->textBox_Mode_of_car->Name = L"textBox_Mode_of_car";
			this->textBox_Mode_of_car->Size = System::Drawing::Size(140, 20);
			this->textBox_Mode_of_car->TabIndex = 8;
			// 
			// comboBox_Repair
			// 
			this->comboBox_Repair->FormattingEnabled = true;
			this->comboBox_Repair->Location = System::Drawing::Point(180, 80);
			this->comboBox_Repair->Name = L"comboBox_Repair";
			this->comboBox_Repair->Size = System::Drawing::Size(140, 21);
			this->comboBox_Repair->TabIndex = 10;
			// 
			// label6
			// 
			this->label6->AutoSize = true;
			this->label6->Location = System::Drawing::Point(180, 65);
			this->label6->Name = L"label6";
			this->label6->Size = System::Drawing::Size(72, 13);
			this->label6->TabIndex = 11;
			this->label6->Text = L"Вид ремонта";
			// 
			// comboBox_Detal
			// 
			this->comboBox_Detal->FormattingEnabled = true;
			this->comboBox_Detal->Location = System::Drawing::Point(180, 130);
			this->comboBox_Detal->Name = L"comboBox_Detal";
			this->comboBox_Detal->Size = System::Drawing::Size(140, 21);
			this->comboBox_Detal->TabIndex = 12;
			// 
			// label7
			// 
			this->label7->AutoSize = true;
			this->label7->Location = System::Drawing::Point(180, 115);
			this->label7->Name = L"label7";
			this->label7->Size = System::Drawing::Size(45, 13);
			this->label7->TabIndex = 13;
			this->label7->Text = L"Деталь";
			// 
			// textBox_Quantity_detals
			// 
			this->textBox_Quantity_detals->Location = System::Drawing::Point(180, 180);
			this->textBox_Quantity_detals->Name = L"textBox_Quantity_detals";
			this->textBox_Quantity_detals->Size = System::Drawing::Size(140, 20);
			this->textBox_Quantity_detals->TabIndex = 15;
			// 
			// label8
			// 
			this->label8->AutoSize = true;
			this->label8->Location = System::Drawing::Point(180, 165);
			this->label8->Name = L"label8";
			this->label8->Size = System::Drawing::Size(66, 13);
			this->label8->TabIndex = 14;
			this->label8->Text = L"Количество";
			// 
			// button_back
			// 
			this->button_back->Location = System::Drawing::Point(15, 256);
			this->button_back->Name = L"button_back";
			this->button_back->Size = System::Drawing::Size(75, 23);
			this->button_back->TabIndex = 16;
			this->button_back->Text = L"Назад";
			this->button_back->UseVisualStyleBackColor = true;
			this->button_back->Click += gcnew System::EventHandler(this, &Add_request_Form::button_back_Click);
			// 
			// button_exit
			// 
			this->button_exit->Location = System::Drawing::Point(245, 255);
			this->button_exit->Name = L"button_exit";
			this->button_exit->Size = System::Drawing::Size(75, 23);
			this->button_exit->TabIndex = 17;
			this->button_exit->Text = L"Выход";
			this->button_exit->UseVisualStyleBackColor = true;
			this->button_exit->Click += gcnew System::EventHandler(this, &Add_request_Form::button_exit_Click);
			// 
			// button_Add
			// 
			this->button_Add->Location = System::Drawing::Point(113, 216);
			this->button_Add->Name = L"button_Add";
			this->button_Add->Size = System::Drawing::Size(100, 30);
			this->button_Add->TabIndex = 18;
			this->button_Add->Text = L"Добавить";
			this->button_Add->UseVisualStyleBackColor = true;
			this->button_Add->Click += gcnew System::EventHandler(this, &Add_request_Form::button_Add_Click);
			// 
			// comboBox_Mechanics
			// 
			this->comboBox_Mechanics->FormattingEnabled = true;
			this->comboBox_Mechanics->Location = System::Drawing::Point(180, 30);
			this->comboBox_Mechanics->Name = L"comboBox_Mechanics";
			this->comboBox_Mechanics->Size = System::Drawing::Size(140, 21);
			this->comboBox_Mechanics->TabIndex = 19;
			// 
			// Add_request_Form
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(334, 291);
			this->Controls->Add(this->comboBox_Mechanics);
			this->Controls->Add(this->button_Add);
			this->Controls->Add(this->button_exit);
			this->Controls->Add(this->button_back);
			this->Controls->Add(this->textBox_Quantity_detals);
			this->Controls->Add(this->label8);
			this->Controls->Add(this->label7);
			this->Controls->Add(this->comboBox_Detal);
			this->Controls->Add(this->label6);
			this->Controls->Add(this->comboBox_Repair);
			this->Controls->Add(this->textBox_Mode_of_car);
			this->Controls->Add(this->textBox_Brand_of_car);
			this->Controls->Add(this->textBox_Number_of_car);
			this->Controls->Add(this->label5);
			this->Controls->Add(this->label4);
			this->Controls->Add(this->label3);
			this->Controls->Add(this->label2);
			this->Controls->Add(this->textBox_DLN);
			this->Controls->Add(this->label1);
			this->Name = L"Add_request_Form";
			this->Text = L"Add_request_Form";
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion
private: System::Void button_Add_Click(System::Object^ sender, System::EventArgs^ e);
private: System::Void button_exit_Click(System::Object^ sender, System::EventArgs^ e);
private: System::Void button_back_Click(System::Object^ sender, System::EventArgs^ e);
};
}
