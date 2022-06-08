#include "Add_Animal_Form.h"
#include "Animal.h"
#include "Connection.h"
#include <iostream>

System::Void Zoo::Add_Animal_Form::button1_Click(System::Object^ sender, System::EventArgs^ e)
{
    setlocale(LC_ALL, "RUS");
    try
    {
        if (textBox_Name->Text == nullptr ||
            textBox_View->Text == nullptr ||
            textBox_Status_Feeding == nullptr ||
            textBox_Status_helth == nullptr)
        {
            MessageBox::Show("Введены не все данные!", "Внимание!");
            return;
        }

        Animal^ animal = gcnew Animal;

        animal->Name = textBox_Name->Text;
        animal->View = textBox_View->Text;
        animal->Feed_status = textBox_Status_Feeding->Text;
        animal->Health_status = textBox_Status_helth->Text;

        String^ Zoo_ID = label5->Text;
        String^ Em_ID = label6->Text;

        Connection connect;
        connect.ConnectToBD();
        connect.conn->Open();

        String^ cmdText = "insert into Animal(Name_, View_, Feeding_status, Health_status, FK_Service_number_Employee, FK_ID_Zoo) values  ('"+animal->Name+"', '"+animal->View+"', '"+animal->Feed_status+"', '"+animal->Health_status+"', "+Em_ID+", "+Zoo_ID+")";
        SqlCommand^ cmd = gcnew SqlCommand(cmdText, connect.conn);

        if (cmd->ExecuteNonQuery() < 1)
        {
            MessageBox::Show("Ошибка выполнения запроса!", "Ошибка!");
        }
        else
        {
            MessageBox::Show("Данные добалены!", "Готово!");
        }

        connect.conn->Close();
        this->Hide();
        return System::Void();
    }
    catch (SqlException^ ex)
    {
        String^ Error = ex->Errors->ToString();
        MessageBox::Show("Проверьте правильность введённыйх данных!\n "+ex+"", "Ошибка!");
        return System::Void();
    }
}

System::Void Zoo::Add_Animal_Form::Add_Animal_Form_FormClosed(System::Object^ sender, System::Windows::Forms::FormClosedEventArgs^ e)
{
    return System::Void();
}
