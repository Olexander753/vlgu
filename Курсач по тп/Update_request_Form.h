#pragma once
#include "Request.h"
#include "Connection.h"
#include "Repair.h"
#include "Detal.h"
#include "Mechanic.h"

namespace Курсачпотп {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;

	/// <summary>
	/// Сводка для Update_request_Form
	/// </summary>
	public ref class Update_request_Form : public System::Windows::Forms::Form
	{
	public:
		Update_request_Form(void)
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
		~Update_request_Form()
		{
			if (components)
			{
				delete components;
			}
		}
	public: System::Windows::Forms::ComboBox^ comboBox_Mechanics;
	private: System::Windows::Forms::Button^ s;
	protected:
	private: System::Windows::Forms::Button^ button_exit;
	private: System::Windows::Forms::Button^ button_back;
	public: System::Windows::Forms::TextBox^ textBox_Quantity_detals;
	private: System::Windows::Forms::Label^ label8;
	private: System::Windows::Forms::Label^ label7;
	public: System::Windows::Forms::ComboBox^ comboBox_Detal;
	private: System::Windows::Forms::Label^ label6;
	public: System::Windows::Forms::ComboBox^ comboBox_Repair;
	public: System::Windows::Forms::TextBox^ textBox_Mode_of_car;
	public: System::Windows::Forms::TextBox^ textBox_Brand_of_car;
	public: System::Windows::Forms::TextBox^ textBox_Number_of_car;
	private: System::Windows::Forms::Label^ label5;
	private: System::Windows::Forms::Label^ label4;
	private: System::Windows::Forms::Label^ label3;
	private: System::Windows::Forms::Label^ label2;
	public: System::Windows::Forms::TextBox^ textBox_DLN;
	private: System::Windows::Forms::Label^ label1;
	public: System::Windows::Forms::Label^ label9;
	private: System::Windows::Forms::Label^ label10;
	private: System::Windows::Forms::Label^ label11;
	public: System::Windows::Forms::Label^ label12;
	public: System::Windows::Forms::Label^ label13;
	public:
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
			this->comboBox_Mechanics = (gcnew System::Windows::Forms::ComboBox());
			this->s = (gcnew System::Windows::Forms::Button());
			this->button_exit = (gcnew System::Windows::Forms::Button());
			this->button_back = (gcnew System::Windows::Forms::Button());
			this->textBox_Quantity_detals = (gcnew System::Windows::Forms::TextBox());
			this->label8 = (gcnew System::Windows::Forms::Label());
			this->label7 = (gcnew System::Windows::Forms::Label());
			this->comboBox_Detal = (gcnew System::Windows::Forms::ComboBox());
			this->label6 = (gcnew System::Windows::Forms::Label());
			this->comboBox_Repair = (gcnew System::Windows::Forms::ComboBox());
			this->textBox_Mode_of_car = (gcnew System::Windows::Forms::TextBox());
			this->textBox_Brand_of_car = (gcnew System::Windows::Forms::TextBox());
			this->textBox_Number_of_car = (gcnew System::Windows::Forms::TextBox());
			this->label5 = (gcnew System::Windows::Forms::Label());
			this->label4 = (gcnew System::Windows::Forms::Label());
			this->label3 = (gcnew System::Windows::Forms::Label());
			this->label2 = (gcnew System::Windows::Forms::Label());
			this->textBox_DLN = (gcnew System::Windows::Forms::TextBox());
			this->label1 = (gcnew System::Windows::Forms::Label());
			this->label9 = (gcnew System::Windows::Forms::Label());
			this->label10 = (gcnew System::Windows::Forms::Label());
			this->label11 = (gcnew System::Windows::Forms::Label());
			this->label12 = (gcnew System::Windows::Forms::Label());
			this->label13 = (gcnew System::Windows::Forms::Label());
			this->SuspendLayout();
			// 
			// comboBox_Mechanics
			// 
			this->comboBox_Mechanics->FormattingEnabled = true;
			this->comboBox_Mechanics->Location = System::Drawing::Point(180, 51);
			this->comboBox_Mechanics->Name = L"comboBox_Mechanics";
			this->comboBox_Mechanics->Size = System::Drawing::Size(140, 21);
			this->comboBox_Mechanics->TabIndex = 38;
			// 
			// s
			// 
			this->s->Location = System::Drawing::Point(113, 237);
			this->s->Name = L"s";
			this->s->Size = System::Drawing::Size(100, 30);
			this->s->TabIndex = 37;
			this->s->Text = L"Изменить";
			this->s->UseVisualStyleBackColor = true;
			this->s->Click += gcnew System::EventHandler(this, &Update_request_Form::button_Update_Click);
			// 
			// button_exit
			// 
			this->button_exit->Location = System::Drawing::Point(245, 268);
			this->button_exit->Name = L"button_exit";
			this->button_exit->Size = System::Drawing::Size(75, 23);
			this->button_exit->TabIndex = 36;
			this->button_exit->Text = L"Выход";
			this->button_exit->UseVisualStyleBackColor = true;
			this->button_exit->Click += gcnew System::EventHandler(this, &Update_request_Form::button_exit_Click);
			// 
			// button_back
			// 
			this->button_back->Location = System::Drawing::Point(15, 269);
			this->button_back->Name = L"button_back";
			this->button_back->Size = System::Drawing::Size(75, 23);
			this->button_back->TabIndex = 35;
			this->button_back->Text = L"Назад";
			this->button_back->UseVisualStyleBackColor = true;
			this->button_back->Click += gcnew System::EventHandler(this, &Update_request_Form::button_back_Click);
			// 
			// textBox_Quantity_detals
			// 
			this->textBox_Quantity_detals->Location = System::Drawing::Point(180, 201);
			this->textBox_Quantity_detals->Name = L"textBox_Quantity_detals";
			this->textBox_Quantity_detals->Size = System::Drawing::Size(140, 20);
			this->textBox_Quantity_detals->TabIndex = 34;
			// 
			// label8
			// 
			this->label8->AutoSize = true;
			this->label8->Location = System::Drawing::Point(180, 186);
			this->label8->Name = L"label8";
			this->label8->Size = System::Drawing::Size(66, 13);
			this->label8->TabIndex = 33;
			this->label8->Text = L"Количество";
			// 
			// label7
			// 
			this->label7->AutoSize = true;
			this->label7->Location = System::Drawing::Point(180, 136);
			this->label7->Name = L"label7";
			this->label7->Size = System::Drawing::Size(45, 13);
			this->label7->TabIndex = 32;
			this->label7->Text = L"Деталь";
			// 
			// comboBox_Detal
			// 
			this->comboBox_Detal->FormattingEnabled = true;
			this->comboBox_Detal->Location = System::Drawing::Point(180, 151);
			this->comboBox_Detal->Name = L"comboBox_Detal";
			this->comboBox_Detal->Size = System::Drawing::Size(140, 21);
			this->comboBox_Detal->TabIndex = 31;
			// 
			// label6
			// 
			this->label6->AutoSize = true;
			this->label6->Location = System::Drawing::Point(180, 86);
			this->label6->Name = L"label6";
			this->label6->Size = System::Drawing::Size(72, 13);
			this->label6->TabIndex = 30;
			this->label6->Text = L"Вид ремонта";
			// 
			// comboBox_Repair
			// 
			this->comboBox_Repair->FormattingEnabled = true;
			this->comboBox_Repair->Location = System::Drawing::Point(180, 101);
			this->comboBox_Repair->Name = L"comboBox_Repair";
			this->comboBox_Repair->Size = System::Drawing::Size(140, 21);
			this->comboBox_Repair->TabIndex = 29;
			// 
			// textBox_Mode_of_car
			// 
			this->textBox_Mode_of_car->Location = System::Drawing::Point(15, 201);
			this->textBox_Mode_of_car->Name = L"textBox_Mode_of_car";
			this->textBox_Mode_of_car->Size = System::Drawing::Size(140, 20);
			this->textBox_Mode_of_car->TabIndex = 28;
			// 
			// textBox_Brand_of_car
			// 
			this->textBox_Brand_of_car->Location = System::Drawing::Point(15, 151);
			this->textBox_Brand_of_car->Name = L"textBox_Brand_of_car";
			this->textBox_Brand_of_car->Size = System::Drawing::Size(140, 20);
			this->textBox_Brand_of_car->TabIndex = 27;
			// 
			// textBox_Number_of_car
			// 
			this->textBox_Number_of_car->Location = System::Drawing::Point(15, 101);
			this->textBox_Number_of_car->Name = L"textBox_Number_of_car";
			this->textBox_Number_of_car->Size = System::Drawing::Size(140, 20);
			this->textBox_Number_of_car->TabIndex = 26;
			// 
			// label5
			// 
			this->label5->AutoSize = true;
			this->label5->Location = System::Drawing::Point(180, 37);
			this->label5->Name = L"label5";
			this->label5->Size = System::Drawing::Size(51, 13);
			this->label5->TabIndex = 25;
			this->label5->Text = L"Механик";
			// 
			// label4
			// 
			this->label4->AutoSize = true;
			this->label4->Location = System::Drawing::Point(15, 186);
			this->label4->Name = L"label4";
			this->label4->Size = System::Drawing::Size(91, 13);
			this->label4->TabIndex = 24;
			this->label4->Text = L"Модель машины";
			// 
			// label3
			// 
			this->label3->AutoSize = true;
			this->label3->Location = System::Drawing::Point(15, 136);
			this->label3->Name = L"label3";
			this->label3->Size = System::Drawing::Size(85, 13);
			this->label3->TabIndex = 23;
			this->label3->Text = L"Марка машины";
			// 
			// label2
			// 
			this->label2->AutoSize = true;
			this->label2->Location = System::Drawing::Point(15, 86);
			this->label2->Name = L"label2";
			this->label2->Size = System::Drawing::Size(86, 13);
			this->label2->TabIndex = 22;
			this->label2->Text = L"Номер машины";
			// 
			// textBox_DLN
			// 
			this->textBox_DLN->Location = System::Drawing::Point(15, 51);
			this->textBox_DLN->Name = L"textBox_DLN";
			this->textBox_DLN->Size = System::Drawing::Size(140, 20);
			this->textBox_DLN->TabIndex = 21;
			// 
			// label1
			// 
			this->label1->AutoSize = true;
			this->label1->Location = System::Drawing::Point(15, 36);
			this->label1->Name = L"label1";
			this->label1->Size = System::Drawing::Size(141, 13);
			this->label1->TabIndex = 20;
			this->label1->Text = L"Номер водительских прав";
			// 
			// label9
			// 
			this->label9->AutoSize = true;
			this->label9->Location = System::Drawing::Point(71, 8);
			this->label9->Name = L"label9";
			this->label9->Size = System::Drawing::Size(35, 13);
			this->label9->TabIndex = 39;
			this->label9->Text = L"label9";
			// 
			// label10
			// 
			this->label10->AutoSize = true;
			this->label10->Location = System::Drawing::Point(15, 8);
			this->label10->Name = L"label10";
			this->label10->Size = System::Drawing::Size(59, 13);
			this->label10->TabIndex = 40;
			this->label10->Text = L"Ремонт №";
			// 
			// label11
			// 
			this->label11->AutoSize = true;
			this->label11->Location = System::Drawing::Point(114, 8);
			this->label11->Name = L"label11";
			this->label11->Size = System::Drawing::Size(82, 13);
			this->label11->TabIndex = 41;
			this->label11->Text = L"Дата ремонта:";
			// 
			// label12
			// 
			this->label12->AutoSize = true;
			this->label12->Location = System::Drawing::Point(190, 9);
			this->label12->Name = L"label12";
			this->label12->Size = System::Drawing::Size(41, 13);
			this->label12->TabIndex = 42;
			this->label12->Text = L"label12";
			// 
			// label13
			// 
			this->label13->AutoSize = true;
			this->label13->BackColor = System::Drawing::SystemColors::Control;
			this->label13->ForeColor = System::Drawing::SystemColors::ScrollBar;
			this->label13->Location = System::Drawing::Point(155, 246);
			this->label13->Name = L"label13";
			this->label13->Size = System::Drawing::Size(41, 13);
			this->label13->TabIndex = 43;
			this->label13->Text = L"label13";
			// 
			// Update_request_Form
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(334, 300);
			this->Controls->Add(this->label12);
			this->Controls->Add(this->label11);
			this->Controls->Add(this->label10);
			this->Controls->Add(this->label9);
			this->Controls->Add(this->comboBox_Mechanics);
			this->Controls->Add(this->s);
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
			this->Controls->Add(this->label13);
			this->Name = L"Update_request_Form";
			this->Text = L"Update_request_Form";
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion
private: System::Void button_Update_Click(System::Object^ sender, System::EventArgs^ e);
private: System::Void button_back_Click(System::Object^ sender, System::EventArgs^ e);
private: System::Void button_exit_Click(System::Object^ sender, System::EventArgs^ e);
};
}
