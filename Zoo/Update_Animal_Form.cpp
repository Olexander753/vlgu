#include "Update_Animal_Form.h"
#include <iostream>
#include "Connection.h"
#include "Animal.h"

System::Void Zoo::Update_Animal_Form::button1_Click(System::Object^ sender, System::EventArgs^ e)
{
    setlocale(LC_ALL, "RUS");
    try
    {
        if (textBox_Name->Text == nullptr ||
            textBox_View == nullptr || 
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
        animal->ID = Convert::ToInt32(label5->Text);

        Connection connect;
        connect.ConnectToBD();
        connect.conn->Open();

        String^ cmdText = "UPDATE Animal set Name_ = '"+ animal->Name +"', View_ = '"+ animal->View +"', Feeding_status = '"+ animal->Feed_status +"', Health_status = '"+ animal->Health_status +"' where ID = " + animal->ID;
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
        MessageBox::Show("Проверьте правильность введённыйх данных!\n " + ex + "", "Ошибка!");
        return System::Void();
    }
}

System::Void Zoo::Update_Animal_Form::Update_Animal_Form_FormClosed(System::Object^ sender, System::Windows::Forms::FormClosedEventArgs^ e)
{
    return System::Void();
}
