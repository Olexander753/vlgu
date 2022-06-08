#include "Add_Food_Form.h"
#include <iostream>
#include "Connection.h"
#include "Food.h"
#include "Animal.h"

System::Void Zoo::Add_Food_Form::button_Add_Click(System::Object^ sender, System::EventArgs^ e)
{
    setlocale(LC_ALL, "RUS");
    try
    {
        if (textBox_Title->Text == nullptr ||
            textBox_Qty->Text == nullptr ||
            comboBox_Animal == nullptr)
        {
            MessageBox::Show("Введены не все данные!", "Внимание!");
            return;
        }

        Animal^ animal = gcnew Animal;
        Food^ food = gcnew Food;
        
        food->Title = textBox_Title->Text;
        food->Qty = Convert::ToInt32(textBox_Qty->Text);

        String^ ani_id = comboBox_Animal->Text;
        String^ a;
        int j = 0;
        while (ani_id[j] != '-')
        {
            a += Convert::ToString(ani_id[j]);
            j++;
        }
        animal->ID = Convert::ToInt32(a);

        Connection connect;
        connect.ConnectToBD();
        connect.conn->Open();

        String^ cmdText1 = "insert into Food (Title, Qty, FK_ID_Animal) values('" + food->Title + "', " + food->Qty + ", " + animal->ID + ")";
        SqlCommand^ cmd1 = gcnew SqlCommand(cmdText1, connect.conn);

        if (cmd1->ExecuteNonQuery() != 1)
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
