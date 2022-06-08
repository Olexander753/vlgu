#pragma once
#include <iostream>
#include <fstream>
#include <iomanip>
#include "Sort.h"
#include "Exception.h"
using namespace std;

class f
{
	char ch;

public:
	explicit f(const char* path);
	~f() = default;
};

f::f(const char* path)
{
	ifstream in(path, ios::in);
	if (!in.is_open())
		throw Exception(FILE_CANNOT_OPEN, "Error: Can't open file");
	int arr1[50];
	int arr2[50];
	ch = -1;
	int item[8];
	int i = 0, j = 0;
	while (!in.eof()) //цикл пока не конец файла
	{
		int temp = 0;
		while (ch == -1 || ch == ' ' || ch == '\r' || ch == '\n' || ch == '\t')
		{
			in.get(ch);
			if (in.eof()) return;
		}
		while (ch != ' ')//считвает число пока не пробел
		{
			temp = temp * 10;
			temp = temp + ch - '0';
			in.get(ch);
		}
		if (temp % 2 == 0)//проверка на чётность и 3апись в массив 
		{
			arr1[i] = temp;
			i++;
		}
		else
		{
			arr2[j] = temp;
			j++;
		}
		in.get(ch);
	}
	in.close(); //3акрвыем файл

	sort1(arr1, i); //сортируем, сортировкуу вытащил и3 прошлой лабы что бы не 3агромождать тут код, она в отдельном файле
	sort2(arr2, j); //ну и немного усовершенствовал что бы отсортировать по убыванию


	ofstream out("x.txt", ios::out); // открываем первый файл и 3писываем массив чётных чисел
	if (out.is_open())
	{
		for (int q = 0; q < i; q++)
		{
			out << arr1[q] << " ";
		}
	}
	else
	{
		throw Exception(FILE_CANNOT_OPEN, "Ошибка файл не открыт");
	}
	out.close();

	ofstream out1("y.txt", ios::out);// открываем второй файл и 3писываем массив нечётных чисел
	if (out1.is_open())
	{
		for (int q = 0; q < j; q++)
		{
			out1 << arr2[q] << " ";
		}
	}
	else
	{
		throw Exception(FILE_CANNOT_OPEN, "Ошибка файл не открыт");
	}
	out1.close();
}