#pragma once
#include "admin_menu.h"
#include "main_menu.h"
#include "Client_menu.h"
#include "Mechanic_menu.h"
#include "Functions.h"

namespace Курсачпотп {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;
	using namespace Data;
	using namespace Data::SqlClient;

	/// <summary>
	/// Сводка для authorization
	/// </summary>
	public ref class authorization : public System::Windows::Forms::Form
	{
	public:
		authorization(void)
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
		~authorization()
		{
			if (components)
			{
				delete components;
			}
		}
	private: System::Windows::Forms::TextBox^ textBox_login;



	protected:


	private: System::Windows::Forms::Label^ label1;
	private: System::Windows::Forms::Label^ label2;
	private: System::Windows::Forms::Button^ button_join;
	private: System::Windows::Forms::TextBox^ textBox_password;

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
			this->textBox_login = (gcnew System::Windows::Forms::TextBox());
			this->label1 = (gcnew System::Windows::Forms::Label());
			this->label2 = (gcnew System::Windows::Forms::Label());
			this->button_join = (gcnew System::Windows::Forms::Button());
			this->textBox_password = (gcnew System::Windows::Forms::TextBox());
			this->SuspendLayout();
			// 
			// textBox_login
			// 
			this->textBox_login->Location = System::Drawing::Point(15, 75);
			this->textBox_login->Name = L"textBox_login";
			this->textBox_login->Size = System::Drawing::Size(255, 20);
			this->textBox_login->TabIndex = 0;
			// 
			// label1
			// 
			this->label1->AutoSize = true;
			this->label1->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 14.25F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->label1->Location = System::Drawing::Point(15, 45);
			this->label1->Name = L"label1";
			this->label1->Size = System::Drawing::Size(69, 24);
			this->label1->TabIndex = 2;
			this->label1->Text = L"Логин:";
			// 
			// label2
			// 
			this->label2->AutoSize = true;
			this->label2->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 14.25F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->label2->Location = System::Drawing::Point(15, 110);
			this->label2->Name = L"label2";
			this->label2->Size = System::Drawing::Size(81, 24);
			this->label2->TabIndex = 3;
			this->label2->Text = L"Пароль:";
			// 
			// button_join
			// 
			this->button_join->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 14.25F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->button_join->Location = System::Drawing::Point(80, 185);
			this->button_join->Name = L"button_join";
			this->button_join->Size = System::Drawing::Size(120, 35);
			this->button_join->TabIndex = 4;
			this->button_join->Text = L"Войти";
			this->button_join->UseVisualStyleBackColor = true;
			this->button_join->Click += gcnew System::EventHandler(this, &authorization::button_join_Click);
			// 
			// textBox_password
			// 
			this->textBox_password->Location = System::Drawing::Point(15, 140);
			this->textBox_password->Name = L"textBox_password";
			this->textBox_password->PasswordChar = '*';
			this->textBox_password->Size = System::Drawing::Size(255, 20);
			this->textBox_password->TabIndex = 5;
			// 
			// authorization
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(284, 241);
			this->Controls->Add(this->textBox_password);
			this->Controls->Add(this->button_join);
			this->Controls->Add(this->label2);
			this->Controls->Add(this->label1);
			this->Controls->Add(this->textBox_login);
			this->Name = L"authorization";
			this->Text = L"Авторизация";
			this->FormClosed += gcnew System::Windows::Forms::FormClosedEventHandler(this, &authorization::authorization_FormClosed);
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion
private: System::Void button_join_Click(System::Object^ sender, System::EventArgs^ e);
private: System::Void authorization_FormClosed(System::Object^ sender, System::Windows::Forms::FormClosedEventArgs^ e);
};
}
