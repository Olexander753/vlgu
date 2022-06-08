#pragma once

namespace Zoo {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;

	/// <summary>
	/// Сводка для Add_Animal_Form
	/// </summary>
	public ref class Add_Animal_Form : public System::Windows::Forms::Form
	{
	public:
		Add_Animal_Form(void)
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
		~Add_Animal_Form()
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
	private: System::Windows::Forms::TextBox^ textBox_Name;
	private: System::Windows::Forms::TextBox^ textBox_View;
	private: System::Windows::Forms::TextBox^ textBox_Status_Feeding;
	private: System::Windows::Forms::TextBox^ textBox_Status_helth;






	private: System::Windows::Forms::Button^ button1;
	public: System::Windows::Forms::Label^ label5;
	public: System::Windows::Forms::Label^ label6;
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
			this->label1 = (gcnew System::Windows::Forms::Label());
			this->label2 = (gcnew System::Windows::Forms::Label());
			this->label3 = (gcnew System::Windows::Forms::Label());
			this->label4 = (gcnew System::Windows::Forms::Label());
			this->textBox_Name = (gcnew System::Windows::Forms::TextBox());
			this->textBox_View = (gcnew System::Windows::Forms::TextBox());
			this->textBox_Status_Feeding = (gcnew System::Windows::Forms::TextBox());
			this->textBox_Status_helth = (gcnew System::Windows::Forms::TextBox());
			this->button1 = (gcnew System::Windows::Forms::Button());
			this->label5 = (gcnew System::Windows::Forms::Label());
			this->label6 = (gcnew System::Windows::Forms::Label());
			this->SuspendLayout();
			// 
			// label1
			// 
			this->label1->AutoSize = true;
			this->label1->Location = System::Drawing::Point(15, 15);
			this->label1->Name = L"label1";
			this->label1->Size = System::Drawing::Size(29, 13);
			this->label1->TabIndex = 0;
			this->label1->Text = L"Имя";
			// 
			// label2
			// 
			this->label2->AutoSize = true;
			this->label2->Location = System::Drawing::Point(15, 65);
			this->label2->Name = L"label2";
			this->label2->Size = System::Drawing::Size(26, 13);
			this->label2->TabIndex = 1;
			this->label2->Text = L"Вид";
			// 
			// label3
			// 
			this->label3->AutoSize = true;
			this->label3->Location = System::Drawing::Point(145, 15);
			this->label3->Name = L"label3";
			this->label3->Size = System::Drawing::Size(100, 13);
			this->label3->TabIndex = 2;
			this->label3->Text = L"Статус кормления";
			// 
			// label4
			// 
			this->label4->AutoSize = true;
			this->label4->Location = System::Drawing::Point(145, 65);
			this->label4->Name = L"label4";
			this->label4->Size = System::Drawing::Size(92, 13);
			this->label4->TabIndex = 3;
			this->label4->Text = L"Статус здоровья";
			// 
			// textBox_Name
			// 
			this->textBox_Name->Location = System::Drawing::Point(18, 32);
			this->textBox_Name->Name = L"textBox_Name";
			this->textBox_Name->Size = System::Drawing::Size(121, 20);
			this->textBox_Name->TabIndex = 6;
			// 
			// textBox_View
			// 
			this->textBox_View->Location = System::Drawing::Point(18, 81);
			this->textBox_View->Name = L"textBox_View";
			this->textBox_View->Size = System::Drawing::Size(121, 20);
			this->textBox_View->TabIndex = 7;
			// 
			// textBox_Status_Feeding
			// 
			this->textBox_Status_Feeding->Location = System::Drawing::Point(148, 32);
			this->textBox_Status_Feeding->Name = L"textBox_Status_Feeding";
			this->textBox_Status_Feeding->Size = System::Drawing::Size(121, 20);
			this->textBox_Status_Feeding->TabIndex = 8;
			// 
			// textBox_Status_helth
			// 
			this->textBox_Status_helth->Location = System::Drawing::Point(148, 81);
			this->textBox_Status_helth->Name = L"textBox_Status_helth";
			this->textBox_Status_helth->Size = System::Drawing::Size(121, 20);
			this->textBox_Status_helth->TabIndex = 9;
			// 
			// button1
			// 
			this->button1->Location = System::Drawing::Point(108, 135);
			this->button1->Name = L"button1";
			this->button1->Size = System::Drawing::Size(75, 23);
			this->button1->TabIndex = 10;
			this->button1->Text = L"Добавить";
			this->button1->UseVisualStyleBackColor = true;
			this->button1->Click += gcnew System::EventHandler(this, &Add_Animal_Form::button1_Click);
			// 
			// label5
			// 
			this->label5->AutoSize = true;
			this->label5->Location = System::Drawing::Point(54, 38);
			this->label5->Name = L"label5";
			this->label5->Size = System::Drawing::Size(35, 13);
			this->label5->TabIndex = 11;
			this->label5->Text = L"label5";
			// 
			// label6
			// 
			this->label6->AutoSize = true;
			this->label6->Location = System::Drawing::Point(193, 38);
			this->label6->Name = L"label6";
			this->label6->Size = System::Drawing::Size(35, 13);
			this->label6->TabIndex = 12;
			this->label6->Text = L"label6";
			// 
			// Add_Animal_Form
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(293, 170);
			this->Controls->Add(this->button1);
			this->Controls->Add(this->textBox_Status_helth);
			this->Controls->Add(this->textBox_Status_Feeding);
			this->Controls->Add(this->textBox_View);
			this->Controls->Add(this->textBox_Name);
			this->Controls->Add(this->label4);
			this->Controls->Add(this->label3);
			this->Controls->Add(this->label2);
			this->Controls->Add(this->label1);
			this->Controls->Add(this->label5);
			this->Controls->Add(this->label6);
			this->Name = L"Add_Animal_Form";
			this->Text = L"Add_Animal_Form";
			this->FormClosed += gcnew System::Windows::Forms::FormClosedEventHandler(this, &Add_Animal_Form::Add_Animal_Form_FormClosed);
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion
private: System::Void button1_Click(System::Object^ sender, System::EventArgs^ e);
private: System::Void Add_Animal_Form_FormClosed(System::Object^ sender, System::Windows::Forms::FormClosedEventArgs^ e);
};
}
