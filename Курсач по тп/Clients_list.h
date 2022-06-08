#pragma once
#include "Connection.h"
#include "Add_client_Form.h"
#include "Client.h"

namespace Курсачпотп {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;

	/// <summary>
	/// Сводка для Clients_list
	/// </summary>
	public ref class Clients_list : public System::Windows::Forms::Form
	{
	public:
		Clients_list(void)
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
		~Clients_list()
		{
			if (components)
			{
				delete components;
			}
		}
	private: System::Windows::Forms::DataGridView^ dataGridView1;
	protected:
	private: System::Windows::Forms::DataGridViewTextBoxColumn^ Full_name;
	private: System::Windows::Forms::DataGridViewTextBoxColumn^ DLN;
	private: System::Windows::Forms::DataGridViewTextBoxColumn^ Phone_numder;
	private: System::Windows::Forms::Button^ button_Back;
	private: System::Windows::Forms::Button^ button_Exit;
	private: System::Windows::Forms::Button^ button_Add;
	private: System::Windows::Forms::Button^ button_Update;
	private: System::Windows::Forms::Button^ button_Delete;
	private: System::Windows::Forms::GroupBox^ groupBox1;
	private: System::Windows::Forms::Button^ button_load;
	private: System::Windows::Forms::DataGridViewTextBoxColumn^ Login;
	private: System::Windows::Forms::DataGridViewTextBoxColumn^ Password;


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
			this->Full_name = (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
			this->DLN = (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
			this->Phone_numder = (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
			this->button_Back = (gcnew System::Windows::Forms::Button());
			this->button_Exit = (gcnew System::Windows::Forms::Button());
			this->button_Add = (gcnew System::Windows::Forms::Button());
			this->button_Update = (gcnew System::Windows::Forms::Button());
			this->button_Delete = (gcnew System::Windows::Forms::Button());
			this->groupBox1 = (gcnew System::Windows::Forms::GroupBox());
			this->button_load = (gcnew System::Windows::Forms::Button());
			this->Login = (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
			this->Password = (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->dataGridView1))->BeginInit();
			this->groupBox1->SuspendLayout();
			this->SuspendLayout();
			// 
			// dataGridView1
			// 
			this->dataGridView1->ColumnHeadersHeightSizeMode = System::Windows::Forms::DataGridViewColumnHeadersHeightSizeMode::AutoSize;
			this->dataGridView1->Columns->AddRange(gcnew cli::array< System::Windows::Forms::DataGridViewColumn^  >(5) {
				this->Full_name,
					this->DLN, this->Phone_numder, this->Login, this->Password
			});
			this->dataGridView1->Location = System::Drawing::Point(15, 15);
			this->dataGridView1->Name = L"dataGridView1";
			this->dataGridView1->Size = System::Drawing::Size(560, 225);
			this->dataGridView1->TabIndex = 0;
			// 
			// Full_name
			// 
			this->Full_name->HeaderText = L"ФИО";
			this->Full_name->Name = L"Full_name";
			// 
			// DLN
			// 
			this->DLN->HeaderText = L"Номер прав";
			this->DLN->Name = L"DLN";
			// 
			// Phone_numder
			// 
			this->Phone_numder->HeaderText = L"Номер телефона";
			this->Phone_numder->Name = L"Phone_numder";
			// 
			// button_Back
			// 
			this->button_Back->Location = System::Drawing::Point(15, 260);
			this->button_Back->Name = L"button_Back";
			this->button_Back->Size = System::Drawing::Size(100, 25);
			this->button_Back->TabIndex = 1;
			this->button_Back->Text = L"Назад";
			this->button_Back->UseVisualStyleBackColor = true;
			this->button_Back->Click += gcnew System::EventHandler(this, &Clients_list::button_Back_Click);
			// 
			// button_Exit
			// 
			this->button_Exit->Location = System::Drawing::Point(665, 260);
			this->button_Exit->Name = L"button_Exit";
			this->button_Exit->Size = System::Drawing::Size(100, 25);
			this->button_Exit->TabIndex = 2;
			this->button_Exit->Text = L"Выход";
			this->button_Exit->UseVisualStyleBackColor = true;
			this->button_Exit->Click += gcnew System::EventHandler(this, &Clients_list::button_Exit_Click);
			// 
			// button_Add
			// 
			this->button_Add->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 9.75F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->button_Add->Location = System::Drawing::Point(5, 90);
			this->button_Add->Name = L"button_Create";
			this->button_Add->Size = System::Drawing::Size(170, 30);
			this->button_Add->TabIndex = 3;
			this->button_Add->Text = L"Добвать";
			this->button_Add->UseVisualStyleBackColor = true;
			this->button_Add->Click += gcnew System::EventHandler(this, &Clients_list::button_Add_Click);
			// 
			// button_Update
			// 
			this->button_Update->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 9.75F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->button_Update->Location = System::Drawing::Point(5, 125);
			this->button_Update->Name = L"button_Update";
			this->button_Update->Size = System::Drawing::Size(170, 30);
			this->button_Update->TabIndex = 4;
			this->button_Update->Text = L"Изменить";
			this->button_Update->UseVisualStyleBackColor = true;
			this->button_Update->Click += gcnew System::EventHandler(this, &Clients_list::button_Update_Click);
			// 
			// button_Delete
			// 
			this->button_Delete->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 9.75F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->button_Delete->Location = System::Drawing::Point(5, 160);
			this->button_Delete->Name = L"button_Delete";
			this->button_Delete->Size = System::Drawing::Size(170, 30);
			this->button_Delete->TabIndex = 5;
			this->button_Delete->Text = L"Удалить";
			this->button_Delete->UseVisualStyleBackColor = true;
			this->button_Delete->Click += gcnew System::EventHandler(this, &Clients_list::button_Delete_Click);
			// 
			// groupBox1
			// 
			this->groupBox1->Controls->Add(this->button_load);
			this->groupBox1->Controls->Add(this->button_Add);
			this->groupBox1->Controls->Add(this->button_Delete);
			this->groupBox1->Controls->Add(this->button_Update);
			this->groupBox1->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 9.75F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->groupBox1->Location = System::Drawing::Point(585, 15);
			this->groupBox1->Name = L"groupBox1";
			this->groupBox1->Size = System::Drawing::Size(180, 205);
			this->groupBox1->TabIndex = 6;
			this->groupBox1->TabStop = false;
			this->groupBox1->Text = L"Управление списком клиентов";
			// 
			// button_load
			// 
			this->button_load->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 9.75F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->button_load->Location = System::Drawing::Point(5, 55);
			this->button_load->Name = L"button_load";
			this->button_load->Size = System::Drawing::Size(170, 30);
			this->button_load->TabIndex = 6;
			this->button_load->Text = L"Загрузить/Обновить";
			this->button_load->UseVisualStyleBackColor = true;
			this->button_load->Click += gcnew System::EventHandler(this, &Clients_list::button_load_Click);
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
			// Clients_list
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(774, 291);
			this->Controls->Add(this->groupBox1);
			this->Controls->Add(this->button_Exit);
			this->Controls->Add(this->button_Back);
			this->Controls->Add(this->dataGridView1);
			this->Name = L"Clients_list";
			this->Text = L"Clients_list";
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->dataGridView1))->EndInit();
			this->groupBox1->ResumeLayout(false);
			this->ResumeLayout(false);

		}
#pragma endregion
private: System::Void button_load_Click(System::Object^ sender, System::EventArgs^ e);
private: System::Void button_Add_Click(System::Object^ sender, System::EventArgs^ e);
private: System::Void button_Update_Click(System::Object^ sender, System::EventArgs^ e);
private: System::Void button_Delete_Click(System::Object^ sender, System::EventArgs^ e);
private: System::Void button_Back_Click(System::Object^ sender, System::EventArgs^ e);
private: System::Void button_Exit_Click(System::Object^ sender, System::EventArgs^ e);
};
}
