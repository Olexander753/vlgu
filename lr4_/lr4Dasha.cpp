#include <cstdio>
#include <iostream>
#include "binaryRead.h"
#include "binaryWrite.h"
#include "Train.h"
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
	ofs.open(path, ofstream::out | ofstream::trunc);
	ofs.close();
	/* Дописывание в файл */
	bin_outstream out2(path);
	for (int k = 0; k < i; k++) 
	{
		if (t[k] % 2 == 1)
		{
			t2[k-l] = t[k];
			j++;
		}
		else
		{
			l++;
		}
	}
	for (int w = j - i; w < j; w++)
	{
		t2[w] = t[w - (j - i)];
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

		Train a(33, "x", 7, 1, 60, 5);
		Train b(34, "qw34e", 8, 12, 40, 8);
		Train c(35, "qwdase", 9, 8, 60, 9);
		Train d(36, "x", 11, 1, 65, 1);

		vector<Train> r;
		vector<Train> e;
		r.push_back(a);
		r.push_back(b);
		r.push_back(c);
		r.push_back(d);

		/* Запись и чтение структуры */
		writeData("Train.dat", r);
		readData("Train.dat", e);

		timetoroud(e, "x", 7, 0, 11, 33);

		havetikkets(e, 36);
	}
	catch (const char* error)
	{
		cout << error << endl;
	}
}
