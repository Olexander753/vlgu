#pragma once
#include "Staff_list.h"
#include "Repairs_list.h"
#include "Detals_list.h"

namespace Курсачпотп {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;

	/// <summary>
	/// Сводка для admin_menu
	/// </summary>
	public ref class admin_menu : public System::Windows::Forms::Form
	{
	public:
		admin_menu(void)
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
		~admin_menu()
		{
			if (components)
			{
				delete components;
			}
		}
	private: System::Windows::Forms::Button^ button_back;
	private: System::Windows::Forms::Button^ button_exit;
	private: System::Windows::Forms::Button^ button_Staff;
	private: System::Windows::Forms::Button^ button_Repair;
	private: System::Windows::Forms::Button^ button_Detals;





	protected:


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
			this->button_back = (gcnew System::Windows::Forms::Button());
			this->button_exit = (gcnew System::Windows::Forms::Button());
			this->button_Staff = (gcnew System::Windows::Forms::Button());
			this->button_Repair = (gcnew System::Windows::Forms::Button());
			this->button_Detals = (gcnew System::Windows::Forms::Button());
			this->SuspendLayout();
			// 
			// button_back
			// 
			this->button_back->Location = System::Drawing::Point(15, 190);
			this->button_back->Name = L"button_back";
			this->button_back->Size = System::Drawing::Size(100, 25);
			this->button_back->TabIndex = 0;
			this->button_back->Text = L"Назад";
			this->button_back->UseVisualStyleBackColor = true;
			this->button_back->Click += gcnew System::EventHandler(this, &admin_menu::button_back_Click);
			// 
			// button_exit
			// 
			this->button_exit->Location = System::Drawing::Point(150, 190);
			this->button_exit->Name = L"button_exit";
			this->button_exit->Size = System::Drawing::Size(100, 25);
			this->button_exit->TabIndex = 1;
			this->button_exit->Text = L"Выход";
			this->button_exit->UseVisualStyleBackColor = true;
			this->button_exit->Click += gcnew System::EventHandler(this, &admin_menu::button_exit_Click);
			// 
			// button_Staff
			// 
			this->button_Staff->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 9.75F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->button_Staff->Location = System::Drawing::Point(15, 20);
			this->button_Staff->Name = L"button_Staff";
			this->button_Staff->Size = System::Drawing::Size(235, 30);
			this->button_Staff->TabIndex = 2;
			this->button_Staff->Text = L"Персонал";
			this->button_Staff->UseVisualStyleBackColor = true;
			this->button_Staff->Click += gcnew System::EventHandler(this, &admin_menu::button_Staff_Click);
			// 
			// button_Repair
			// 
			this->button_Repair->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 9.75F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->button_Repair->Location = System::Drawing::Point(15, 70);
			this->button_Repair->Name = L"button_Repair";
			this->button_Repair->Size = System::Drawing::Size(235, 30);
			this->button_Repair->TabIndex = 3;
			this->button_Repair->Text = L"Виды ремонта";
			this->button_Repair->UseVisualStyleBackColor = true;
			this->button_Repair->Click += gcnew System::EventHandler(this, &admin_menu::button_Repair_Click);
			// 
			// button_Detals
			// 
			this->button_Detals->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 9.75F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->button_Detals->Location = System::Drawing::Point(15, 120);
			this->button_Detals->Name = L"button_Detals";
			this->button_Detals->Size = System::Drawing::Size(235, 30);
			this->button_Detals->TabIndex = 4;
			this->button_Detals->Text = L"Детали";
			this->button_Detals->UseVisualStyleBackColor = true;
			this->button_Detals->Click += gcnew System::EventHandler(this, &admin_menu::button_Detals_Click);
			// 
			// admin_menu
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(264, 221);
			this->Controls->Add(this->button_Detals);
			this->Controls->Add(this->button_Repair);
			this->Controls->Add(this->button_Staff);
			this->Controls->Add(this->button_exit);
			this->Controls->Add(this->button_back);
			this->Name = L"admin_menu";
			this->Text = L"Меню администратора";
			this->FormClosed += gcnew System::Windows::Forms::FormClosedEventHandler(this, &admin_menu::admin_menu_FormClosed);
			this->ResumeLayout(false);

		}
#pragma endregion
private: System::Void button_back_Click(System::Object^ sender, System::EventArgs^ e);
private: System::Void button_exit_Click(System::Object^ sender, System::EventArgs^ e);
private: System::Void admin_menu_FormClosed(System::Object^ sender, System::Windows::Forms::FormClosedEventArgs^ e);
private: System::Void button_Staff_Click(System::Object^ sender, System::EventArgs^ e);
private: System::Void button_Repair_Click(System::Object^ sender, System::EventArgs^ e);
private: System::Void button_Detals_Click(System::Object^ sender, System::EventArgs^ e);
};
}
