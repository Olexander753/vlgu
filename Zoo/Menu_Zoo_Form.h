#pragma once
#include "Employee.h"
#include "Connection.h"
#include "Zoopark.h"
#include "Food.h"
#include "Add_Employee_Form.h"
#include "Update_Employee_Form.h"
#include "Add_Food_Form.h"

namespace Zoo {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;

	/// <summary>
	/// Сводка для Menu_Zoo_Form
	/// </summary>
	public ref class Menu_Zoo_Form : public System::Windows::Forms::Form
	{
	public:
		Menu_Zoo_Form(void)
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
		~Menu_Zoo_Form()
		{
			if (components)
			{
				delete components;
			}
		}
	private: System::Windows::Forms::GroupBox^ groupBox1;
	protected:
	private: System::Windows::Forms::Button^ button_Delete_Employee;
	private: System::Windows::Forms::Button^ button_Update;
	private: System::Windows::Forms::Button^ button_Add_Employee;
	private: System::Windows::Forms::Label^ label1;
	public: System::Windows::Forms::DataGridView^ dataGridView_Employee;
	private:
	private: System::Windows::Forms::DataGridViewTextBoxColumn^ Service_number;
	public:
	private: System::Windows::Forms::DataGridViewTextBoxColumn^ Full_name;
	private: System::Windows::Forms::DataGridViewTextBoxColumn^ Passport_data;
	private: System::Windows::Forms::DataGridViewTextBoxColumn^ Login;
	private: System::Windows::Forms::DataGridViewTextBoxColumn^ Password;
	private: System::Windows::Forms::GroupBox^ groupBox3;
	private: System::Windows::Forms::Button^ button_write_off;
	private: System::Windows::Forms::Button^ button_Add_food;
	public: System::Windows::Forms::DataGridView^ dataGridView_Food;
	private:

	public:



	private: System::Windows::Forms::Label^ label3;
	private: System::Windows::Forms::ToolStripMenuItem^ обновитьToolStripMenuItem;
	private: System::Windows::Forms::ToolStripMenuItem^ назадToolStripMenuItem;
	private: System::Windows::Forms::MenuStrip^ menuStrip1;
	private: System::Windows::Forms::DataGridViewTextBoxColumn^ ID;
	private: System::Windows::Forms::DataGridViewTextBoxColumn^ Title_food;
	private: System::Windows::Forms::DataGridViewTextBoxColumn^ Qty;
	public: System::Windows::Forms::Label^ label_Zoo_ID;
	private: System::Windows::Forms::Button^ button_Edit;
	private: System::Windows::Forms::Label^ label2;
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
			this->groupBox1 = (gcnew System::Windows::Forms::GroupBox());
			this->button_Delete_Employee = (gcnew System::Windows::Forms::Button());
			this->button_Update = (gcnew System::Windows::Forms::Button());
			this->button_Add_Employee = (gcnew System::Windows::Forms::Button());
			this->label1 = (gcnew System::Windows::Forms::Label());
			this->dataGridView_Employee = (gcnew System::Windows::Forms::DataGridView());
			this->Service_number = (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
			this->Full_name = (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
			this->Passport_data = (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
			this->Login = (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
			this->Password = (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
			this->groupBox3 = (gcnew System::Windows::Forms::GroupBox());
			this->button_Edit = (gcnew System::Windows::Forms::Button());
			this->button_write_off = (gcnew System::Windows::Forms::Button());
			this->button_Add_food = (gcnew System::Windows::Forms::Button());
			this->dataGridView_Food = (gcnew System::Windows::Forms::DataGridView());
			this->ID = (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
			this->Title_food = (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
			this->Qty = (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
			this->label3 = (gcnew System::Windows::Forms::Label());
			this->обновитьToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->назадToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->menuStrip1 = (gcnew System::Windows::Forms::MenuStrip());
			this->label_Zoo_ID = (gcnew System::Windows::Forms::Label());
			this->label2 = (gcnew System::Windows::Forms::Label());
			this->groupBox1->SuspendLayout();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->dataGridView_Employee))->BeginInit();
			this->groupBox3->SuspendLayout();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->dataGridView_Food))->BeginInit();
			this->menuStrip1->SuspendLayout();
			this->SuspendLayout();
			// 
			// groupBox1
			// 
			this->groupBox1->Controls->Add(this->button_Delete_Employee);
			this->groupBox1->Controls->Add(this->button_Update);
			this->groupBox1->Controls->Add(this->button_Add_Employee);
			this->groupBox1->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->groupBox1->Location = System::Drawing::Point(537, 75);
			this->groupBox1->Name = L"groupBox1";
			this->groupBox1->Size = System::Drawing::Size(200, 180);
			this->groupBox1->TabIndex = 5;
			this->groupBox1->TabStop = false;
			this->groupBox1->Text = L"Управление сотрудниками";
			// 
			// button_Delete_Employee
			// 
			this->button_Delete_Employee->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 11.25F, System::Drawing::FontStyle::Regular,
				System::Drawing::GraphicsUnit::Point, static_cast<System::Byte>(204)));
			this->button_Delete_Employee->Location = System::Drawing::Point(20, 125);
			this->button_Delete_Employee->Name = L"button_Delete_Employee";
			this->button_Delete_Employee->Size = System::Drawing::Size(160, 25);
			this->button_Delete_Employee->TabIndex = 2;
			this->button_Delete_Employee->Text = L"Удалить";
			this->button_Delete_Employee->UseVisualStyleBackColor = true;
			this->button_Delete_Employee->Click += gcnew System::EventHandler(this, &Menu_Zoo_Form::button_Delete_Employee_Click);
			// 
			// button_Update
			// 
			this->button_Update->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 11.25F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->button_Update->Location = System::Drawing::Point(20, 85);
			this->button_Update->Name = L"button_Update";
			this->button_Update->Size = System::Drawing::Size(160, 25);
			this->button_Update->TabIndex = 1;
			this->button_Update->Text = L"Изменить данные";
			this->button_Update->UseVisualStyleBackColor = true;
			this->button_Update->Click += gcnew System::EventHandler(this, &Menu_Zoo_Form::button_Update_Click);
			// 
			// button_Add_Employee
			// 
			this->button_Add_Employee->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 11.25F, System::Drawing::FontStyle::Regular,
				System::Drawing::GraphicsUnit::Point, static_cast<System::Byte>(204)));
			this->button_Add_Employee->Location = System::Drawing::Point(20, 45);
			this->button_Add_Employee->Name = L"button_Add_Employee";
			this->button_Add_Employee->Size = System::Drawing::Size(160, 25);
			this->button_Add_Employee->TabIndex = 0;
			this->button_Add_Employee->Text = L"Добавить";
			this->button_Add_Employee->UseVisualStyleBackColor = true;
			this->button_Add_Employee->Click += gcnew System::EventHandler(this, &Menu_Zoo_Form::button_Add_Employee_Click);
			// 
			// label1
			// 
			this->label1->AutoSize = true;
			this->label1->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 14.25F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->label1->Location = System::Drawing::Point(12, 50);
			this->label1->Name = L"label1";
			this->label1->Size = System::Drawing::Size(118, 24);
			this->label1->TabIndex = 4;
			this->label1->Text = L"Сотрудники";
			// 
			// dataGridView_Employee
			// 
			this->dataGridView_Employee->ColumnHeadersHeightSizeMode = System::Windows::Forms::DataGridViewColumnHeadersHeightSizeMode::AutoSize;
			this->dataGridView_Employee->Columns->AddRange(gcnew cli::array< System::Windows::Forms::DataGridViewColumn^  >(5) {
				this->Service_number,
					this->Full_name, this->Passport_data, this->Login, this->Password
			});
			this->dataGridView_Employee->Location = System::Drawing::Point(12, 75);
			this->dataGridView_Employee->Name = L"dataGridView_Employee";
			this->dataGridView_Employee->Size = System::Drawing::Size(510, 180);
			this->dataGridView_Employee->TabIndex = 3;
			// 
			// Service_number
			// 
			this->Service_number->HeaderText = L"Табельный номер";
			this->Service_number->Name = L"Service_number";
			this->Service_number->Width = 90;
			// 
			// Full_name
			// 
			this->Full_name->HeaderText = L"ФИО";
			this->Full_name->Name = L"Full_name";
			this->Full_name->Width = 90;
			// 
			// Passport_data
			// 
			this->Passport_data->HeaderText = L"Паспортные данные";
			this->Passport_data->Name = L"Passport_data";
			this->Passport_data->Width = 90;
			// 
			// Login
			// 
			this->Login->HeaderText = L"Логин";
			this->Login->Name = L"Login";
			this->Login->Width = 90;
			// 
			// Password
			// 
			this->Password->HeaderText = L"Пароль";
			this->Password->Name = L"Password";
			this->Password->Width = 90;
			// 
			// groupBox3
			// 
			this->groupBox3->Controls->Add(this->button_Edit);
			this->groupBox3->Controls->Add(this->button_write_off);
			this->groupBox3->Controls->Add(this->button_Add_food);
			this->groupBox3->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->groupBox3->Location = System::Drawing::Point(446, 294);
			this->groupBox3->Name = L"groupBox3";
			this->groupBox3->Size = System::Drawing::Size(200, 180);
			this->groupBox3->TabIndex = 7;
			this->groupBox3->TabStop = false;
			this->groupBox3->Text = L"Управление кормом";
			// 
			// button_Edit
			// 
			this->button_Edit->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 11.25F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->button_Edit->Location = System::Drawing::Point(20, 78);
			this->button_Edit->Name = L"button_Edit";
			this->button_Edit->Size = System::Drawing::Size(160, 25);
			this->button_Edit->TabIndex = 5;
			this->button_Edit->Text = L"Поменять кол-во";
			this->button_Edit->UseVisualStyleBackColor = true;
			this->button_Edit->Click += gcnew System::EventHandler(this, &Menu_Zoo_Form::button_Edit_Click);
			// 
			// button_write_off
			// 
			this->button_write_off->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 11.25F, System::Drawing::FontStyle::Regular,
				System::Drawing::GraphicsUnit::Point, static_cast<System::Byte>(204)));
			this->button_write_off->Location = System::Drawing::Point(20, 122);
			this->button_write_off->Name = L"button_write_off";
			this->button_write_off->Size = System::Drawing::Size(160, 25);
			this->button_write_off->TabIndex = 4;
			this->button_write_off->Text = L"Списать";
			this->button_write_off->UseVisualStyleBackColor = true;
			this->button_write_off->Click += gcnew System::EventHandler(this, &Menu_Zoo_Form::button_write_off_Click);
			// 
			// button_Add_food
			// 
			this->button_Add_food->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 11.25F, System::Drawing::FontStyle::Regular,
				System::Drawing::GraphicsUnit::Point, static_cast<System::Byte>(204)));
			this->button_Add_food->Location = System::Drawing::Point(20, 34);
			this->button_Add_food->Name = L"button_Add_food";
			this->button_Add_food->Size = System::Drawing::Size(160, 25);
			this->button_Add_food->TabIndex = 3;
			this->button_Add_food->Text = L"Добавить";
			this->button_Add_food->UseVisualStyleBackColor = true;
			this->button_Add_food->Click += gcnew System::EventHandler(this, &Menu_Zoo_Form::button_Add_food_Click);
			// 
			// dataGridView_Food
			// 
			this->dataGridView_Food->ColumnHeadersHeightSizeMode = System::Windows::Forms::DataGridViewColumnHeadersHeightSizeMode::AutoSize;
			this->dataGridView_Food->Columns->AddRange(gcnew cli::array< System::Windows::Forms::DataGridViewColumn^  >(3) {
				this->ID,
					this->Title_food, this->Qty
			});
			this->dataGridView_Food->Location = System::Drawing::Point(12, 294);
			this->dataGridView_Food->Name = L"dataGridView_Food";
			this->dataGridView_Food->Size = System::Drawing::Size(363, 180);
			this->dataGridView_Food->TabIndex = 9;
			// 
			// ID
			// 
			this->ID->HeaderText = L"ID";
			this->ID->Name = L"ID";
			// 
			// Title_food
			// 
			this->Title_food->HeaderText = L"Название";
			this->Title_food->Name = L"Title_food";
			// 
			// Qty
			// 
			this->Qty->HeaderText = L"Кол-во";
			this->Qty->Name = L"Qty";
			// 
			// label3
			// 
			this->label3->AutoSize = true;
			this->label3->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 14.25F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->label3->Location = System::Drawing::Point(12, 269);
			this->label3->Name = L"label3";
			this->label3->Size = System::Drawing::Size(57, 24);
			this->label3->TabIndex = 8;
			this->label3->Text = L"Корм";
			// 
			// обновитьToolStripMenuItem
			// 
			this->обновитьToolStripMenuItem->Name = L"обновитьToolStripMenuItem";
			this->обновитьToolStripMenuItem->Size = System::Drawing::Size(73, 20);
			this->обновитьToolStripMenuItem->Text = L"Обновить";
			this->обновитьToolStripMenuItem->Click += gcnew System::EventHandler(this, &Menu_Zoo_Form::обновитьToolStripMenuItem_Click);
			// 
			// назадToolStripMenuItem
			// 
			this->назадToolStripMenuItem->Name = L"назадToolStripMenuItem";
			this->назадToolStripMenuItem->Size = System::Drawing::Size(51, 20);
			this->назадToolStripMenuItem->Text = L"Назад";
			this->назадToolStripMenuItem->Click += gcnew System::EventHandler(this, &Menu_Zoo_Form::назадToolStripMenuItem_Click);
			// 
			// menuStrip1
			// 
			this->menuStrip1->BackColor = System::Drawing::SystemColors::GradientInactiveCaption;
			this->menuStrip1->Items->AddRange(gcnew cli::array< System::Windows::Forms::ToolStripItem^  >(2) {
				this->обновитьToolStripMenuItem,
					this->назадToolStripMenuItem
			});
			this->menuStrip1->Location = System::Drawing::Point(0, 0);
			this->menuStrip1->Name = L"menuStrip1";
			this->menuStrip1->Size = System::Drawing::Size(754, 24);
			this->menuStrip1->TabIndex = 10;
			this->menuStrip1->Text = L"menuStrip1";
			// 
			// label_Zoo_ID
			// 
			this->label_Zoo_ID->AutoSize = true;
			this->label_Zoo_ID->Location = System::Drawing::Point(75, 28);
			this->label_Zoo_ID->Name = L"label_Zoo_ID";
			this->label_Zoo_ID->Size = System::Drawing::Size(35, 13);
			this->label_Zoo_ID->TabIndex = 11;
			this->label_Zoo_ID->Text = L"label2";
			// 
			// label2
			// 
			this->label2->AutoSize = true;
			this->label2->Location = System::Drawing::Point(13, 28);
			this->label2->Name = L"label2";
			this->label2->Size = System::Drawing::Size(64, 13);
			this->label2->TabIndex = 12;
			this->label2->Text = L"Зоопарк №";
			// 
			// Menu_Zoo_Form
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(754, 486);
			this->Controls->Add(this->label2);
			this->Controls->Add(this->label_Zoo_ID);
			this->Controls->Add(this->groupBox3);
			this->Controls->Add(this->dataGridView_Food);
			this->Controls->Add(this->label3);
			this->Controls->Add(this->groupBox1);
			this->Controls->Add(this->label1);
			this->Controls->Add(this->dataGridView_Employee);
			this->Controls->Add(this->menuStrip1);
			this->MainMenuStrip = this->menuStrip1;
			this->Name = L"Menu_Zoo_Form";
			this->Text = L"Menu_Zoo_Form";
			this->FormClosed += gcnew System::Windows::Forms::FormClosedEventHandler(this, &Menu_Zoo_Form::Menu_Zoo_Form_FormClosed);
			this->groupBox1->ResumeLayout(false);
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->dataGridView_Employee))->EndInit();
			this->groupBox3->ResumeLayout(false);
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->dataGridView_Food))->EndInit();
			this->menuStrip1->ResumeLayout(false);
			this->menuStrip1->PerformLayout();
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion
private: System::Void обновитьToolStripMenuItem_Click(System::Object^ sender, System::EventArgs^ e);
private: System::Void назадToolStripMenuItem_Click(System::Object^ sender, System::EventArgs^ e);
private: System::Void button_Add_Employee_Click(System::Object^ sender, System::EventArgs^ e);
private: System::Void button_Update_Click(System::Object^ sender, System::EventArgs^ e);
private: System::Void button_Delete_Employee_Click(System::Object^ sender, System::EventArgs^ e);
private: System::Void button_Add_food_Click(System::Object^ sender, System::EventArgs^ e);
private: System::Void button_write_off_Click(System::Object^ sender, System::EventArgs^ e);
private: System::Void Menu_Zoo_Form_FormClosed(System::Object^ sender, System::Windows::Forms::FormClosedEventArgs^ e);
private: System::Void button_Edit_Click(System::Object^ sender, System::EventArgs^ e);
};
}
