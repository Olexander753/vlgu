#pragma once

namespace Zoo {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;

	/// <summary>
	/// Сводка для Menu_Visitor_Form
	/// </summary>
	public ref class Menu_Visitor_Form : public System::Windows::Forms::Form
	{
	public:
		Menu_Visitor_Form(void)
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
		~Menu_Visitor_Form()
		{
			if (components)
			{
				delete components;
			}
		}
	public: System::Windows::Forms::DataGridView^ dataGridView1;
	protected:
	private: System::Windows::Forms::DataGridViewTextBoxColumn^ Title;
	private: System::Windows::Forms::DataGridViewTextBoxColumn^ Address;
	private: System::Windows::Forms::DataGridViewTextBoxColumn^ Square;
	private: System::Windows::Forms::DataGridViewTextBoxColumn^ Job_ststus;

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
			this->dataGridView1 = (gcnew System::Windows::Forms::DataGridView());
			this->Title = (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
			this->Address = (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
			this->Square = (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
			this->Job_ststus = (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->dataGridView1))->BeginInit();
			this->SuspendLayout();
			// 
			// dataGridView1
			// 
			this->dataGridView1->ColumnHeadersHeightSizeMode = System::Windows::Forms::DataGridViewColumnHeadersHeightSizeMode::AutoSize;
			this->dataGridView1->Columns->AddRange(gcnew cli::array< System::Windows::Forms::DataGridViewColumn^  >(4) {
				this->Title,
					this->Address, this->Square, this->Job_ststus
			});
			this->dataGridView1->Location = System::Drawing::Point(15, 15);
			this->dataGridView1->Name = L"dataGridView1";
			this->dataGridView1->Size = System::Drawing::Size(460, 235);
			this->dataGridView1->TabIndex = 0;
			// 
			// Title
			// 
			this->Title->HeaderText = L"Название";
			this->Title->Name = L"Title";
			this->Title->ReadOnly = true;
			// 
			// Address
			// 
			this->Address->HeaderText = L"Адрес";
			this->Address->Name = L"Address";
			this->Address->ReadOnly = true;
			// 
			// Square
			// 
			this->Square->HeaderText = L"Площадь";
			this->Square->Name = L"Square";
			this->Square->ReadOnly = true;
			// 
			// Job_ststus
			// 
			this->Job_ststus->HeaderText = L"Статус работы";
			this->Job_ststus->Name = L"Job_ststus";
			this->Job_ststus->ReadOnly = true;
			// 
			// Menu_Visitor_Form
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(489, 261);
			this->Controls->Add(this->dataGridView1);
			this->Name = L"Menu_Visitor_Form";
			this->Text = L"Menu_Visitor_Form";
			this->FormClosed += gcnew System::Windows::Forms::FormClosedEventHandler(this, &Menu_Visitor_Form::Menu_Visitor_Form_FormClosed);
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->dataGridView1))->EndInit();
			this->ResumeLayout(false);

		}
#pragma endregion
private: System::Void Menu_Visitor_Form_FormClosed(System::Object^ sender, System::Windows::Forms::FormClosedEventArgs^ e);
};
}
