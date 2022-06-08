#include "Update_request_Form.h"
#include <iostream>

System::Void Курсачпотп::Update_request_Form::button_Update_Click(System::Object^ sender, System::EventArgs^ e)
{
    setlocale(LC_ALL, "RUS");
    try
    {
        if (textBox_Brand_of_car == nullptr ||
            textBox_DLN == nullptr ||
            textBox_Mode_of_car == nullptr ||
            textBox_Number_of_car == nullptr ||
            comboBox_Mechanics == nullptr ||
            comboBox_Repair == nullptr)
        {
            MessageBox::Show("Введены не все данные!", "Внимание!");
            return;
        }

        Request^ request = gcnew Request();
        request->ID = Convert::ToInt32(label9->Text);
        request->DLN = Convert::ToDouble(textBox_DLN->Text);
        request->Number = textBox_Number_of_car->Text;
        request->Brand = textBox_Brand_of_car->Text;
        request->Model = textBox_Mode_of_car->Text;
        request->Full_name_ = comboBox_Mechanics->Text;
        request->Title = comboBox_Repair->Text;
        request->Date = Convert::ToString(label12->Text);
        int log_quantity = 0;
        if (label13->Text != "label13")
            log_quantity = Convert::ToInt32(label13->Text);
        Detal^ detal = gcnew Detal();
        Detal^ detal2 = gcnew Detal();
        Repair^ repair = gcnew Repair();
        Mechanic^ mechanic = gcnew Mechanic();

        if (comboBox_Detal->Text != "")
        {
            if (textBox_Quantity_detals != nullptr)
            {
                if (textBox_Quantity_detals->Text == "")
                {
                    MessageBox::Show("Укажите количество деталей", "Ошибка!");
                    return System::Void();
                }
                request->Title_ = comboBox_Detal->Text;
                request->Quantity = Convert::ToInt32(textBox_Quantity_detals->Text);

                String^ detal_id;

                int i = 0;
                while (request->Title_[i] != '-')
                {
                    detal_id += Convert::ToString(request->Title_[i]);
                    i++;
                }

                Connection connect;
                connect.ConnectToBD();
                connect.conn->Open();

                String^ cmdText = "select * from Detail where ID = " + detal_id;
                SqlCommand^ cmd = gcnew SqlCommand(cmdText, connect.conn);

                SqlDataReader^ dbreader = cmd->ExecuteReader();

                if (dbreader->HasRows == false)
                {
                    MessageBox::Show("Ошибка считывания данных", "Ошибка!");
                    dbreader->Close();
                    connect.conn->Close();
                    return System::Void();
                }
                else
                {
                    while (dbreader->Read())
                    {
                        detal->Vender_code = Convert::ToInt32(dbreader["ID"]);
                        detal->Name = Convert::ToString(dbreader["Title"]);
                        detal->Quantity = Convert::ToInt32(dbreader["Quantity"]);
                        detal->Price = Convert::ToDouble(dbreader["Price"]);
                    }

                    dbreader->Close();
                    connect.conn->Close();
                }

                if ((detal->Quantity + log_quantity) < request->Quantity)
                {
                    MessageBox::Show("Недостаточное количество деталей в наличии", "Ошибка!");
                    return System::Void();
                }
            }
        }
        String^ repair_id;

        int j = 0;
        while (request->Title[j] != '-')
        {
            repair_id += Convert::ToString(request->Title[j]);
            j++;
        }

        Connection connect;
        connect.ConnectToBD();
        connect.conn->Open();

        String^ cmdText = "select * from Type_repair where ID = " + repair_id;
        SqlCommand^ cmd = gcnew SqlCommand(cmdText, connect.conn);

        SqlDataReader^ dbreader = cmd->ExecuteReader();

        if (dbreader->HasRows == false)
        {
            MessageBox::Show("Ошибка считывания данных", "Ошибка!");
            dbreader->Close();
            connect.conn->Close();
            return System::Void();
        }
        else
        {
            while (dbreader->Read())
            {
                repair->ID = Convert::ToInt32(dbreader["ID"]);
                repair->Price = Convert::ToDouble(dbreader["Price"]);
                repair->Name = Convert::ToString(dbreader["Title"]);
            }
            dbreader->Close();
            connect.conn->Close();
        }

        Connection connect1;
        connect1.ConnectToBD();
        connect1.conn->Open();

        String^ cmdText1 = "select * from Mechanic where Full_name = '" + request->Full_name_ + "'";
        SqlCommand^ cmd1 = gcnew SqlCommand(cmdText1, connect1.conn);

        SqlDataReader^ dbreader1 = cmd1->ExecuteReader();

        if (dbreader1->HasRows == false)
        {
            MessageBox::Show("Ошибка считывания данных", "Ошибка!");
            dbreader1->Close();
            connect1.conn->Close();
            return System::Void();
        }
        else
        {
            while (dbreader1->Read())
            {
                mechanic->Full_name = request->Full_name_;
                mechanic->P_data = Convert::ToDouble(dbreader1["Passport_data"]);
            }
            dbreader1->Close();
            connect1.conn->Close();
        }
        if (comboBox_Detal->Text != "")
        {
            if (comboBox_Detal->Items[0] != "")
            {
                String^ detal_id = Convert::ToString(comboBox_Detal->Text);
                String^ detal_id_2;

                int i = 0;
                while (detal_id[i] != '-')
                {
                    detal_id_2 += Convert::ToString(detal_id[i]);
                    i++;
                }
                detal2->Vender_code = Convert::ToInt32(detal_id_2);
            }

            int tottal_quantity;

            String^ qwe;
            if (detal->Vender_code != detal2->Vender_code)
            {
                tottal_quantity = detal->Quantity - request->Quantity;
                qwe = "UPDATE Detail Set Quantity = " + detal->Quantity + log_quantity + " where ID =" + detal2->Vender_code;
                qwe += "UPDATE Detail Set Quantity = " + tottal_quantity + " where ID =" + detal->Vender_code;
            }
            else
            {
                tottal_quantity = detal->Quantity - request->Quantity + log_quantity;
                qwe += "UPDATE Detail Set Quantity = " + tottal_quantity + " where ID =" + detal->Vender_code;
            }

            Connection connect2;
            connect2.ConnectToBD();
            connect2.conn->Open();

            int i = 0;
            String^ total_price1;
            String^ total_price2;
            double pr = repair->Price + (detal->Price * request->Quantity);

            total_price1 = Convert::ToString(pr);
            for (int i = 0; i < total_price1->Length; i++)
            {
                if (total_price1[i] != ',')
                    total_price2 += total_price1[i];
                else
                    total_price2 += ".";
            }

            String^ cmdText2 = "begin tran;";
            cmdText2 += " UPDATE Car set Brand = '" + request->Brand + "', Model ='" + request->Model + "', FK_DLN = " + request->DLN + " where Number = '" + request->Number + "';";
            cmdText2 += " UPDATE Repair set Total_price = " + total_price2 + ", Date_ = getdate(), FK_Number = '" + request->Number + "', FK_Passport_data = " + mechanic->P_data + ", FK_ID_repair = " + repair->ID + ", FK_ID_detail = " + detal->Vender_code + ", Quantity = " + request->Quantity + "where Repair.ID = " + request->ID;
            cmdText2 += qwe;
            cmdText2 += " commit ";
            SqlCommand^ cmd2 = gcnew SqlCommand(cmdText2, connect2.conn);

            if (cmd2->ExecuteNonQuery() < 1)
                MessageBox::Show("Ошибка выполнения запроса!", "Ошибка!");
            else
                MessageBox::Show("Данные добалены!", "Готово!");

            connect2.conn->Close();
            this->Hide();
            return System::Void();
        }
        else
        {
            int tottal_quantity = detal->Quantity + log_quantity;
            Connection connect2;
            connect2.ConnectToBD();
            connect2.conn->Open();

            int i = 0;
            String^ total_price1;
            String^ total_price2;

            total_price1 = Convert::ToString(repair->Price);
            for (int i = 0; i < total_price1->Length; i++)
            {
                if (total_price1[i] != ',')
                    total_price2 += total_price1[i];
                else
                    total_price2 += ".";
            }

            String^ cmdText2 = "begin tran;";
            cmdText2 += " UPDATE Car set Brand = '" + request->Brand + "', Model ='" + request->Model + "', FK_DLN = " + request->DLN + " where Number = '" + request->Number + "';";
            cmdText2 += " UPDATE Repair set Total_price = " + total_price2 + ", Date_ = getdate(), FK_Number = '" + request->Number + "', FK_Passport_data = " + mechanic->P_data + ", FK_ID_repair = " + repair->ID + " where ID = " + request->ID;
            cmdText2 += " UPDATE Detail Set Quantity = " + tottal_quantity + " where ID =" + detal->Vender_code;
            cmdText2 += " commit ";

            SqlCommand^ cmd2 = gcnew SqlCommand(cmdText2, connect2.conn);

            if (cmd2->ExecuteNonQuery() < 1)
                MessageBox::Show("Ошибка выполнения запроса!", "Ошибка!");
            else
                MessageBox::Show("Данные добалены!", "Готово!");

            connect2.conn->Close();
            this->Hide();
            return System::Void();
        }
    }
    catch (SqlException^ ex)
    {
        String^ Error = ex->Errors->ToString();
        MessageBox::Show("Проверьте правильность введённыйх данных!", "Ошибка!");
        return System::Void();
    }
}

System::Void Курсачпотп::Update_request_Form::button_back_Click(System::Object^ sender, System::EventArgs^ e)
{
    this->Hide();
    return System::Void();
}

System::Void Курсачпотп::Update_request_Form::button_exit_Click(System::Object^ sender, System::EventArgs^ e)
{
    Application::Exit();
    return System::Void();
}
