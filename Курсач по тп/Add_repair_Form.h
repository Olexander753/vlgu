#pragma once
#include "Connection.h"
#include "Repair.h"

namespace Курсачпотп {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;

	/// <summary>
	/// Сводка для Add_repair_Form
	/// </summary>
	public ref class Add_repair_Form : public System::Windows::Forms::Form
	{
	public:
		Add_repair_Form(void)
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
		~Add_repair_Form()
		{
			if (components)
			{
				delete components;
			}
		}
	private: System::Windows::Forms::TextBox^ textBox_Name;
	protected:
	private: System::Windows::Forms::Label^ label2;
	private: System::Windows::Forms::TextBox^ textBox_Price;
	private: System::Windows::Forms::Label^ label3;
	private: System::Windows::Forms::Button^ button_Add;
	private: System::Windows::Forms::Button^ button_Back;
	private: System::Windows::Forms::Button^ button_Exit;

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
			this->textBox_Name = (gcnew System::Windows::Forms::TextBox());
			this->label2 = (gcnew System::Windows::Forms::Label());
			this->textBox_Price = (gcnew System::Windows::Forms::TextBox());
			this->label3 = (gcnew System::Windows::Forms::Label());
			this->button_Add = (gcnew System::Windows::Forms::Button());
			this->button_Back = (gcnew System::Windows::Forms::Button());
			this->button_Exit = (gcnew System::Windows::Forms::Button());
			this->SuspendLayout();
			// 
			// textBox_Name
			// 
			this->textBox_Name->Location = System::Drawing::Point(15, 30);
			this->textBox_Name->Name = L"textBox_Name";
			this->textBox_Name->Size = System::Drawing::Size(200, 20);
			this->textBox_Name->TabIndex = 3;
			// 
			// label2
			// 
			this->label2->AutoSize = true;
			this->label2->Location = System::Drawing::Point(15, 10);
			this->label2->Name = L"label2";
			this->label2->Size = System::Drawing::Size(57, 13);
			this->label2->TabIndex = 2;
			this->label2->Text = L"Название";
			// 
			// textBox_Price
			// 
			this->textBox_Price->Location = System::Drawing::Point(15, 80);
			this->textBox_Price->Name = L"textBox_Price";
			this->textBox_Price->Size = System::Drawing::Size(200, 20);
			this->textBox_Price->TabIndex = 5;
			// 
			// label3
			// 
			this->label3->AutoSize = true;
			this->label3->Location = System::Drawing::Point(15, 60);
			this->label3->Name = L"label3";
			this->label3->Size = System::Drawing::Size(62, 13);
			this->label3->TabIndex = 4;
			this->label3->Text = L"Стоимость";
			// 
			// button_Add
			// 
			this->button_Add->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 9.75F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->button_Add->Location = System::Drawing::Point(55, 120);
			this->button_Add->Name = L"button_Add";
			this->button_Add->Size = System::Drawing::Size(120, 30);
			this->button_Add->TabIndex = 6;
			this->button_Add->Text = L"Добвать";
			this->button_Add->UseVisualStyleBackColor = true;
			this->button_Add->Click += gcnew System::EventHandler(this, &Add_repair_Form::button_Add_Click);
			// 
			// button_Back
			// 
			this->button_Back->Location = System::Drawing::Point(15, 175);
			this->button_Back->Name = L"button_Back";
			this->button_Back->Size = System::Drawing::Size(75, 25);
			this->button_Back->TabIndex = 7;
			this->button_Back->Text = L"Назад";
			this->button_Back->UseVisualStyleBackColor = true;
			this->button_Back->Click += gcnew System::EventHandler(this, &Add_repair_Form::button_Back_Click);
			// 
			// button_Exit
			// 
			this->button_Exit->Location = System::Drawing::Point(135, 175);
			this->button_Exit->Name = L"button_Exit";
			this->button_Exit->Size = System::Drawing::Size(75, 25);
			this->button_Exit->TabIndex = 8;
			this->button_Exit->Text = L"Выход";
			this->button_Exit->UseVisualStyleBackColor = true;
			this->button_Exit->Click += gcnew System::EventHandler(this, &Add_repair_Form::button_Exit_Click);
			// 
			// Add_repair_Form
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(234, 211);
			this->Controls->Add(this->button_Exit);
			this->Controls->Add(this->button_Back);
			this->Controls->Add(this->button_Add);
			this->Controls->Add(this->textBox_Price);
			this->Controls->Add(this->label3);
			this->Controls->Add(this->textBox_Name);
			this->Controls->Add(this->label2);
			this->Name = L"Add_repair_Form";
			this->Text = L"Добавить ремонт";
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion
private: System::Void button_Add_Click(System::Object^ sender, System::EventArgs^ e);
private: System::Void button_Back_Click(System::Object^ sender, System::EventArgs^ e);
private: System::Void button_Exit_Click(System::Object^ sender, System::EventArgs^ e);
};
}
