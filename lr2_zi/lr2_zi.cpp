#include <iostream>
#include <string>
#include <fstream>
#include <vector>

using namespace std;

vector <int> num_seq_1;
vector <int> num_seq_2;

void Print_matrix(string* matrix, int n, int m, vector<int> v1, vector<int> v2)
{
    cout << "  ";
    for (unsigned int i = 0; i < v2.size(); i++)
        cout << v2[i] << " ";
    cout << endl;
    for (int i = 0; i < n; i++)
    {
        cout << v1[i] << " ";
        for (int j = 0; j < m; j++)
            cout << matrix[i][j] << " ";
        cout << endl;
    }
    cout << endl;
}



int main()
{
    setlocale(LC_ALL, "rus");

    try
    {
        char sym;
        string f_name_nums_seq, f_name_text, buff;

        //cin >> f_name_nums_seq;
        f_name_nums_seq = "1.txt";
        ifstream in_num_seq(f_name_nums_seq);

        if (in_num_seq.is_open())
        {
            while (!in_num_seq.eof())
            {
                in_num_seq.get(sym);
                if (in_num_seq.eof())
                    break;
                while (sym != ' ' && sym != '\n' && sym != '\t')
                {
                    buff = sym;
                    num_seq_1.push_back(stoi(buff));
                    in_num_seq.get(sym);
                }
                while (sym == ' ' || sym == '\n' || sym == '\t')
                {
                    in_num_seq.get(sym);
                }
                while (!in_num_seq.eof())
                {
                    buff = sym;
                    num_seq_2.push_back(stoi(buff));
                    in_num_seq.get(sym);
                }
            }
        }
        else
        {
            throw("Error! File whith nums sequenses can not open!");
        }
        in_num_seq.close();

        int capacity_1 = num_seq_1.size();
        int capacity_2 = num_seq_2.size();
        int capacity_3 = capacity_1 * capacity_2;

        f_name_text = "D:/Go/text.txt";
        //cin >> f_name_text;
        ifstream in_text(f_name_text);
        ofstream out("shifr.txt");
        //char* text = new char [capacity_1 * capacity_2];
        string* text = new string[capacity_2];
        string z;
        char* text2 = new char[capacity_1 * capacity_2];
        char* tmp1 = new char[capacity_1];
        string tmp2;
        vector <int> copy_num_seq_1;
        vector <int> copy_num_seq_2;
        int tmp3;

        

        if (in_text.is_open())
        {
            while (!in_text.eof())
            {
                copy_num_seq_1 = num_seq_1;
                copy_num_seq_2 = num_seq_2;

                for (int i = 0; i < capacity_1; i++)
                {
                    in_text.read(tmp1, capacity_2);
                    for (int j = 0; j < capacity_2; j++)
                    {
                        text[i] += tmp1[j];
                        tmp1[j] = ' ';
                    }
                }
                //Print_matrix(text, capacity_1, capacity_2, num_seq_1, num_seq_2);

                for (int i = 0; i < capacity_1; i++)
                {
                    for (int j = (capacity_1 - 1); j >= (i + 1); j--)
                    {
                        if (copy_num_seq_1[j] < copy_num_seq_1[j - 1])
                        {
                            tmp3 = copy_num_seq_1[j];
                            copy_num_seq_1[j] = copy_num_seq_1[j - 1];
                            copy_num_seq_1[j - 1] = tmp3;

                            tmp2 = text[j];
                            text[j] = text[j - 1];
                            text[j - 1] = tmp2;
                        }
                    }
                }
                //Print_matrix(text, capacity_1, capacity_2, copy_num_seq_1, num_seq_2);

                for (int i = 0; i < capacity_2; i++)
                {
                    for (int j = (capacity_2 - 1); j >= (i + 1); j--)
                    {
                        if (copy_num_seq_2[j] < copy_num_seq_2[j - 1])
                        {
                            tmp3 = copy_num_seq_2[j];
                            copy_num_seq_2[j] = copy_num_seq_2[j - 1];
                            copy_num_seq_2[j - 1] = tmp3;
                            for (int g = 0; g < capacity_1; g++)
                            {
                                tmp2 = text[g][j];
                                text[g][j] = text[g][j - 1];
                                text[g][j - 1] = tmp2[0];
                            }
                        }
                    }
                }
                for (unsigned int i = 0; i < num_seq_1.size(); i++)
                {
                    out.write(text[i].c_str(), num_seq_2.size());
                }
                //Print_matrix(text, capacity_1, capacity_2, copy_num_seq_1, copy_num_seq_2);
                for (unsigned int i = 0; i < num_seq_1.size(); i++)
                {
                    text[i].clear();
                }
                copy_num_seq_1.clear();
                copy_num_seq_2.clear();
                //break;
            }
        }
        else
        {
            throw("Error! File whith text can not open!");
        }
        in_text.close();
        out.close();

    }
    catch (const char* err)
    {
        cerr << err << endl;
    }
}