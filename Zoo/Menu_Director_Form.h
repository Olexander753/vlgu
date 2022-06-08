#pragma once
#include "Connection.h"
//#include "Zoopark.h"
#include "Menu_Zoo_Form.h"

namespace Zoo {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;

	/// <summary>
	/// Сводка для Menu_Director_Form
	/// </summary>
	public ref class Menu_Director_Form : public System::Windows::Forms::Form
	{
	public:
		Menu_Director_Form(void)
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
		~Menu_Director_Form()
		{
			if (components)
			{
				delete components;
			}
		}

	protected:

	protected:








	private: System::Windows::Forms::Label^ label2;
	public: System::Windows::Forms::DataGridView^ dataGridView_Zoo;





	private: System::Windows::Forms::GroupBox^ groupBox2;
















	private: System::Windows::Forms::Button^ button_Exit;

	private: System::Windows::Forms::Button^ button_Open;









	private: System::Windows::Forms::MenuStrip^ menuStrip1;
	private: System::Windows::Forms::ToolStripMenuItem^ обновитьToolStripMenuItem;
	private: System::Windows::Forms::Button^ button_Enter;
	private: System::Windows::Forms::DataGridViewTextBoxColumn^ ID;
	private: System::Windows::Forms::DataGridViewTextBoxColumn^ Title;
	private: System::Windows::Forms::DataGridViewTextBoxColumn^ Square_;
	private: System::Windows::Forms::DataGridViewTextBoxColumn^ Address;
	private: System::Windows::Forms::DataGridViewTextBoxColumn^ Job_status;
	public: System::Windows::Forms::Label^ label1;







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
			this->label2 = (gcnew System::Windows::Forms::Label());
			this->dataGridView_Zoo = (gcnew System::Windows::Forms::DataGridView());
			this->ID = (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
			this->Title = (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
			this->Square_ = (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
			this->Address = (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
			this->Job_status = (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
			this->groupBox2 = (gcnew System::Windows::Forms::GroupBox());
			this->button_Enter = (gcnew System::Windows::Forms::Button());
			this->button_Exit = (gcnew System::Windows::Forms::Button());
			this->button_Open = (gcnew System::Windows::Forms::Button());
			this->menuStrip1 = (gcnew System::Windows::Forms::MenuStrip());
			this->обновитьToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->label1 = (gcnew System::Windows::Forms::Label());
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->dataGridView_Zoo))->BeginInit();
			this->groupBox2->SuspendLayout();
			this->menuStrip1->SuspendLayout();
			this->SuspendLayout();
			// 
			// label2
			// 
			this->label2->AutoSize = true;
			this->label2->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 14.25F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->label2->Location = System::Drawing::Point(15, 30);
			this->label2->Name = L"label2";
			this->label2->Size = System::Drawing::Size(97, 24);
			this->label2->TabIndex = 3;
			this->label2->Text = L"Зоопарки";
			// 
			// dataGridView_Zoo
			// 
			this->dataGridView_Zoo->ColumnHeadersHeightSizeMode = System::Windows::Forms::DataGridViewColumnHeadersHeightSizeMode::AutoSize;
			this->dataGridView_Zoo->Columns->AddRange(gcnew cli::array< System::Windows::Forms::DataGridViewColumn^  >(5) {
				this->ID,
					this->Title, this->Square_, this->Address, this->Job_status
			});
			this->dataGridView_Zoo->Location = System::Drawing::Point(15, 55);
			this->dataGridView_Zoo->Name = L"dataGridView_Zoo";
			this->dataGridView_Zoo->Size = System::Drawing::Size(565, 234);
			this->dataGridView_Zoo->TabIndex = 4;
			// 
			// ID
			// 
			this->ID->HeaderText = L"ID";
			this->ID->Name = L"ID";
			// 
			// Title
			// 
			this->Title->HeaderText = L"Название";
			this->Title->Name = L"Title";
			// 
			// Square_
			// 
			this->Square_->HeaderText = L"Площадь";
			this->Square_->Name = L"Square_";
			// 
			// Address
			// 
			this->Address->HeaderText = L"Адрес";
			this->Address->Name = L"Address";
			// 
			// Job_status
			// 
			this->Job_status->HeaderText = L"Статус работы";
			this->Job_status->Name = L"Job_status";
			// 
			// groupBox2
			// 
			this->groupBox2->Controls->Add(this->button_Enter);
			this->groupBox2->Controls->Add(this->button_Exit);
			this->groupBox2->Controls->Add(this->button_Open);
			this->groupBox2->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->groupBox2->Location = System::Drawing::Point(595, 55);
			this->groupBox2->Name = L"groupBox2";
			this->groupBox2->Size = System::Drawing::Size(200, 234);
			this->groupBox2->TabIndex = 3;
			this->groupBox2->TabStop = false;
			this->groupBox2->Text = L"Управление зоопарками";
			// 
			// button_Enter
			// 
			this->button_Enter->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 11.25F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->button_Enter->Location = System::Drawing::Point(20, 65);
			this->button_Enter->Name = L"button_Enter";
			this->button_Enter->Size = System::Drawing::Size(160, 25);
			this->button_Enter->TabIndex = 2;
			this->button_Enter->Text = L"Подробнее";
			this->button_Enter->UseVisualStyleBackColor = true;
			this->button_Enter->Click += gcnew System::EventHandler(this, &Menu_Director_Form::button_Enter_Click);
			// 
			// button_Exit
			// 
			this->button_Exit->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 11.25F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->button_Exit->Location = System::Drawing::Point(20, 190);
			this->button_Exit->Name = L"button_Exit";
			this->button_Exit->Size = System::Drawing::Size(160, 25);
			this->button_Exit->TabIndex = 1;
			this->button_Exit->Text = L"Закрыть";
			this->button_Exit->UseVisualStyleBackColor = true;
			this->button_Exit->Click += gcnew System::EventHandler(this, &Menu_Director_Form::button_Exit_Click);
			// 
			// button_Open
			// 
			this->button_Open->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 11.25F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->button_Open->Location = System::Drawing::Point(20, 129);
			this->button_Open->Name = L"button_Open";
			this->button_Open->Size = System::Drawing::Size(160, 25);
			this->button_Open->TabIndex = 0;
			this->button_Open->Text = L"Открыть";
			this->button_Open->UseVisualStyleBackColor = true;
			this->button_Open->Click += gcnew System::EventHandler(this, &Menu_Director_Form::button_Open_Click);
			// 
			// menuStrip1
			// 
			this->menuStrip1->BackColor = System::Drawing::SystemColors::GradientInactiveCaption;
			this->menuStrip1->Items->AddRange(gcnew cli::array< System::Windows::Forms::ToolStripItem^  >(1) { this->обновитьToolStripMenuItem });
			this->menuStrip1->Location = System::Drawing::Point(0, 0);
			this->menuStrip1->Name = L"menuStrip1";
			this->menuStrip1->Size = System::Drawing::Size(809, 24);
			this->menuStrip1->TabIndex = 7;
			this->menuStrip1->Text = L"menuStrip1";
			// 
			// обновитьToolStripMenuItem
			// 
			this->обновитьToolStripMenuItem->Name = L"обновитьToolStripMenuItem";
			this->обновитьToolStripMenuItem->Size = System::Drawing::Size(73, 20);
			this->обновитьToolStripMenuItem->Text = L"Обновить";
			this->обновитьToolStripMenuItem->Click += gcnew System::EventHandler(this, &Menu_Director_Form::обновитьToolStripMenuItem_Click);
			// 
			// label1
			// 
			this->label1->AutoSize = true;
			this->label1->Location = System::Drawing::Point(257, 164);
			this->label1->Name = L"label1";
			this->label1->Size = System::Drawing::Size(35, 13);
			this->label1->TabIndex = 8;
			this->label1->Text = L"label1";
			// 
			// Menu_Director_Form
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(809, 311);
			this->Controls->Add(this->groupBox2);
			this->Controls->Add(this->dataGridView_Zoo);
			this->Controls->Add(this->label2);
			this->Controls->Add(this->menuStrip1);
			this->Controls->Add(this->label1);
			this->MainMenuStrip = this->menuStrip1;
			this->Name = L"Menu_Director_Form";
			this->Text = L"Menu_Director_Form";
			this->FormClosed += gcnew System::Windows::Forms::FormClosedEventHandler(this, &Menu_Director_Form::Menu_Director_Form_FormClosed);
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->dataGridView_Zoo))->EndInit();
			this->groupBox2->ResumeLayout(false);
			this->menuStrip1->ResumeLayout(false);
			this->menuStrip1->PerformLayout();
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion
private: System::Void обновитьToolStripMenuItem_Click(System::Object^ sender, System::EventArgs^ e);
private: System::Void button_Enter_Click(System::Object^ sender, System::EventArgs^ e);
private: System::Void button_Open_Click(System::Object^ sender, System::EventArgs^ e);
private: System::Void button_Exit_Click(System::Object^ sender, System::EventArgs^ e);
private: System::Void Menu_Director_Form_FormClosed(System::Object^ sender, System::Windows::Forms::FormClosedEventArgs^ e);
};
}
