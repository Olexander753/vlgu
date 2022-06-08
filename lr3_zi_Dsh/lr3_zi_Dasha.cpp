#include <iostream>
#include <string>
#include <fstream>
#include <stdlib.h>
#include <omp.h>

using namespace std;

int main()
{
    setlocale(LC_ALL, "RUS");

    double start_time;
    string a, k, sh, dsh;

    a = "D:/Go/1.txt";
    k = "D:/Go/2.txt";
    sh = "D:/Go/shifr.txt";
    dsh = "D:/Go/docode_text.txt";

    ifstream in_a(a);
    if (in_a.is_open())
    {
        while (!in_a.eof())
        {
            getline(in_a, a);
        }
    }
    in_a.close();

    int* a_ = new int[a.size()];

    for (int i = 0; i < a.size(); i++)
    {
        a_[i] = i;
    }

    ifstream in_k(k);
    if (in_k.is_open())
    {
        while (!in_k.eof())
        {
            getline(in_k, k);
        }
    }
    in_k.close();

    int* k_ = new int[k.size()];

    for (int i = 0; i < k.size(); i++)
    {
        k_[i] = a.find(k[i]);
    }

    start_time = omp_get_wtime();
    int N = 1024;
    int n;
    int size_a = a.size();
    int ind_k = 0;
    int index;
    char* text = new char[N];
    ifstream in_sh(sh);
    ofstream out_dsh(dsh);
    string buff;
    string s;
    dsh = "";
    if (in_sh.is_open() && out_dsh.is_open())
    {
        while (!in_sh.eof())
        {
            //in_sh.read(text, N);
            n = N;
            for (int i = 0; i < N; i++)
            {
                in_sh.get(text[i]);
                if (in_sh.eof())
                {
                    n = i;
                    text[i + 1] = '\0';
                    break;
                }
            }
            //s = text;
            for (int i = 0; i < n; i++)
            { 
                index = a.find(text[i]);
                if (index == string::npos)
                {
                    dsh = dsh + text[i];
                }
                else 
                {
                    index = a_[index];
                    if (index == k_[ind_k])
                        index = 0;
                    else
                        index = index + size_a - 1 - k_[ind_k];
                    if (index > size_a - 1)
                        index = index - size_a + 1;
                    //s = a[a.find(text[i]) + a.size() - 1 - k_[cap_k]];
                    dsh = dsh + a[index];
                } 
                ind_k++;
                if (ind_k == k.size())
                    ind_k = 0;
            }
            out_dsh << dsh;
            dsh.clear();
        }

    }
    in_sh.close();
    out_dsh.close();
    cout << "Time to deshifr = " << omp_get_wtime() - start_time << endl;
}