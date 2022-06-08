#pragma once
#include "Add_detals_Form.h"
#include "Connection.h"

namespace Курсачпотп {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;

	/// <summary>
	/// Сводка для Detals_list
	/// </summary>
	public ref class Detals_list : public System::Windows::Forms::Form
	{
	public:
		Detals_list(void)
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
		~Detals_list()
		{
			if (components)
			{
				delete components;
			}
		}
	private: System::Windows::Forms::DataGridView^ dataGridView1;
	private: System::Windows::Forms::DataGridViewTextBoxColumn^ Vendor_code;
	private: System::Windows::Forms::DataGridViewTextBoxColumn^ Name;
	private: System::Windows::Forms::DataGridViewTextBoxColumn^ Price;
	private: System::Windows::Forms::GroupBox^ groupBox1;
	private: System::Windows::Forms::Button^ button_Delete;
	private: System::Windows::Forms::Button^ button_Edit;

	private: System::Windows::Forms::Button^ button_Back;
	private: System::Windows::Forms::Button^ button_Exit;
	private: System::Windows::Forms::DataGridViewTextBoxColumn^ Quantity;
	private: System::Windows::Forms::Button^ button_load;
	private: System::Windows::Forms::Button^ button_Add;
	protected:

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
			this->Vendor_code = (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
			this->Name = (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
			this->Price = (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
			this->Quantity = (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
			this->groupBox1 = (gcnew System::Windows::Forms::GroupBox());
			this->button_load = (gcnew System::Windows::Forms::Button());
			this->button_Delete = (gcnew System::Windows::Forms::Button());
			this->button_Edit = (gcnew System::Windows::Forms::Button());
			this->button_Add = (gcnew System::Windows::Forms::Button());
			this->button_Back = (gcnew System::Windows::Forms::Button());
			this->button_Exit = (gcnew System::Windows::Forms::Button());
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->dataGridView1))->BeginInit();
			this->groupBox1->SuspendLayout();
			this->SuspendLayout();
			// 
			// dataGridView1
			// 
			this->dataGridView1->ColumnHeadersHeightSizeMode = System::Windows::Forms::DataGridViewColumnHeadersHeightSizeMode::AutoSize;
			this->dataGridView1->Columns->AddRange(gcnew cli::array< System::Windows::Forms::DataGridViewColumn^  >(4) {
				this->Vendor_code,
					this->Name, this->Price, this->Quantity
			});
			this->dataGridView1->Location = System::Drawing::Point(15, 15);
			this->dataGridView1->Name = L"dataGridView1";
			this->dataGridView1->Size = System::Drawing::Size(455, 234);
			this->dataGridView1->TabIndex = 0;
			// 
			// Vendor_code
			// 
			this->Vendor_code->HeaderText = L"Артикул";
			this->Vendor_code->Name = L"Vendor_code";
			// 
			// Name
			// 
			this->Name->HeaderText = L"Название";
			this->Name->Name = L"Name";
			// 
			// Price
			// 
			this->Price->HeaderText = L"Стоимость";
			this->Price->Name = L"Price";
			// 
			// Quantity
			// 
			this->Quantity->HeaderText = L"Количество";
			this->Quantity->Name = L"Quantity";
			// 
			// groupBox1
			// 
			this->groupBox1->Controls->Add(this->button_load);
			this->groupBox1->Controls->Add(this->button_Delete);
			this->groupBox1->Controls->Add(this->button_Edit);
			this->groupBox1->Controls->Add(this->button_Add);
			this->groupBox1->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->groupBox1->Location = System::Drawing::Point(485, 12);
			this->groupBox1->Name = L"groupBox1";
			this->groupBox1->Size = System::Drawing::Size(205, 191);
			this->groupBox1->TabIndex = 1;
			this->groupBox1->TabStop = false;
			this->groupBox1->Text = L"Действия";
			// 
			// button_load
			// 
			this->button_load->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 11.25F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->button_load->Location = System::Drawing::Point(10, 40);
			this->button_load->Name = L"button_load";
			this->button_load->Size = System::Drawing::Size(185, 25);
			this->button_load->TabIndex = 3;
			this->button_load->Text = L"Загрузить/Обновить";
			this->button_load->UseVisualStyleBackColor = true;
			this->button_load->Click += gcnew System::EventHandler(this, &Detals_list::button_load_Click);
			// 
			// button_Delete
			// 
			this->button_Delete->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 11.25F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->button_Delete->Location = System::Drawing::Point(10, 160);
			this->button_Delete->Name = L"button_Delete";
			this->button_Delete->Size = System::Drawing::Size(185, 25);
			this->button_Delete->TabIndex = 2;
			this->button_Delete->Text = L"Удалить";
			this->button_Delete->UseVisualStyleBackColor = true;
			this->button_Delete->Click += gcnew System::EventHandler(this, &Detals_list::button_Delete_Click);
			// 
			// button_Edit
			// 
			this->button_Edit->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 11.25F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->button_Edit->Location = System::Drawing::Point(10, 120);
			this->button_Edit->Name = L"button_Edit";
			this->button_Edit->Size = System::Drawing::Size(185, 25);
			this->button_Edit->TabIndex = 1;
			this->button_Edit->Text = L"Изменить";
			this->button_Edit->UseVisualStyleBackColor = true;
			this->button_Edit->Click += gcnew System::EventHandler(this, &Detals_list::button_Edit_Click);
			// 
			// button_Add
			// 
			this->button_Add->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 11.25F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->button_Add->Location = System::Drawing::Point(10, 80);
			this->button_Add->Name = L"button_Add";
			this->button_Add->Size = System::Drawing::Size(185, 25);
			this->button_Add->TabIndex = 0;
			this->button_Add->Text = L"Добавить";
			this->button_Add->UseVisualStyleBackColor = true;
			this->button_Add->Click += gcnew System::EventHandler(this, &Detals_list::button_Add_Click);
			// 
			// button_Back
			// 
			this->button_Back->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 9.75F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->button_Back->Location = System::Drawing::Point(485, 225);
			this->button_Back->Name = L"button_Back";
			this->button_Back->Size = System::Drawing::Size(100, 25);
			this->button_Back->TabIndex = 2;
			this->button_Back->Text = L"Назад";
			this->button_Back->UseVisualStyleBackColor = true;
			this->button_Back->Click += gcnew System::EventHandler(this, &Detals_list::button_Back_Click);
			// 
			// button_Exit
			// 
			this->button_Exit->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 9.75F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->button_Exit->Location = System::Drawing::Point(590, 225);
			this->button_Exit->Name = L"button_Exit";
			this->button_Exit->Size = System::Drawing::Size(100, 25);
			this->button_Exit->TabIndex = 3;
			this->button_Exit->Text = L"Выход";
			this->button_Exit->UseVisualStyleBackColor = true;
			this->button_Exit->Click += gcnew System::EventHandler(this, &Detals_list::button_Exit_Click);
			// 
			// Detals_list
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(704, 261);
			this->Controls->Add(this->button_Exit);
			this->Controls->Add(this->button_Back);
			this->Controls->Add(this->groupBox1);
			this->Controls->Add(this->dataGridView1);
			//this->Name = L"Detals_list";
			this->Text = L"Детали";
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->dataGridView1))->EndInit();
			this->groupBox1->ResumeLayout(false);
			this->ResumeLayout(false);

		}
#pragma endregion
private: System::Void button_load_Click(System::Object^ sender, System::EventArgs^ e);
private: System::Void button_Add_Click(System::Object^ sender, System::EventArgs^ e);
private: System::Void button_Edit_Click(System::Object^ sender, System::EventArgs^ e);
private: System::Void button_Delete_Click(System::Object^ sender, System::EventArgs^ e);
private: System::Void button_Back_Click(System::Object^ sender, System::EventArgs^ e);
private: System::Void button_Exit_Click(System::Object^ sender, System::EventArgs^ e);
};
}
