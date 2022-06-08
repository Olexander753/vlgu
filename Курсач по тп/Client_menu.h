#pragma once
#include "Connection.h"
#include "Client.h"

namespace Курсачпотп {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;

	/// <summary>
	/// Сводка для Client_menu
	/// </summary>
	public ref class Client_menu : public System::Windows::Forms::Form
	{
	public:
		Client_menu(void)
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
		~Client_menu()
		{
			if (components)
			{
				delete components;
			}
		}
	private: System::Windows::Forms::Button^ button_back;
	private: System::Windows::Forms::Button^ button_Exit;
	protected:
	protected:
	protected:
	protected:
	protected:
	protected:
	public: System::Windows::Forms::DataGridView^ dataGridView1;





	private: System::Windows::Forms::Button^ button_load;
	public: System::Windows::Forms::Label^ Full_name_label;
	public: System::Windows::Forms::Label^ DLN_label;
	private: System::Windows::Forms::DataGridViewTextBoxColumn^ Number;
	public:
	private: System::Windows::Forms::DataGridViewTextBoxColumn^ Brend;
	private: System::Windows::Forms::DataGridViewTextBoxColumn^ Model;
	private: System::Windows::Forms::DataGridViewTextBoxColumn^ Type_of_work;
	private: System::Windows::Forms::DataGridViewTextBoxColumn^ Price;
	private: System::Windows::Forms::DataGridViewTextBoxColumn^ Status;

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
			this->button_back = (gcnew System::Windows::Forms::Button());
			this->button_Exit = (gcnew System::Windows::Forms::Button());
			this->dataGridView1 = (gcnew System::Windows::Forms::DataGridView());
			this->Number = (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
			this->Brend = (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
			this->Model = (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
			this->Type_of_work = (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
			this->Price = (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
			this->Status = (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
			this->button_load = (gcnew System::Windows::Forms::Button());
			this->Full_name_label = (gcnew System::Windows::Forms::Label());
			this->DLN_label = (gcnew System::Windows::Forms::Label());
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->dataGridView1))->BeginInit();
			this->SuspendLayout();
			// 
			// button_back
			// 
			this->button_back->Location = System::Drawing::Point(695, 215);
			this->button_back->Name = L"button_back";
			this->button_back->Size = System::Drawing::Size(75, 25);
			this->button_back->TabIndex = 0;
			this->button_back->Text = L"Назад";
			this->button_back->UseVisualStyleBackColor = true;
			this->button_back->Click += gcnew System::EventHandler(this, &Client_menu::button_back_Click);
			// 
			// button_Exit
			// 
			this->button_Exit->Location = System::Drawing::Point(785, 215);
			this->button_Exit->Name = L"button_Exit";
			this->button_Exit->Size = System::Drawing::Size(75, 25);
			this->button_Exit->TabIndex = 1;
			this->button_Exit->Text = L"Выход";
			this->button_Exit->UseVisualStyleBackColor = true;
			this->button_Exit->Click += gcnew System::EventHandler(this, &Client_menu::button_Exit_Click);
			// 
			// dataGridView1
			// 
			this->dataGridView1->ColumnHeadersHeightSizeMode = System::Windows::Forms::DataGridViewColumnHeadersHeightSizeMode::AutoSize;
			this->dataGridView1->Columns->AddRange(gcnew cli::array< System::Windows::Forms::DataGridViewColumn^  >(6) {
				this->Number,
					this->Brend, this->Model, this->Type_of_work, this->Price, this->Status
			});
			this->dataGridView1->Location = System::Drawing::Point(15, 40);
			this->dataGridView1->Name = L"dataGridView1";
			this->dataGridView1->Size = System::Drawing::Size(655, 200);
			this->dataGridView1->TabIndex = 2;
			// 
			// Number
			// 
			this->Number->HeaderText = L"Номер";
			this->Number->Name = L"Number";
			// 
			// Brend
			// 
			this->Brend->HeaderText = L"Марка";
			this->Brend->Name = L"Brend";
			// 
			// Model
			// 
			this->Model->HeaderText = L"Модель";
			this->Model->Name = L"Model";
			// 
			// Type_of_work
			// 
			this->Type_of_work->HeaderText = L"Вид работы";
			this->Type_of_work->Name = L"Type_of_work";
			// 
			// Price
			// 
			this->Price->HeaderText = L"Цена";
			this->Price->Name = L"Price";
			// 
			// Status
			// 
			this->Status->HeaderText = L"Статус готовности";
			this->Status->Name = L"Status";
			// 
			// button_load
			// 
			this->button_load->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 9.75F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->button_load->Location = System::Drawing::Point(695, 40);
			this->button_load->Name = L"button_load";
			this->button_load->Size = System::Drawing::Size(165, 53);
			this->button_load->TabIndex = 3;
			this->button_load->Text = L"Загрузить/Обновить";
			this->button_load->UseVisualStyleBackColor = true;
			this->button_load->Click += gcnew System::EventHandler(this, &Client_menu::button_load_Click);
			// 
			// Full_name_label
			// 
			this->Full_name_label->AutoSize = true;
			this->Full_name_label->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 9.75F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->Full_name_label->Location = System::Drawing::Point(15, 13);
			this->Full_name_label->Name = L"Full_name_label";
			this->Full_name_label->Size = System::Drawing::Size(45, 16);
			this->Full_name_label->TabIndex = 4;
			this->Full_name_label->Text = L"label1";
			// 
			// DLN_label
			// 
			this->DLN_label->AutoSize = true;
			this->DLN_label->Location = System::Drawing::Point(208, 134);
			this->DLN_label->Name = L"DLN_label";
			this->DLN_label->Size = System::Drawing::Size(35, 13);
			this->DLN_label->TabIndex = 5;
			this->DLN_label->Text = L"label1";
			// 
			// Client_menu
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(875, 261);
			this->Controls->Add(this->Full_name_label);
			this->Controls->Add(this->button_load);
			this->Controls->Add(this->dataGridView1);
			this->Controls->Add(this->button_Exit);
			this->Controls->Add(this->button_back);
			this->Controls->Add(this->DLN_label);
			this->Name = L"Client_menu";
			this->Text = L"Client_menu";
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->dataGridView1))->EndInit();
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion
private: System::Void button_load_Click(System::Object^ sender, System::EventArgs^ e);
private: System::Void button_back_Click(System::Object^ sender, System::EventArgs^ e);
private: System::Void button_Exit_Click(System::Object^ sender, System::EventArgs^ e);
};
}
