#pragma once

namespace Zoo {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;

	/// <summary>
	/// Сводка для Menu_Employee_Form
	/// </summary>
	public ref class Menu_Employee_Form : public System::Windows::Forms::Form
	{
	public:
		Menu_Employee_Form(void)
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
		~Menu_Employee_Form()
		{
			if (components)
			{
				delete components;
			}
		}
	public: System::Windows::Forms::DataGridView^ dataGridView1;
	protected:
	private: System::Windows::Forms::DataGridViewTextBoxColumn^ ID;
	private: System::Windows::Forms::DataGridViewTextBoxColumn^ Name;
	private: System::Windows::Forms::DataGridViewTextBoxColumn^ View;
	private: System::Windows::Forms::DataGridViewTextBoxColumn^ Feeding_status;
	private: System::Windows::Forms::DataGridViewTextBoxColumn^ Health_status;
	public: System::Windows::Forms::Label^ label2;
	private: System::Windows::Forms::Label^ label1;
	private: System::Windows::Forms::Button^ button_Treat;
	private: System::Windows::Forms::Button^ button_Feed;
	private: System::Windows::Forms::Button^ button_Delete;
	private: System::Windows::Forms::Button^ button_Update;
	private: System::Windows::Forms::Button^ button_Add;
	private: System::Windows::Forms::Button^ button1;
	private: System::Windows::Forms::MenuStrip^ menuStrip1;
	private: System::Windows::Forms::ToolStripMenuItem^ обновитьToolStripMenuItem;

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
			this->ID = (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
			this->Name = (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
			this->View = (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
			this->Feeding_status = (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
			this->Health_status = (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
			this->label2 = (gcnew System::Windows::Forms::Label());
			this->label1 = (gcnew System::Windows::Forms::Label());
			this->button_Treat = (gcnew System::Windows::Forms::Button());
			this->button_Feed = (gcnew System::Windows::Forms::Button());
			this->button_Delete = (gcnew System::Windows::Forms::Button());
			this->button_Update = (gcnew System::Windows::Forms::Button());
			this->button_Add = (gcnew System::Windows::Forms::Button());
			this->button1 = (gcnew System::Windows::Forms::Button());
			this->menuStrip1 = (gcnew System::Windows::Forms::MenuStrip());
			this->обновитьToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->dataGridView1))->BeginInit();
			this->menuStrip1->SuspendLayout();
			this->SuspendLayout();
			// 
			// dataGridView1
			// 
			this->dataGridView1->ColumnHeadersHeightSizeMode = System::Windows::Forms::DataGridViewColumnHeadersHeightSizeMode::AutoSize;
			this->dataGridView1->Columns->AddRange(gcnew cli::array< System::Windows::Forms::DataGridViewColumn^  >(5) {
				this->ID, this->Name,
					this->View, this->Feeding_status, this->Health_status
			});
			this->dataGridView1->Location = System::Drawing::Point(13, 60);
			this->dataGridView1->Name = L"dataGridView1";
			this->dataGridView1->Size = System::Drawing::Size(554, 225);
			this->dataGridView1->TabIndex = 10;
			// 
			// ID
			// 
			this->ID->HeaderText = L"ID";
			this->ID->Name = L"ID";
			// 
			// Name
			// 
			this->Name->HeaderText = L"Имя";
			this->Name->Name = L"Name";
			// 
			// View
			// 
			this->View->HeaderText = L"Вид";
			this->View->Name = L"View";
			// 
			// Feeding_status
			// 
			this->Feeding_status->HeaderText = L"Статус кормления";
			this->Feeding_status->Name = L"Feeding_status";
			// 
			// Health_status
			// 
			this->Health_status->HeaderText = L"Статус здоровья";
			this->Health_status->Name = L"Health_status";
			// 
			// label2
			// 
			this->label2->AutoSize = true;
			this->label2->Location = System::Drawing::Point(80, 39);
			this->label2->Name = L"label2";
			this->label2->Size = System::Drawing::Size(35, 13);
			this->label2->TabIndex = 9;
			this->label2->Text = L"label2";
			// 
			// label1
			// 
			this->label1->AutoSize = true;
			this->label1->Location = System::Drawing::Point(10, 39);
			this->label1->Name = L"label1";
			this->label1->Size = System::Drawing::Size(74, 13);
			this->label1->TabIndex = 8;
			this->label1->Text = L"Сотрудник №";
			// 
			// button_Treat
			// 
			this->button_Treat->Location = System::Drawing::Point(754, 177);
			this->button_Treat->Name = L"button_Treat";
			this->button_Treat->Size = System::Drawing::Size(150, 35);
			this->button_Treat->TabIndex = 15;
			this->button_Treat->Text = L"Изменить статус здоровья";
			this->button_Treat->UseVisualStyleBackColor = true;
			this->button_Treat->Click += gcnew System::EventHandler(this, &Menu_Employee_Form::button_Treat_Click);
			// 
			// button_Feed
			// 
			this->button_Feed->Location = System::Drawing::Point(754, 54);
			this->button_Feed->Name = L"button_Feed";
			this->button_Feed->Size = System::Drawing::Size(150, 35);
			this->button_Feed->TabIndex = 14;
			this->button_Feed->Text = L"Покормить животного";
			this->button_Feed->UseVisualStyleBackColor = true;
			this->button_Feed->Click += gcnew System::EventHandler(this, &Menu_Employee_Form::button_Feed_Click);
			// 
			// button_Delete
			// 
			this->button_Delete->Location = System::Drawing::Point(583, 177);
			this->button_Delete->Name = L"button_Delete";
			this->button_Delete->Size = System::Drawing::Size(150, 35);
			this->button_Delete->TabIndex = 13;
			this->button_Delete->Text = L"Удалить животного";
			this->button_Delete->UseVisualStyleBackColor = true;
			this->button_Delete->Click += gcnew System::EventHandler(this, &Menu_Employee_Form::button_Delete_Click);
			// 
			// button_Update
			// 
			this->button_Update->Location = System::Drawing::Point(583, 117);
			this->button_Update->Name = L"button_Update";
			this->button_Update->Size = System::Drawing::Size(150, 35);
			this->button_Update->TabIndex = 12;
			this->button_Update->Text = L"Изменить данные";
			this->button_Update->UseVisualStyleBackColor = true;
			this->button_Update->Click += gcnew System::EventHandler(this, &Menu_Employee_Form::button_Update_Click);
			// 
			// button_Add
			// 
			this->button_Add->Location = System::Drawing::Point(583, 55);
			this->button_Add->Name = L"button_Add";
			this->button_Add->Size = System::Drawing::Size(150, 35);
			this->button_Add->TabIndex = 11;
			this->button_Add->Text = L"Добавить животное";
			this->button_Add->UseVisualStyleBackColor = true;
			this->button_Add->Click += gcnew System::EventHandler(this, &Menu_Employee_Form::button_Add_Click);
			// 
			// button1
			// 
			this->button1->Location = System::Drawing::Point(754, 117);
			this->button1->Name = L"button1";
			this->button1->Size = System::Drawing::Size(150, 35);
			this->button1->TabIndex = 16;
			this->button1->Text = L"Изменить статус кормления на \"Голоден\"";
			this->button1->UseVisualStyleBackColor = true;
			this->button1->Click += gcnew System::EventHandler(this, &Menu_Employee_Form::button1_Click);
			// 
			// menuStrip1
			// 
			this->menuStrip1->BackColor = System::Drawing::SystemColors::GradientActiveCaption;
			this->menuStrip1->Items->AddRange(gcnew cli::array< System::Windows::Forms::ToolStripItem^  >(1) { this->обновитьToolStripMenuItem });
			this->menuStrip1->Location = System::Drawing::Point(0, 0);
			this->menuStrip1->Name = L"menuStrip1";
			this->menuStrip1->Size = System::Drawing::Size(926, 24);
			this->menuStrip1->TabIndex = 17;
			this->menuStrip1->Text = L"menuStrip1";
			// 
			// обновитьToolStripMenuItem
			// 
			this->обновитьToolStripMenuItem->Name = L"обновитьToolStripMenuItem";
			this->обновитьToolStripMenuItem->Size = System::Drawing::Size(73, 20);
			this->обновитьToolStripMenuItem->Text = L"Обновить";
			this->обновитьToolStripMenuItem->Click += gcnew System::EventHandler(this, &Menu_Employee_Form::обновитьToolStripMenuItem_Click);
			// 
			// Menu_Employee_Form
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(926, 297);
			this->Controls->Add(this->button1);
			this->Controls->Add(this->dataGridView1);
			this->Controls->Add(this->label2);
			this->Controls->Add(this->label1);
			this->Controls->Add(this->button_Treat);
			this->Controls->Add(this->button_Feed);
			this->Controls->Add(this->button_Delete);
			this->Controls->Add(this->button_Update);
			this->Controls->Add(this->button_Add);
			this->Controls->Add(this->menuStrip1);
			this->MainMenuStrip = this->menuStrip1;
			//this->Name = L"Menu_Employee_Form";
			this->Text = L"Menu_Employee_Form";
			this->FormClosed += gcnew System::Windows::Forms::FormClosedEventHandler(this, &Menu_Employee_Form::Menu_Employee_Form_FormClosed);
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->dataGridView1))->EndInit();
			this->menuStrip1->ResumeLayout(false);
			this->menuStrip1->PerformLayout();
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion
private: System::Void button_Add_Click(System::Object^ sender, System::EventArgs^ e);
private: System::Void button_Update_Click(System::Object^ sender, System::EventArgs^ e);
private: System::Void button_Delete_Click(System::Object^ sender, System::EventArgs^ e);
private: System::Void button_Feed_Click(System::Object^ sender, System::EventArgs^ e);
private: System::Void button_Treat_Click(System::Object^ sender, System::EventArgs^ e);
private: System::Void Menu_Employee_Form_FormClosed(System::Object^ sender, System::Windows::Forms::FormClosedEventArgs^ e);
private: System::Void button1_Click(System::Object^ sender, System::EventArgs^ e);
private: System::Void обновитьToolStripMenuItem_Click(System::Object^ sender, System::EventArgs^ e);
};
}
