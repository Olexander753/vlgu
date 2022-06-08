#pragma once
#include <iostream> 
#include <vector> 
#include <fstream>
#include "Exception.h"
using namespace std;

class Reader
{
	int id, num, year; // шифр книги. год издания, местоположение (номер стеллажа).
	char autor[20], name[20]; // автор. название

public:
	Reader() = default;
	Reader(int iid, const char* iautor, const char* iname, int iyear, int inum);
	~Reader() = default;
	friend void write(vector<Reader> item); //3аписывает в файл
	friend void read(vector<Reader>& item); //читает и3 файла
	friend istream& operator>> (istream& in, Reader& item); //перегру3ка оператора ввода
	friend ostream& operator<< (ostream& out, Reader& item); //перегру3ка оператора вывода
	friend void place(vector<Reader> item, const char* iautor, const char* name);  //местоположение книги, автора X названия Y;
	friend void books_autor(vector<Reader> item, const char* iautor);              //список книг автора Z, находящихся в коллекции;
	friend void books_year(vector<Reader> item, int iyear);                        //число книг издания XX года, имеющихся в библиотеке.

};

Reader::Reader(int iid, const char* iautor, const char* iname, int iyear, int inum)
{
	id = iid;
	strcpy_s(autor, iautor);
	strcpy_s(name, iname);
	year = iyear;
	num = inum;
}

istream& operator>>(istream& in, Reader& item)
{
	cout << "Информация о личной коллекции книголюба:" << endl;
	cout << "шифр книги: ";
	in >> item.id;
	cout << "автор: ";
	in >> item.autor;
	cout << "название: ";
	in >> item.name;
	cout << "год издания:";
	in >> item.year;
	cout << "местоположение (номер стеллажа): ";
	in >> item.num;
	return in;
}

ostream& operator<<(ostream& out, Reader& item)
{
	out << endl << "Информация о личной коллекции книголюба: " << endl;
	out << "шифр книги: " << item.id << endl;
	out << "автор: " << item.autor << endl;
	out << "название: " << item.name << endl;
	out << "год издания:" << item.year << endl;
	out << "местоположение (номер стеллажа): " << item.num << endl;
	return out;
}

void write(vector<Reader> item)
{
	ofstream fout;
	fout.open("Reader.dat", ofstream::app | ofstream::binary);

	for (int i = 0; i < item.size(); i++) {
		fout.write((char*)&item[i], sizeof(Reader));
	}

	fout.close();
}

void read(vector<Reader>& item)
{
	ifstream fin;
	fin.open("Reader.dat", ifstream::in | ifstream::binary);
	int i{ 0 };
	Reader temp;

	while (fin.read((char*)&temp, sizeof(Reader))) {
		item.push_back(temp);
		i++;
	}

	fin.close();
}

void place(vector<Reader> item, const char* iautor, const char* iname)
{
	int k = 0, m = 0, s = 0;
	char a[20], n[20];
	strcpy_s(a, iautor);
	strcpy_s(n, iname);
	for (int i = 0; i < item.size(); i++)
	{
		int j = 0;
		while (item[i].autor[j] != '\0')//сравниваем автора
		{
			k = 0;
			if (item[i].autor[j] == a[j])
			{
				k = 1;
			}
			j++;
		}
		int q = 0;
		while (item[i].name[q] != '\0')//сравниваем имя
		{
			m = 0;
			if (item[i].name[q] == n[q])
			{

				m = 1;
			}
			q++;
		}
		if (k == 1 && m == 1) //если совпадает на3вание и автор выводим
		{
			cout << "Книга " << iname << " автора " << iautor << " находится на стилаже №" << item[i].num << endl;
			s++;
		}

	}
	if (s == 0)
		throw Exception(HAVE_NOT_BOOK, "Тaкой книги нет");
}

void books_autor(vector<Reader> item, const char* iautor)
{
	int k = 0, s = 0;
	char a[20];
	strcpy_s(a, iautor);
	cout << "Автор " << iautor << endl;
	for (int i = 0; i < item.size(); i++)
	{
		int j = 0;
		while (item[i].autor[j] != '\0')//сравниваем автора
		{
			k = 0;
			if (item[i].autor[j] == a[j])
			{
				k = 1;
			}
			j++;
		}
		if (k == 1) // если такой автор есть выводим его книгу
		{
			cout << "Книга " << item[i].name << endl;
			s++;
		}
	}
	if (s == 0)
		throw Exception(HAVE_NOT_BOOK, "Ккниг данного автора нет");
}
void books_year(vector<Reader> item, int iyear)
{
	int k = 0;
	for (int i = 0; i < item.size(); i++)
	{
		if (item[i].year == iyear)//сравниваем год
			k++;
	}
	if (k == 0)
		throw Exception(HAVE_NOT_BOOK, "Книг данного года нет");
	else
		cout << "В коллеккции есть " << k << " книги " << iyear << " года" << endl; // есть такой год выводим год и кол-ао книг
}