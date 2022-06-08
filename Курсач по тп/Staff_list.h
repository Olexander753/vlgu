#pragma once
#include "Add_manager_Form.h"
#include "Add_mechanic_Form.h"
#include "Connection.h"
#include "Manager.h"
#include "Mechanic.h"

namespace Курсачпотп {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;

	/// <summary>
	/// Сводка для Staff_list
	/// </summary>
	public ref class Staff_list : public System::Windows::Forms::Form
	{
	public:
		Staff_list(void)
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
		~Staff_list()
		{
			if (components)
			{
				delete components;
			}
		}
	private: System::Windows::Forms::DataGridView^ dataGridView1;
	protected:;
	private: System::Windows::Forms::Button^ button_Add;
	private: System::Windows::Forms::Button^ button_Edit;
	private: System::Windows::Forms::GroupBox^ groupBox1;
	private: System::Windows::Forms::Button^ button_Delete;
	private: System::Windows::Forms::Button^ button_Back;
	private: System::Windows::Forms::Button^ button_Exit;
	private: System::Windows::Forms::Button^ button_load;
	private: System::Windows::Forms::DataGridView^ dataGridView2;
	private: System::Windows::Forms::GroupBox^ groupBox2;
	private: System::Windows::Forms::Button^ button_load_;
	private: System::Windows::Forms::Button^ button_delete_;
	private: System::Windows::Forms::Button^ button_Edit_;
	private: System::Windows::Forms::Button^ button5;
	private: System::Windows::Forms::Button^ button_Add_;
	private: System::Windows::Forms::Label^ label1;
	private: System::Windows::Forms::Label^ label2;
	private: System::Windows::Forms::DataGridViewTextBoxColumn^ PN;
	private: System::Windows::Forms::DataGridViewTextBoxColumn^ Full_name;
	private: System::Windows::Forms::DataGridViewTextBoxColumn^ Passport_data;
	private: System::Windows::Forms::DataGridViewTextBoxColumn^ Phone_number;
	private: System::Windows::Forms::DataGridViewTextBoxColumn^ Login;
	private: System::Windows::Forms::DataGridViewTextBoxColumn^ Password;
	private: System::Windows::Forms::DataGridViewTextBoxColumn^ PN_;
	private: System::Windows::Forms::DataGridViewTextBoxColumn^ dataGridViewTextBoxColumn2;
	private: System::Windows::Forms::DataGridViewTextBoxColumn^ dataGridViewTextBoxColumn4;
	private: System::Windows::Forms::DataGridViewTextBoxColumn^ dataGridViewTextBoxColumn5;
	private: System::Windows::Forms::DataGridViewTextBoxColumn^ Qualification;
	private: System::Windows::Forms::DataGridViewTextBoxColumn^ Login_;
	private: System::Windows::Forms::DataGridViewTextBoxColumn^ Password_;
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
			this->PN = (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
			this->Full_name = (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
			this->Passport_data = (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
			this->Phone_number = (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
			this->Login = (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
			this->Password = (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
			this->button_Exit = (gcnew System::Windows::Forms::Button());
			this->button_Add = (gcnew System::Windows::Forms::Button());
			this->button_Edit = (gcnew System::Windows::Forms::Button());
			this->groupBox1 = (gcnew System::Windows::Forms::GroupBox());
			this->button_load = (gcnew System::Windows::Forms::Button());
			this->button_Delete = (gcnew System::Windows::Forms::Button());
			this->button_Back = (gcnew System::Windows::Forms::Button());
			this->dataGridView2 = (gcnew System::Windows::Forms::DataGridView());
			this->PN_ = (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
			this->dataGridViewTextBoxColumn2 = (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
			this->dataGridViewTextBoxColumn4 = (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
			this->dataGridViewTextBoxColumn5 = (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
			this->Qualification = (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
			this->Login_ = (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
			this->Password_ = (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
			this->groupBox2 = (gcnew System::Windows::Forms::GroupBox());
			this->button_load_ = (gcnew System::Windows::Forms::Button());
			this->button_delete_ = (gcnew System::Windows::Forms::Button());
			this->button_Edit_ = (gcnew System::Windows::Forms::Button());
			this->button5 = (gcnew System::Windows::Forms::Button());
			this->button_Add_ = (gcnew System::Windows::Forms::Button());
			this->label1 = (gcnew System::Windows::Forms::Label());
			this->label2 = (gcnew System::Windows::Forms::Label());
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->dataGridView1))->BeginInit();
			this->groupBox1->SuspendLayout();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->dataGridView2))->BeginInit();
			this->groupBox2->SuspendLayout();
			this->SuspendLayout();
			// 
			// dataGridView1
			// 
			this->dataGridView1->ColumnHeadersHeightSizeMode = System::Windows::Forms::DataGridViewColumnHeadersHeightSizeMode::AutoSize;
			this->dataGridView1->Columns->AddRange(gcnew cli::array< System::Windows::Forms::DataGridViewColumn^  >(6) {
				this->PN, this->Full_name,
					this->Passport_data, this->Phone_number, this->Login, this->Password
			});
			this->dataGridView1->Location = System::Drawing::Point(12, 33);
			this->dataGridView1->Name = L"dataGridView1";
			this->dataGridView1->Size = System::Drawing::Size(623, 182);
			this->dataGridView1->TabIndex = 0;
			// 
			// PN
			// 
			this->PN->HeaderText = L"Табельный номер";
			this->PN->Name = L"PN";
			this->PN->Width = 70;
			// 
			// Full_name
			// 
			this->Full_name->HeaderText = L"ФИО";
			this->Full_name->Name = L"Full_name";
			// 
			// Passport_data
			// 
			this->Passport_data->HeaderText = L"Паспортные данные";
			this->Passport_data->Name = L"Passport_data";
			// 
			// Phone_number
			// 
			this->Phone_number->HeaderText = L"Номер телефона";
			this->Phone_number->Name = L"Phone_number";
			// 
			// Login
			// 
			this->Login->HeaderText = L"Логин";
			this->Login->Name = L"Login";
			// 
			// Password
			// 
			this->Password->HeaderText = L"Пароль";
			this->Password->Name = L"Password";
			// 
			// button_Exit
			// 
			this->button_Exit->Location = System::Drawing::Point(1300, 351);
			this->button_Exit->Name = L"button_Exit";
			this->button_Exit->Size = System::Drawing::Size(100, 30);
			this->button_Exit->TabIndex = 6;
			this->button_Exit->Text = L"Выход";
			this->button_Exit->UseVisualStyleBackColor = true;
			this->button_Exit->Click += gcnew System::EventHandler(this, &Staff_list::button_Exit_Click);
			// 
			// button_Add
			// 
			this->button_Add->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 11.25F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->button_Add->Location = System::Drawing::Point(5, 86);
			this->button_Add->Name = L"button_Add";
			this->button_Add->Size = System::Drawing::Size(225, 30);
			this->button_Add->TabIndex = 2;
			this->button_Add->Text = L"Добавить";
			this->button_Add->UseVisualStyleBackColor = true;
			this->button_Add->Click += gcnew System::EventHandler(this, &Staff_list::button_Add_Click);
			// 
			// button_Edit
			// 
			this->button_Edit->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 11.25F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->button_Edit->Location = System::Drawing::Point(271, 36);
			this->button_Edit->Name = L"button_Edit";
			this->button_Edit->Size = System::Drawing::Size(225, 30);
			this->button_Edit->TabIndex = 3;
			this->button_Edit->Text = L"Изменить данные";
			this->button_Edit->UseVisualStyleBackColor = true;
			this->button_Edit->Click += gcnew System::EventHandler(this, &Staff_list::button_Edit_Click);
			// 
			// groupBox1
			// 
			this->groupBox1->Controls->Add(this->button_load);
			this->groupBox1->Controls->Add(this->button_Delete);
			this->groupBox1->Controls->Add(this->button_Edit);
			this->groupBox1->Controls->Add(this->button_Add);
			this->groupBox1->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->groupBox1->Location = System::Drawing::Point(15, 221);
			this->groupBox1->Name = L"groupBox1";
			this->groupBox1->Size = System::Drawing::Size(502, 124);
			this->groupBox1->TabIndex = 4;
			this->groupBox1->TabStop = false;
			this->groupBox1->Text = L"Управление списком менеджеров";
			// 
			// button_load
			// 
			this->button_load->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 11.25F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->button_load->Location = System::Drawing::Point(5, 36);
			this->button_load->Name = L"button_load";
			this->button_load->Size = System::Drawing::Size(225, 30);
			this->button_load->TabIndex = 5;
			this->button_load->Text = L"Загрузить/Обновить";
			this->button_load->UseVisualStyleBackColor = true;
			this->button_load->Click += gcnew System::EventHandler(this, &Staff_list::button_load_Click);
			// 
			// button_Delete
			// 
			this->button_Delete->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 11.25F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->button_Delete->Location = System::Drawing::Point(271, 86);
			this->button_Delete->Name = L"button_Delete";
			this->button_Delete->Size = System::Drawing::Size(225, 30);
			this->button_Delete->TabIndex = 4;
			this->button_Delete->Text = L"Удалить";
			this->button_Delete->UseVisualStyleBackColor = true;
			this->button_Delete->Click += gcnew System::EventHandler(this, &Staff_list::button_Delete_Click);
			// 
			// button_Back
			// 
			this->button_Back->Location = System::Drawing::Point(15, 351);
			this->button_Back->Name = L"button_Back";
			this->button_Back->Size = System::Drawing::Size(100, 30);
			this->button_Back->TabIndex = 5;
			this->button_Back->Text = L"Назад";
			this->button_Back->UseVisualStyleBackColor = true;
			this->button_Back->Click += gcnew System::EventHandler(this, &Staff_list::button_Back_Click);
			// 
			// dataGridView2
			// 
			this->dataGridView2->ColumnHeadersHeightSizeMode = System::Windows::Forms::DataGridViewColumnHeadersHeightSizeMode::AutoSize;
			this->dataGridView2->Columns->AddRange(gcnew cli::array< System::Windows::Forms::DataGridViewColumn^  >(7) {
				this->PN_, this->dataGridViewTextBoxColumn2,
					this->dataGridViewTextBoxColumn4, this->dataGridViewTextBoxColumn5, this->Qualification, this->Login_, this->Password_
			});
			this->dataGridView2->Location = System::Drawing::Point(678, 33);
			this->dataGridView2->Name = L"dataGridView2";
			this->dataGridView2->Size = System::Drawing::Size(721, 182);
			this->dataGridView2->TabIndex = 7;
			// 
			// PN_
			// 
			this->PN_->HeaderText = L"Табельный номер";
			this->PN_->Name = L"PN_";
			this->PN_->Width = 70;
			// 
			// dataGridViewTextBoxColumn2
			// 
			this->dataGridViewTextBoxColumn2->HeaderText = L"ФИО";
			this->dataGridViewTextBoxColumn2->Name = L"dataGridViewTextBoxColumn2";
			// 
			// dataGridViewTextBoxColumn4
			// 
			this->dataGridViewTextBoxColumn4->HeaderText = L"Паспортные данные";
			this->dataGridViewTextBoxColumn4->Name = L"dataGridViewTextBoxColumn4";
			// 
			// dataGridViewTextBoxColumn5
			// 
			this->dataGridViewTextBoxColumn5->HeaderText = L"Номер телефона";
			this->dataGridViewTextBoxColumn5->Name = L"dataGridViewTextBoxColumn5";
			// 
			// Qualification
			// 
			this->Qualification->HeaderText = L"Квалификация";
			this->Qualification->Name = L"Qualification";
			// 
			// Login_
			// 
			this->Login_->HeaderText = L"Логин";
			this->Login_->Name = L"Login_";
			// 
			// Password_
			// 
			this->Password_->HeaderText = L"Пароль";
			this->Password_->Name = L"Password_";
			// 
			// groupBox2
			// 
			this->groupBox2->Controls->Add(this->button_load_);
			this->groupBox2->Controls->Add(this->button_delete_);
			this->groupBox2->Controls->Add(this->button_Edit_);
			this->groupBox2->Controls->Add(this->button5);
			this->groupBox2->Controls->Add(this->button_Add_);
			this->groupBox2->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->groupBox2->Location = System::Drawing::Point(789, 221);
			this->groupBox2->Name = L"groupBox2";
			this->groupBox2->Size = System::Drawing::Size(502, 124);
			this->groupBox2->TabIndex = 6;
			this->groupBox2->TabStop = false;
			this->groupBox2->Text = L"Управление списком механиков";
			// 
			// button_load_
			// 
			this->button_load_->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 11.25F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->button_load_->Location = System::Drawing::Point(5, 36);
			this->button_load_->Name = L"button_load_";
			this->button_load_->Size = System::Drawing::Size(225, 30);
			this->button_load_->TabIndex = 5;
			this->button_load_->Text = L"Загрузить/Обновить";
			this->button_load_->UseVisualStyleBackColor = true;
			this->button_load_->Click += gcnew System::EventHandler(this, &Staff_list::button_load__Click);
			// 
			// button_delete_
			// 
			this->button_delete_->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 11.25F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->button_delete_->Location = System::Drawing::Point(271, 86);
			this->button_delete_->Name = L"button_delete_";
			this->button_delete_->Size = System::Drawing::Size(225, 30);
			this->button_delete_->TabIndex = 4;
			this->button_delete_->Text = L"Удалить";
			this->button_delete_->UseVisualStyleBackColor = true;
			this->button_delete_->Click += gcnew System::EventHandler(this, &Staff_list::button_delete__Click);
			// 
			// button_Edit_
			// 
			this->button_Edit_->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 11.25F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->button_Edit_->Location = System::Drawing::Point(271, 36);
			this->button_Edit_->Name = L"button_Edit_";
			this->button_Edit_->Size = System::Drawing::Size(225, 30);
			this->button_Edit_->TabIndex = 3;
			this->button_Edit_->Text = L"Изменить данные";
			this->button_Edit_->UseVisualStyleBackColor = true;
			this->button_Edit_->Click += gcnew System::EventHandler(this, &Staff_list::button_Edit__Click);
			// 
			// button5
			// 
			this->button5->Location = System::Drawing::Point(20, -44);
			this->button5->Name = L"button5";
			this->button5->Size = System::Drawing::Size(150, 30);
			this->button5->TabIndex = 1;
			this->button5->Text = L"button5";
			this->button5->UseVisualStyleBackColor = true;
			// 
			// button_Add_
			// 
			this->button_Add_->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 11.25F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->button_Add_->Location = System::Drawing::Point(5, 86);
			this->button_Add_->Name = L"button_Add_";
			this->button_Add_->Size = System::Drawing::Size(225, 30);
			this->button_Add_->TabIndex = 2;
			this->button_Add_->Text = L"Добавить";
			this->button_Add_->UseVisualStyleBackColor = true;
			this->button_Add_->Click += gcnew System::EventHandler(this, &Staff_list::button_Add__Click);
			// 
			// label1
			// 
			this->label1->AutoSize = true;
			this->label1->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 14.25F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->label1->Location = System::Drawing::Point(12, 6);
			this->label1->Name = L"label1";
			this->label1->Size = System::Drawing::Size(120, 24);
			this->label1->TabIndex = 8;
			this->label1->Text = L"Менеджеры";
			// 
			// label2
			// 
			this->label2->AutoSize = true;
			this->label2->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 14.25F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->label2->Location = System::Drawing::Point(674, 6);
			this->label2->Name = L"label2";
			this->label2->Size = System::Drawing::Size(99, 24);
			this->label2->TabIndex = 9;
			this->label2->Text = L"Механики";
			// 
			// Staff_list
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(1411, 385);
			this->Controls->Add(this->label2);
			this->Controls->Add(this->label1);
			this->Controls->Add(this->groupBox2);
			this->Controls->Add(this->dataGridView2);
			this->Controls->Add(this->button_Exit);
			this->Controls->Add(this->button_Back);
			this->Controls->Add(this->groupBox1);
			this->Controls->Add(this->dataGridView1);
			this->Name = L"Staff_list";
			this->Text = L"Персонал";
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->dataGridView1))->EndInit();
			this->groupBox1->ResumeLayout(false);
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->dataGridView2))->EndInit();
			this->groupBox2->ResumeLayout(false);
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion
private: System::Void button_load_Click(System::Object^ sender, System::EventArgs^ e);
private: System::Void button_Edit_Click(System::Object^ sender, System::EventArgs^ e);
private: System::Void button_Add_Click(System::Object^ sender, System::EventArgs^ e);
private: System::Void button_Delete_Click(System::Object^ sender, System::EventArgs^ e);
private: System::Void button_load__Click(System::Object^ sender, System::EventArgs^ e);
private: System::Void button_Edit__Click(System::Object^ sender, System::EventArgs^ e);
private: System::Void button_Add__Click(System::Object^ sender, System::EventArgs^ e);
private: System::Void button_delete__Click(System::Object^ sender, System::EventArgs^ e);
private: System::Void button_Back_Click(System::Object^ sender, System::EventArgs^ e);
private: System::Void button_Exit_Click(System::Object^ sender, System::EventArgs^ e);
};
}
