#include <string>
#include <iostream>
#include <fstream>
#include <stdlib.h>
#include <omp.h>

using namespace std;

double start_time;

int comp1(const void* a, const void* b)
{
	return(*(int*)a - *(int*)b);
}

void func1 (string* Matr_sh, string* Matr_sh_, string kluch1, string kluch2, char *S_sh)
{
	for (int i = 0; i < kluch1.size(); i++)
	{
		for (int j = i * kluch2.size(); j < kluch2.size() * (i + 1); j++)
		{
			Matr_sh[i] = Matr_sh[i] + S_sh[j];
			S_sh[j] = ' ';
			Matr_sh_[i] = Matr_sh_[i] + S_sh[j];
		}
	}
}

void func2(string* Matr_sh, string* Matr_sh_, string kluch1, string kluch2, int l, int* B)
{
	for (int i = 0; i < kluch2.size(); i++)
	{
		l = kluch2.find(to_string(B[i]));
		for (int j = 0; j < kluch1.size(); j++)
		{
			Matr_sh_[j][l] = Matr_sh[j][i];
		}
		while (B[i] == B[i + 1])
		{
			i++;
			l = kluch2.find(to_string(B[i]), 1 + l);
			for (int j = 0; j < kluch1.size(); j++)
			{
				Matr_sh_[j][l] = Matr_sh[j][i];
			}
		}
	}
}

void func3(string* Matr_sh_, string* Matr_sh__, string kluch1, string kluch2, int* A)
{
	for (int i = 0; i < kluch1.size(); i++)
	{
		//cout << Matr_sh_[i] << endl;
		Matr_sh__[kluch1.find(to_string(A[i]))] = Matr_sh_[i];
		while (A[i] == A[i + 1])
		{
			i++;
			//cout << Matr_sh_[i] << endl;
			Matr_sh__[kluch1.find(to_string(A[i]), 1 + kluch1.find(to_string(A[i])))] = Matr_sh_[i];
		}

	}
}

void func4(string kluch1, string kluch2, string* Matr_sh, string* Matr_sh_, string* Matr_sh__)
{
	for (int i = 0; i < kluch1.size(); i++)
	{
		Matr_sh[i].erase(0, kluch2.size());
		Matr_sh_[i].erase(0, kluch2.size());
		Matr_sh__[i].erase(0, kluch2.size());
	}
}

int main()
{
	setlocale(LC_ALL, "RUS");

	string kluch1, kluch2, sh, dsh, stroka, buff;
	//453 5645
	//чм ыкяо сти еюс яи  бллю к и ткьуашм
	//cin >> kluch1;
	//cin >> kluch2;
	//cin >> sh;

	kluch1 = "1.txt";
	kluch2 = "2.txt";
	sh = "C:/Users/a8720/source/repos/lr2_zi/lr2_zi/shifr.txt";

	ifstream in_kluch1(kluch1);
	if (in_kluch1.is_open())
	{
		while (!in_kluch1.eof())
		{
			getline(in_kluch1, kluch1);
		}
	}
	in_kluch1.close();

	int* A = new int[kluch1.size()];
	for (int i = 0; i < kluch1.size(); i++)
	{
		buff = kluch1[i];
		A[i] = stoi(buff);
	}
	qsort(A, kluch1.size(), sizeof(int), comp1);


	ifstream in_kluch2(kluch2);
	if (in_kluch2.is_open())
	{
		while (!in_kluch2.eof())
		{
			getline(in_kluch2, kluch2);
		}
	}
	in_kluch2.close();

	int* B = new int[kluch2.size()];
	for (int i = 0; i < kluch2.size(); i++)
	{
		buff = kluch2[i];
		B[i] = stoi(buff);
	}
	qsort(B, kluch2.size(), sizeof(int), comp1);


	char* S_sh = new char[kluch2.size()*kluch1.size()];
	S_sh[kluch2.size()* kluch1.size()] = '\0';
	int k = kluch2.size() * kluch1.size();
	int l = 0;
	string* Matr_sh = new string[kluch1.size()];
	string* Matr_sh_ = new string[kluch1.size()];
	string* Matr_sh__ = new string[kluch1.size()];

	start_time = omp_get_wtime();
	ifstream in_sh(sh);
	ofstream out_dsh("text.txt");
	if (in_sh.is_open())
	{
		while (!in_sh.eof())
		{
			in_sh.read(S_sh, k);
			func1(Matr_sh, Matr_sh_, kluch1, kluch2, S_sh);
			func2(Matr_sh, Matr_sh_, kluch1, kluch2, l, B);
			func3(Matr_sh_, Matr_sh__, kluch1, kluch2, A);
			for (int i = 0; i < kluch1.size(); i++)
				out_dsh << Matr_sh__[i];
			func4(kluch1, kluch2, Matr_sh, Matr_sh_, Matr_sh__);
			if (in_sh.eof())
				break;
		}
	}
	in_sh.close();
	out_dsh.close();
	cout << "Time to deshifr = " << omp_get_wtime() - start_time << endl;
}
