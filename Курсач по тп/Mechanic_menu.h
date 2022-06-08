#pragma once
#include "Connection.h"
#include "Request.h"
#include "Mechanic.h"

namespace Курсачпотп {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;

	/// <summary>
	/// Сводка для Mechanic_menu
	/// </summary>
	public ref class Mechanic_menu : public System::Windows::Forms::Form
	{
	public:
		Mechanic_menu(void)
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
		~Mechanic_menu()
		{
			if (components)
			{
				delete components;
			}
		}
	private: System::Windows::Forms::DataGridView^ dataGridView1;
	protected:



	private: System::Windows::Forms::Button^ button_Execute;
	private: System::Windows::Forms::Button^ button_Back;
	private: System::Windows::Forms::Button^ button_Exit;
	private: System::Windows::Forms::Button^ button_Update;
	private: System::Windows::Forms::GroupBox^ groupBox1;
	public: System::Windows::Forms::Label^ label_mechanic;
	private: System::Windows::Forms::DataGridViewTextBoxColumn^ ID_repair;
	public:
	private: System::Windows::Forms::DataGridViewTextBoxColumn^ Car_namber;
	private: System::Windows::Forms::DataGridViewTextBoxColumn^ Type_of_repair;
	private: System::Windows::Forms::DataGridViewTextBoxColumn^ Status;

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
			this->dataGridView1 = (gcnew System::Windows::Forms::DataGridView());
			this->button_Execute = (gcnew System::Windows::Forms::Button());
			this->button_Back = (gcnew System::Windows::Forms::Button());
			this->button_Exit = (gcnew System::Windows::Forms::Button());
			this->button_Update = (gcnew System::Windows::Forms::Button());
			this->groupBox1 = (gcnew System::Windows::Forms::GroupBox());
			this->label_mechanic = (gcnew System::Windows::Forms::Label());
			this->ID_repair = (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
			this->Car_namber = (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
			this->Type_of_repair = (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
			this->Status = (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->dataGridView1))->BeginInit();
			this->groupBox1->SuspendLayout();
			this->SuspendLayout();
			// 
			// dataGridView1
			// 
			this->dataGridView1->ColumnHeadersHeightSizeMode = System::Windows::Forms::DataGridViewColumnHeadersHeightSizeMode::AutoSize;
			this->dataGridView1->Columns->AddRange(gcnew cli::array< System::Windows::Forms::DataGridViewColumn^  >(4) {
				this->ID_repair,
					this->Car_namber, this->Type_of_repair, this->Status
			});
			this->dataGridView1->Location = System::Drawing::Point(15, 15);
			this->dataGridView1->Name = L"dataGridView1";
			this->dataGridView1->Size = System::Drawing::Size(460, 255);
			this->dataGridView1->TabIndex = 0;
			// 
			// button_Execute
			// 
			this->button_Execute->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 9.75F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->button_Execute->Location = System::Drawing::Point(10, 100);
			this->button_Execute->Name = L"button_Execute";
			this->button_Execute->Size = System::Drawing::Size(190, 32);
			this->button_Execute->TabIndex = 1;
			this->button_Execute->Text = L"Выполнить";
			this->button_Execute->UseVisualStyleBackColor = true;
			this->button_Execute->Click += gcnew System::EventHandler(this, &Mechanic_menu::button_Execute_Click);
			// 
			// button_Back
			// 
			this->button_Back->Location = System::Drawing::Point(490, 244);
			this->button_Back->Name = L"button_Back";
			this->button_Back->Size = System::Drawing::Size(100, 25);
			this->button_Back->TabIndex = 2;
			this->button_Back->Text = L"Назад";
			this->button_Back->UseVisualStyleBackColor = true;
			this->button_Back->Click += gcnew System::EventHandler(this, &Mechanic_menu::button_Back_Click);
			// 
			// button_Exit
			// 
			this->button_Exit->Location = System::Drawing::Point(600, 244);
			this->button_Exit->Name = L"button_Exit";
			this->button_Exit->Size = System::Drawing::Size(100, 25);
			this->button_Exit->TabIndex = 3;
			this->button_Exit->Text = L"Выход";
			this->button_Exit->UseVisualStyleBackColor = true;
			this->button_Exit->Click += gcnew System::EventHandler(this, &Mechanic_menu::button_Exit_Click);
			// 
			// button_Update
			// 
			this->button_Update->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 9.75F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->button_Update->Location = System::Drawing::Point(10, 40);
			this->button_Update->Name = L"button_Update";
			this->button_Update->Size = System::Drawing::Size(190, 32);
			this->button_Update->TabIndex = 4;
			this->button_Update->Text = L"Загрузить/Обновить";
			this->button_Update->UseVisualStyleBackColor = true;
			this->button_Update->Click += gcnew System::EventHandler(this, &Mechanic_menu::button_Update_Click);
			// 
			// groupBox1
			// 
			this->groupBox1->Controls->Add(this->button_Execute);
			this->groupBox1->Controls->Add(this->button_Update);
			this->groupBox1->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->groupBox1->Location = System::Drawing::Point(490, 15);
			this->groupBox1->Name = L"groupBox1";
			this->groupBox1->Size = System::Drawing::Size(210, 175);
			this->groupBox1->TabIndex = 5;
			this->groupBox1->TabStop = false;
			this->groupBox1->Text = L"Управление";
			// 
			// label_mechanic
			// 
			this->label_mechanic->AutoSize = true;
			this->label_mechanic->Location = System::Drawing::Point(185, 148);
			this->label_mechanic->Name = L"label_mechanic";
			this->label_mechanic->Size = System::Drawing::Size(35, 13);
			this->label_mechanic->TabIndex = 6;
			this->label_mechanic->Text = L"label1";
			// 
			// ID_repair
			// 
			this->ID_repair->HeaderText = L"Номер ремонта";
			this->ID_repair->Name = L"ID_repair";
			// 
			// Car_namber
			// 
			this->Car_namber->HeaderText = L"Номер машины";
			this->Car_namber->Name = L"Car_namber";
			// 
			// Type_of_repair
			// 
			this->Type_of_repair->HeaderText = L"Вид ремонта";
			this->Type_of_repair->Name = L"Type_of_repair";
			// 
			// Status
			// 
			this->Status->HeaderText = L"Готовность";
			this->Status->Name = L"Status";
			// 
			// Mechanic_menu
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(714, 281);
			this->Controls->Add(this->groupBox1);
			this->Controls->Add(this->button_Exit);
			this->Controls->Add(this->button_Back);
			this->Controls->Add(this->dataGridView1);
			this->Controls->Add(this->label_mechanic);
			this->Name = L"Mechanic_menu";
			this->Text = L"Mechanic_menu";
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->dataGridView1))->EndInit();
			this->groupBox1->ResumeLayout(false);
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion
private: System::Void button_Execute_Click(System::Object^ sender, System::EventArgs^ e);
private: System::Void button_Update_Click(System::Object^ sender, System::EventArgs^ e);
private: System::Void button_Back_Click(System::Object^ sender, System::EventArgs^ e);
private: System::Void button_Exit_Click(System::Object^ sender, System::EventArgs^ e);
};
}
