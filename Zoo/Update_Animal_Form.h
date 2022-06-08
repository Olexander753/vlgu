#pragma once

namespace Zoo {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;

	/// <summary>
	/// Сводка для Update_Animal_Form
	/// </summary>
	public ref class Update_Animal_Form : public System::Windows::Forms::Form
	{
	public:
		Update_Animal_Form(void)
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
		~Update_Animal_Form()
		{
			if (components)
			{
				delete components;
			}
		}
	private: System::Windows::Forms::Button^ button1;
	protected:
	public: System::Windows::Forms::TextBox^ textBox_Status_helth;
	public: System::Windows::Forms::TextBox^ textBox_Status_Feeding;
	public: System::Windows::Forms::TextBox^ textBox_View;
	public: System::Windows::Forms::TextBox^ textBox_Name;
	private: System::Windows::Forms::Label^ label4;
	private: System::Windows::Forms::Label^ label3;
	private: System::Windows::Forms::Label^ label2;
	private: System::Windows::Forms::Label^ label1;
	public: System::Windows::Forms::Label^ label5;
	private:
	public: System::Windows::Forms::Label^ label6;

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
			this->button1 = (gcnew System::Windows::Forms::Button());
			this->textBox_Status_helth = (gcnew System::Windows::Forms::TextBox());
			this->textBox_Status_Feeding = (gcnew System::Windows::Forms::TextBox());
			this->textBox_View = (gcnew System::Windows::Forms::TextBox());
			this->textBox_Name = (gcnew System::Windows::Forms::TextBox());
			this->label4 = (gcnew System::Windows::Forms::Label());
			this->label3 = (gcnew System::Windows::Forms::Label());
			this->label2 = (gcnew System::Windows::Forms::Label());
			this->label1 = (gcnew System::Windows::Forms::Label());
			this->label5 = (gcnew System::Windows::Forms::Label());
			this->label6 = (gcnew System::Windows::Forms::Label());
			this->SuspendLayout();
			// 
			// button1
			// 
			this->button1->Location = System::Drawing::Point(105, 141);
			this->button1->Name = L"button1";
			this->button1->Size = System::Drawing::Size(75, 23);
			this->button1->TabIndex = 21;
			this->button1->Text = L"Добавить";
			this->button1->UseVisualStyleBackColor = true;
			this->button1->Click += gcnew System::EventHandler(this, &Update_Animal_Form::button1_Click);
			// 
			// textBox_Status_helth
			// 
			this->textBox_Status_helth->Location = System::Drawing::Point(145, 87);
			this->textBox_Status_helth->Name = L"textBox_Status_helth";
			this->textBox_Status_helth->Size = System::Drawing::Size(121, 20);
			this->textBox_Status_helth->TabIndex = 20;
			// 
			// textBox_Status_Feeding
			// 
			this->textBox_Status_Feeding->Location = System::Drawing::Point(145, 38);
			this->textBox_Status_Feeding->Name = L"textBox_Status_Feeding";
			this->textBox_Status_Feeding->Size = System::Drawing::Size(121, 20);
			this->textBox_Status_Feeding->TabIndex = 19;
			// 
			// textBox_View
			// 
			this->textBox_View->Location = System::Drawing::Point(15, 87);
			this->textBox_View->Name = L"textBox_View";
			this->textBox_View->Size = System::Drawing::Size(121, 20);
			this->textBox_View->TabIndex = 18;
			// 
			// textBox_Name
			// 
			this->textBox_Name->Location = System::Drawing::Point(15, 38);
			this->textBox_Name->Name = L"textBox_Name";
			this->textBox_Name->Size = System::Drawing::Size(121, 20);
			this->textBox_Name->TabIndex = 17;
			// 
			// label4
			// 
			this->label4->AutoSize = true;
			this->label4->Location = System::Drawing::Point(142, 71);
			this->label4->Name = L"label4";
			this->label4->Size = System::Drawing::Size(92, 13);
			this->label4->TabIndex = 16;
			this->label4->Text = L"Статус здоровья";
			// 
			// label3
			// 
			this->label3->AutoSize = true;
			this->label3->Location = System::Drawing::Point(142, 21);
			this->label3->Name = L"label3";
			this->label3->Size = System::Drawing::Size(100, 13);
			this->label3->TabIndex = 15;
			this->label3->Text = L"Статус кормления";
			// 
			// label2
			// 
			this->label2->AutoSize = true;
			this->label2->Location = System::Drawing::Point(12, 71);
			this->label2->Name = L"label2";
			this->label2->Size = System::Drawing::Size(26, 13);
			this->label2->TabIndex = 14;
			this->label2->Text = L"Вид";
			// 
			// label1
			// 
			this->label1->AutoSize = true;
			this->label1->Location = System::Drawing::Point(12, 21);
			this->label1->Name = L"label1";
			this->label1->Size = System::Drawing::Size(29, 13);
			this->label1->TabIndex = 13;
			this->label1->Text = L"Имя";
			// 
			// label5
			// 
			this->label5->AutoSize = true;
			this->label5->Location = System::Drawing::Point(51, 44);
			this->label5->Name = L"label5";
			this->label5->Size = System::Drawing::Size(35, 13);
			this->label5->TabIndex = 22;
			this->label5->Text = L"label5";
			// 
			// label6
			// 
			this->label6->AutoSize = true;
			this->label6->Location = System::Drawing::Point(190, 44);
			this->label6->Name = L"label6";
			this->label6->Size = System::Drawing::Size(35, 13);
			this->label6->TabIndex = 23;
			this->label6->Text = L"label6";
			// 
			// Update_Animal_Form
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(284, 178);
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
			this->Name = L"Update_Animal_Form";
			this->Text = L"Update_Animal_Form";
			this->FormClosed += gcnew System::Windows::Forms::FormClosedEventHandler(this, &Update_Animal_Form::Update_Animal_Form_FormClosed);
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion
private: System::Void button1_Click(System::Object^ sender, System::EventArgs^ e);
private: System::Void Update_Animal_Form_FormClosed(System::Object^ sender, System::Windows::Forms::FormClosedEventArgs^ e);
};
}
