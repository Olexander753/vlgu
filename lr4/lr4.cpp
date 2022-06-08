#include <cstdio>
#include <iostream>
#include "binaryRead.h"
#include "binaryWrite.h"
#include "Attackers.h"
#include <vector>

void processData(vector<int> data, const char* path)
{
	int t[100];
	int t2[100];
	int temp;
	int i = 0;
	int j = 0;
	int l = 0;

	/* Запись в файл */
	bin_outstream out1(path);
	for (int k = 0; k < data.size(); k++)
	{
		out1 << data[k];
	}
	out1.close();


	cout << "Old: ";
	/* Чтение из файла */
	bin_instream in1(path);
	in1 >> temp;
	while (!in1.eof())
	{
		t[i] = temp;
		i++;
		cout << temp << " ";
		in1 >> temp;
	}
	in1.close();


	cout << endl;

	j = i;
	ofstream ofs;
	ofs.open("text.dat", ofstream::out | ofstream::trunc);
	ofs.close();
	/* Сортировка в файле */
	bin_outstream out2(path);
	for (int k = 0; k < i; k = k + 2)
	{
		t2[k] = t[k+1];
	}
	for (int k = 1; k < i; k = k + 2)
	{
		t2[k] = t[k-1];
	}
	for (int q = 0; q < j; q++)
	{
		out2 << t2[q];
	}
	out2.close();

	cout << endl;


	cout << "New: ";
	/* Проверка: считывание из файла */
	i = 0;
	bin_instream in2(path);
	in2 >> temp;
	while (!in2.eof())
	{
		t[i] = temp;
		i++;
		cout << temp << " ";
		in2 >> temp;
	}
	in2.close();
}

int main()
{
	try
	{
		setlocale(LC_ALL, "RUS");

		vector<int> q;
		q.push_back(1);
		q.push_back(2);
		q.push_back(3);
		q.push_back(4);
		q.push_back(5);
		q.push_back(6);
		q.push_back(7);
		q.push_back(8);

		processData(q, "text.dat");





		attackers a("a", 33, 7, 1);
		attackers b("b", 12, 4, 5);
		attackers c("c", 1, 17, 7);
		attackers d("d", 22, 14, 11);
		attackers e("e", 45, 9, 17);
		attackers f("f", 7, 10, 16);
		vector<attackers> z;
		z.push_back(a);
		z.push_back(b);
		z.push_back(c);
		z.push_back(d);
		z.push_back(e);
		z.push_back(f);

		writeData(z);

		readData(z);
		
		best(z);
	}
	catch (const char* error)
	{
		cout << error << endl;
	}
}
