#pragma once

namespace Zoo {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;

	/// <summary>
	/// Сводка для Add_Food_Form
	/// </summary>
	public ref class Add_Food_Form : public System::Windows::Forms::Form
	{
	public:
		Add_Food_Form(void)
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
		~Add_Food_Form()
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
	public: System::Windows::Forms::ComboBox^ comboBox_Animal;
	private: System::Windows::Forms::TextBox^ textBox_Title;
	private: System::Windows::Forms::TextBox^ textBox_Qty;
	private: System::Windows::Forms::Button^ button_Add;
	public: System::Windows::Forms::Label^ label4;

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
			this->comboBox_Animal = (gcnew System::Windows::Forms::ComboBox());
			this->textBox_Title = (gcnew System::Windows::Forms::TextBox());
			this->textBox_Qty = (gcnew System::Windows::Forms::TextBox());
			this->button_Add = (gcnew System::Windows::Forms::Button());
			this->label4 = (gcnew System::Windows::Forms::Label());
			this->SuspendLayout();
			// 
			// label1
			// 
			this->label1->AutoSize = true;
			this->label1->Location = System::Drawing::Point(15, 25);
			this->label1->Name = L"label1";
			this->label1->Size = System::Drawing::Size(57, 13);
			this->label1->TabIndex = 0;
			this->label1->Text = L"Название";
			// 
			// label2
			// 
			this->label2->AutoSize = true;
			this->label2->Location = System::Drawing::Point(15, 75);
			this->label2->Name = L"label2";
			this->label2->Size = System::Drawing::Size(66, 13);
			this->label2->TabIndex = 1;
			this->label2->Text = L"Количество";
			// 
			// label3
			// 
			this->label3->AutoSize = true;
			this->label3->Location = System::Drawing::Point(18, 125);
			this->label3->Name = L"label3";
			this->label3->Size = System::Drawing::Size(59, 13);
			this->label3->TabIndex = 2;
			this->label3->Text = L"Животное";
			// 
			// comboBox_Animal
			// 
			this->comboBox_Animal->FormattingEnabled = true;
			this->comboBox_Animal->Location = System::Drawing::Point(15, 140);
			this->comboBox_Animal->Name = L"comboBox_Animal";
			this->comboBox_Animal->Size = System::Drawing::Size(200, 21);
			this->comboBox_Animal->TabIndex = 3;
			// 
			// textBox_Title
			// 
			this->textBox_Title->Location = System::Drawing::Point(15, 40);
			this->textBox_Title->Name = L"textBox_Title";
			this->textBox_Title->Size = System::Drawing::Size(200, 20);
			this->textBox_Title->TabIndex = 4;
			// 
			// textBox_Qty
			// 
			this->textBox_Qty->Location = System::Drawing::Point(15, 90);
			this->textBox_Qty->Name = L"textBox_Qty";
			this->textBox_Qty->Size = System::Drawing::Size(200, 20);
			this->textBox_Qty->TabIndex = 5;
			// 
			// button_Add
			// 
			this->button_Add->Location = System::Drawing::Point(234, 87);
			this->button_Add->Name = L"button_Add";
			this->button_Add->Size = System::Drawing::Size(75, 23);
			this->button_Add->TabIndex = 6;
			this->button_Add->Text = L"Добавить";
			this->button_Add->UseVisualStyleBackColor = true;
			this->button_Add->Click += gcnew System::EventHandler(this, &Add_Food_Form::button_Add_Click);
			// 
			// label4
			// 
			this->label4->AutoSize = true;
			this->label4->Location = System::Drawing::Point(80, 46);
			this->label4->Name = L"label4";
			this->label4->Size = System::Drawing::Size(35, 13);
			this->label4->TabIndex = 7;
			this->label4->Text = L"label4";
			// 
			// Add_Food_Form
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(321, 183);
			this->Controls->Add(this->button_Add);
			this->Controls->Add(this->textBox_Qty);
			this->Controls->Add(this->textBox_Title);
			this->Controls->Add(this->comboBox_Animal);
			this->Controls->Add(this->label3);
			this->Controls->Add(this->label2);
			this->Controls->Add(this->label1);
			this->Controls->Add(this->label4);
			this->Name = L"Add_Food_Form";
			this->Text = L"Add_Food_Form";
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion
private: System::Void button_Add_Click(System::Object^ sender, System::EventArgs^ e);
};
}
