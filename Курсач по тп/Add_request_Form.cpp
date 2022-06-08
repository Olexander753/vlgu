#include "Add_request_Form.h"
#include <iostream>

System::Void Курсачпотп::Add_request_Form::button_Add_Click(System::Object^ sender, System::EventArgs^ e)
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
        request->DLN = Convert::ToDouble(textBox_DLN->Text);
        request->Number = textBox_Number_of_car->Text;
        request->Brand = textBox_Brand_of_car->Text;
        request->Model = textBox_Mode_of_car->Text;
        request->Full_name_ = comboBox_Mechanics->Text;
        request->Title = comboBox_Repair->Text;
        Detal det;
        Repair re;
        Mechanic me;

        Connection connect_;
        connect_.ConnectToBD();
        connect_.conn->Open();

        String^ cmdText_ = "select * from Client where DLN = " + request->DLN;
        SqlCommand^ cmd_ = gcnew SqlCommand(cmdText_, connect_.conn);

        SqlDataReader^ dbreader_ = cmd_->ExecuteReader();
        if (dbreader_->HasRows == false)
        {
            MessageBox::Show("Такой клиент отсутствует в базе, внесите его данные!", "Ошибка!");
            dbreader_->Close();
            connect_.conn->Close();

            Add_client_Form^ Add_client_form1 = gcnew Add_client_Form;
            Add_client_form1->textBox_DLN->Text = Convert::ToString(request->DLN);
            Add_client_form1->Show();
            return System::Void();
        }


        if (comboBox_Detal->Text != "")
        {
            if (textBox_Quantity_detals != nullptr)
            {
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
                        det.Quantity = Convert::ToInt32(dbreader["Quantity"]);
                        det.Price = Convert::ToDouble(dbreader["Price"]);
                    }

                    dbreader->Close();
                    connect.conn->Close();
                }

                if (det.Quantity < request->Quantity)
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
                re.ID = Convert::ToInt32(dbreader["ID"]);
                re.Price = Convert::ToDouble(dbreader["Price"]);
                re.Name = Convert::ToString(dbreader["Title"]);
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
            return System::Void();
        }
        else
        {
            while (dbreader1->Read())
            {
                me.Full_name = request->Full_name_;
                me.P_data = Convert::ToDouble(dbreader1["Passport_data"]);
            }
            dbreader1->Close();
        }

        String^ car_;
        String^ cmdText3 = "select * from Car where Number = '" + request->Number + "'";
        SqlCommand^ cmd3 = gcnew SqlCommand(cmdText3, connect1.conn);

        SqlDataReader^ dbreader3 = cmd3->ExecuteReader();

        if (dbreader3->HasRows == false)
        {
            car_ = " insert into Car values('" + request->Number + "', '" + request->Brand + "', '" + request->Model + "', " + request->DLN + ");";
        }
        else
        {
            car_ = " ";
        }
        dbreader3->Close();


        if (comboBox_Detal->Text != "")
        {
            int l = det.Quantity - request->Quantity;

            Connection connect2;
            connect2.ConnectToBD();
            connect2.conn->Open();

            int i = 0;
            String^ s;
            String^ s2;
            double pr = re.Price + (det.Price * request->Quantity);

            s = Convert::ToString(pr);
            for (int i = 0; i < s->Length; i++)
            {
                if (s[i] != ',')
                    s2 += s[i];
                else
                    s2 += ".";
            }

            String^ cmdText2 = "begin tran;";
            cmdText2 += car_;
            cmdText2 += " insert into Repair(Status_, Total_price, Date_, FK_Number, FK_Passport_data, FK_ID_repair, FK_ID_detail, Quantity) values('Не готово', " + s2 + ", getdate(), '" + request->Number + "', " + me.P_data + ", " + re.ID + ", " + det.Vender_code + ", " + request->Quantity + ")";
            cmdText2 += " UPDATE Detail Set Quantity = " + l + " where ID =" + det.Vender_code;
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
            Connection connect2;
            connect2.ConnectToBD();
            connect2.conn->Open();

            int i = 0;
            String^ s;
            String^ s2;
            double pr = re.Price + (det.Price * request->Quantity);

            s = Convert::ToString(pr);
            for (int i = 0; i < s->Length; i++)
            {
                if (s[i] != ',')
                    s2 += s[i];
                else
                    s2 += ".";
            }

            String^ cmdText_rollback;
            String^ cmdText_commit;

            String^ cmdText2 = "begin tran;";
            cmdText2 += car_;
            cmdText2 += " insert into Repair(Status_, Total_price, Date_, FK_Number, FK_Passport_data, FK_ID_repair) values('Не готово', " + s2 + ", getdate(), '" + request->Number + "', " + me.P_data + ", " + re.ID + ")";
            cmdText_rollback = cmdText2 + "rollback";

            SqlCommand^ cmd = gcnew SqlCommand(cmdText_rollback, connect2.conn);

            if (cmd->ExecuteNonQuery() < 1)
            {
                MessageBox::Show("Ошибка выполнения запроса!", "Ошибка!");
            }
            else
            {
                cmdText_commit = cmdText2 + "commit";
                SqlCommand^ cmd1 = gcnew SqlCommand(cmdText_commit, connect2.conn);
                if (cmd1->ExecuteNonQuery() == 2)
                    MessageBox::Show("Данные добалены!", "Готово!");
            }

            connect2.conn->Close();
            this->Hide();
            return System::Void();
        }
    }
    catch (SqlException^ ex)
    {
        String^ Error = ex->Errors->ToString();
        MessageBox::Show("Проверьте правильность введённыйх данных! \n "+ex, "Ошибка!");
        return System::Void();
    }
}

System::Void Курсачпотп::Add_request_Form::button_exit_Click(System::Object^ sender, System::EventArgs^ e)
{
    Application::Exit();
    return System::Void();
}

System::Void Курсачпотп::Add_request_Form::button_back_Click(System::Object^ sender, System::EventArgs^ e)
{
    this->Hide();
    return System::Void();
}
