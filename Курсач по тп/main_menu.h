#pragma once
#include "Clients_list.h"
#include "Connection.h"
#include "Add_client_Form.h"
#include "Add_request_Form.h"
#include "Update_request_Form.h"
#include "Request.h"
#include "Mechanic.h"
#include "Detal.h"

namespace Курсачпотп {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;

	/// <summary>
	/// Сводка для main_menu
	/// </summary>
	public ref class main_menu : public System::Windows::Forms::Form
	{
	public:
		main_menu(void)
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
		~main_menu()
		{
			if (components)
			{
				delete components;
			}
		}
	public: System::Windows::Forms::DataGridView^ dataGridView1;
	protected:
	private: System::Windows::Forms::GroupBox^ groupBox1;
	private: System::Windows::Forms::Button^ button_delete;
	private: System::Windows::Forms::Button^ button_edit;
	private: System::Windows::Forms::Button^ button_create;
	private: System::Windows::Forms::Button^ button_back;
	private: System::Windows::Forms::Button^ button_exit;
	private: System::Windows::Forms::Button^ button_Client_list;
	private: System::Windows::Forms::Button^ button_load;
	public: System::Windows::Forms::DataGridViewTextBoxColumn^ ID;
	private: System::Windows::Forms::DataGridViewTextBoxColumn^ FullName;
	private: System::Windows::Forms::DataGridViewTextBoxColumn^ Number_car;
	private: System::Windows::Forms::DataGridViewTextBoxColumn^ Mechanic_;
	private: System::Windows::Forms::DataGridViewTextBoxColumn^ Repair_;
	private: System::Windows::Forms::DataGridViewTextBoxColumn^ Detal_;
	private: System::Windows::Forms::DataGridViewTextBoxColumn^ Quantity;
	private: System::Windows::Forms::DataGridViewTextBoxColumn^ Date;
	private: System::Windows::Forms::DataGridViewTextBoxColumn^ Cost;
	private: System::Windows::Forms::DataGridViewTextBoxColumn^ Condition;
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
			this->groupBox1 = (gcnew System::Windows::Forms::GroupBox());
			this->button_load = (gcnew System::Windows::Forms::Button());
			this->button_create = (gcnew System::Windows::Forms::Button());
			this->button_delete = (gcnew System::Windows::Forms::Button());
			this->button_edit = (gcnew System::Windows::Forms::Button());
			this->button_back = (gcnew System::Windows::Forms::Button());
			this->button_exit = (gcnew System::Windows::Forms::Button());
			this->button_Client_list = (gcnew System::Windows::Forms::Button());
			this->ID = (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
			this->FullName = (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
			this->Number_car = (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
			this->Mechanic_ = (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
			this->Repair_ = (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
			this->Detal_ = (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
			this->Quantity = (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
			this->Date = (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
			this->Cost = (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
			this->Condition = (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->dataGridView1))->BeginInit();
			this->groupBox1->SuspendLayout();
			this->SuspendLayout();
			// 
			// dataGridView1
			// 
			this->dataGridView1->ColumnHeadersHeightSizeMode = System::Windows::Forms::DataGridViewColumnHeadersHeightSizeMode::AutoSize;
			this->dataGridView1->Columns->AddRange(gcnew cli::array< System::Windows::Forms::DataGridViewColumn^  >(10) {
				this->ID, this->FullName,
					this->Number_car, this->Mechanic_, this->Repair_, this->Detal_, this->Quantity, this->Date, this->Cost, this->Condition
			});
			this->dataGridView1->Location = System::Drawing::Point(15, 15);
			this->dataGridView1->Name = L"dataGridView1";
			this->dataGridView1->Size = System::Drawing::Size(960, 344);
			this->dataGridView1->TabIndex = 0;
			// 
			// groupBox1
			// 
			this->groupBox1->BackColor = System::Drawing::SystemColors::ButtonFace;
			this->groupBox1->Controls->Add(this->button_load);
			this->groupBox1->Controls->Add(this->button_create);
			this->groupBox1->Controls->Add(this->button_delete);
			this->groupBox1->Controls->Add(this->button_edit);
			this->groupBox1->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 14.25F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->groupBox1->Location = System::Drawing::Point(990, 15);
			this->groupBox1->Name = L"groupBox1";
			this->groupBox1->Size = System::Drawing::Size(220, 239);
			this->groupBox1->TabIndex = 1;
			this->groupBox1->TabStop = false;
			this->groupBox1->Text = L"Управление заявкой";
			// 
			// button_load
			// 
			this->button_load->Location = System::Drawing::Point(5, 40);
			this->button_load->Name = L"button_load";
			this->button_load->Size = System::Drawing::Size(210, 35);
			this->button_load->TabIndex = 4;
			this->button_load->Text = L"Загрузить/Обновить";
			this->button_load->UseVisualStyleBackColor = true;
			this->button_load->Click += gcnew System::EventHandler(this, &main_menu::button_load_Click);
			// 
			// button_create
			// 
			this->button_create->Location = System::Drawing::Point(5, 190);
			this->button_create->Name = L"button_create";
			this->button_create->Size = System::Drawing::Size(210, 35);
			this->button_create->TabIndex = 3;
			this->button_create->Text = L"Создать новую ";
			this->button_create->UseVisualStyleBackColor = true;
			this->button_create->Click += gcnew System::EventHandler(this, &main_menu::button_create_Click);
			// 
			// button_delete
			// 
			this->button_delete->Location = System::Drawing::Point(5, 140);
			this->button_delete->Name = L"button_delete";
			this->button_delete->Size = System::Drawing::Size(210, 35);
			this->button_delete->TabIndex = 2;
			this->button_delete->Text = L"Удалить";
			this->button_delete->UseVisualStyleBackColor = true;
			this->button_delete->Click += gcnew System::EventHandler(this, &main_menu::button_delete_Click);
			// 
			// button_edit
			// 
			this->button_edit->Location = System::Drawing::Point(5, 90);
			this->button_edit->Name = L"button_edit";
			this->button_edit->Size = System::Drawing::Size(210, 35);
			this->button_edit->TabIndex = 1;
			this->button_edit->Text = L"Редактировать";
			this->button_edit->UseVisualStyleBackColor = true;
			this->button_edit->Click += gcnew System::EventHandler(this, &main_menu::button_edit_Click);
			// 
			// button_back
			// 
			this->button_back->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 14.25F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->button_back->Location = System::Drawing::Point(995, 324);
			this->button_back->Name = L"button_back";
			this->button_back->Size = System::Drawing::Size(100, 35);
			this->button_back->TabIndex = 2;
			this->button_back->Text = L"Назад";
			this->button_back->UseVisualStyleBackColor = true;
			this->button_back->Click += gcnew System::EventHandler(this, &main_menu::button_back_Click);
			// 
			// button_exit
			// 
			this->button_exit->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 14.25F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->button_exit->Location = System::Drawing::Point(1105, 325);
			this->button_exit->Name = L"button_exit";
			this->button_exit->Size = System::Drawing::Size(100, 35);
			this->button_exit->TabIndex = 3;
			this->button_exit->Text = L"Выход";
			this->button_exit->UseVisualStyleBackColor = true;
			this->button_exit->Click += gcnew System::EventHandler(this, &main_menu::button_exit_Click);
			// 
			// button_Client_list
			// 
			this->button_Client_list->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 14.25F, System::Drawing::FontStyle::Regular,
				System::Drawing::GraphicsUnit::Point, static_cast<System::Byte>(204)));
			this->button_Client_list->Location = System::Drawing::Point(995, 272);
			this->button_Client_list->Name = L"button_Client_list";
			this->button_Client_list->Size = System::Drawing::Size(210, 35);
			this->button_Client_list->TabIndex = 4;
			this->button_Client_list->Text = L"Список клиентов";
			this->button_Client_list->UseVisualStyleBackColor = true;
			this->button_Client_list->Click += gcnew System::EventHandler(this, &main_menu::button_Client_list_Click);
			// 
			// ID
			// 
			this->ID->HeaderText = L"ID";
			this->ID->Name = L"ID";
			this->ID->Width = 70;
			// 
			// FullName
			// 
			this->FullName->HeaderText = L"ФИО";
			this->FullName->Name = L"FullName";
			// 
			// Number_car
			// 
			this->Number_car->HeaderText = L"Номер авто";
			this->Number_car->Name = L"Number_car";
			// 
			// Mechanic_
			// 
			this->Mechanic_->HeaderText = L"Механик";
			this->Mechanic_->Name = L"Mechanic_";
			// 
			// Repair_
			// 
			this->Repair_->HeaderText = L"Вид ремонта";
			this->Repair_->Name = L"Repair_";
			// 
			// Detal_
			// 
			this->Detal_->HeaderText = L"Деталь";
			this->Detal_->Name = L"Detal_";
			// 
			// Quantity
			// 
			this->Quantity->HeaderText = L"Количество ";
			this->Quantity->Name = L"Quantity";
			this->Quantity->Width = 80;
			// 
			// Date
			// 
			this->Date->HeaderText = L"Дата ";
			this->Date->Name = L"Date";
			this->Date->Width = 70;
			// 
			// Cost
			// 
			this->Cost->HeaderText = L"Стоимость";
			this->Cost->Name = L"Cost";
			this->Cost->Width = 70;
			// 
			// Condition
			// 
			this->Condition->HeaderText = L"Состояние";
			this->Condition->Name = L"Condition";
			// 
			// main_menu
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(1224, 371);
			this->Controls->Add(this->button_Client_list);
			this->Controls->Add(this->button_exit);
			this->Controls->Add(this->button_back);
			this->Controls->Add(this->groupBox1);
			this->Controls->Add(this->dataGridView1);
			this->Name = L"main_menu";
			this->Text = L"main_menu";
			this->FormClosed += gcnew System::Windows::Forms::FormClosedEventHandler(this, &main_menu::main_menu_FormClosed);
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->dataGridView1))->EndInit();
			this->groupBox1->ResumeLayout(false);
			this->ResumeLayout(false);

		}
#pragma endregion
private: System::Void button_back_Click(System::Object^ sender, System::EventArgs^ e);
private: System::Void button_exit_Click(System::Object^ sender, System::EventArgs^ e);
private: System::Void main_menu_FormClosed(System::Object^ sender, System::Windows::Forms::FormClosedEventArgs^ e);
private: System::Void button_edit_Click(System::Object^ sender, System::EventArgs^ e);
private: System::Void button_delete_Click(System::Object^ sender, System::EventArgs^ e);
private: System::Void button_create_Click(System::Object^ sender, System::EventArgs^ e);
private: System::Void button_Client_list_Click(System::Object^ sender, System::EventArgs^ e);
private: System::Void button_load_Click(System::Object^ sender, System::EventArgs^ e);
};
}
