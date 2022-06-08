#include <cstdio>
#include <iostream>
#include "binaryRead.h"
#include "binaryWrite.h"
#include "Reader.h"

void processData(vector<int> data, const char* path)
{
	int t[100];
	int t2[100];
	int t3[100];
	int temp;
	int i = 0;

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

	int n;
	cout << endl << "Введиет число ";
	cin >> n;

	ofstream ofs;
	ofs.open(path, ofstream::out | ofstream::trunc);//чистка файла
	ofs.close();
	/* Дописывание в файл */
	int q = 0;
	bin_outstream out2(path);
	for (int k = 0; k < i; k++)//3апись числе меньше введённого в массив т2
	{
		if (t[k] < n)
		{
			t2[q] = t[k];
			q++;
		}
	}
	for (int w = 0; w < i / 2; w++)//3апись числе до середины 
	{
		t3[w] = t[w];
	}
	int e = 0;
	for (int w = i / 2; w < i / 2 + q; w++)//3апись чисел и3 массива т2
	{
		t3[w] = t2[e];
		e++;
	}
	e = i / 2;
	for (int w = i / 2 + q; w < i + q; w++)//3апись отсавшихся числе исходного массива
	{
		t3[w] = t[e];
		e++;
	}

	for (int j = 0; j < q + i; j++)//3апись в банарный файл
	{
		out2 << t3[j];
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
	setlocale(LC_ALL, "RUS");
	try
	{
		//первое 3адание
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



		//второе
		Reader a(1, "q", "xxx", 2005, 4);//со3даём книги
		Reader b(2, "w", "ttt", 2007, 5);
		Reader c(3, "r", "yyy", 2005, 1);
		Reader d(4, "q", "zzz", 2006, 8);

		vector<Reader> r;
		r.push_back(a); //толкаем в вектор
		r.push_back(b);
		r.push_back(c);
		r.push_back(d);

		read(r);
		write(r);

		place(r, "q", "xxx");

		books_autor(r, "w");

		books_year(r, 2005);
	}
	catch (Exception& exp) {
		exp.printError();
	}
	return 0;
}
