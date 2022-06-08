#include "admin_menu.h"

System::Void Курсачпотп::admin_menu::button_back_Click(System::Object^ sender, System::EventArgs^ e)
{
    Owner->Show();
    this->Hide();
    return System::Void();
}

System::Void Курсачпотп::admin_menu::button_exit_Click(System::Object^ sender, System::EventArgs^ e)
{
    Application::Exit();
    return System::Void();
}

System::Void Курсачпотп::admin_menu::admin_menu_FormClosed(System::Object^ sender, System::Windows::Forms::FormClosedEventArgs^ e)
{
    Application::Exit();
    return System::Void();
}

System::Void Курсачпотп::admin_menu::button_Staff_Click(System::Object^ sender, System::EventArgs^ e)
{
    Staff_list^ Staff_list_Frorm = gcnew Staff_list;
    Staff_list_Frorm->Show();
    Staff_list_Frorm->Owner = this;
    this->Hide();
    return System::Void();
}

System::Void Курсачпотп::admin_menu::button_Repair_Click(System::Object^ sender, System::EventArgs^ e)
{
    Repairs_list^ Repairs_list_Frorm = gcnew Repairs_list;
    Repairs_list_Frorm->Show();
    Repairs_list_Frorm->Owner = this;
    this->Hide();
    return System::Void();
}

System::Void Курсачпотп::admin_menu::button_Detals_Click(System::Object^ sender, System::EventArgs^ e)
{
    Detals_list^ Detals_list_Frorm = gcnew Detals_list;
    Detals_list_Frorm->Show();
    Detals_list_Frorm->Owner = this;
    this->Hide();
    return System::Void();
}
