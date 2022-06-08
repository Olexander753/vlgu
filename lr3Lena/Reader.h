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
	friend void place(vector<Reader> item, const char *iautor, const char *name);  //местоположение книги, автора X названия Y;
	friend void books_autor(vector<Reader> item, const char* iautor);              //список книг автора Z, находящихся в коллекции;
	friend void books_year(vector<Reader> item, int iyear);                        //число книг издания XX года, имеющихся в библиотеке.

};

Reader::Reader(int iid,  const char* iautor, const char* iname, int iyear, int inum)
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
	ofstream out("Reader1.txt", ios::out);//открываем файл 
	if (!out)
	{
		throw Exception(FILE_CANNOT_OPEN, "Ошибка файл не открыт");
	}
	for (int i = 0; i < item.size(); i++) //3аписывем чере3 цикл
	{
		out << item[i].id << " " << item[i].name << " " << item[i].autor << " " << item[i].year << " " << item[i].num << endl;
	}
	out.close();
}

void read(vector<Reader>& item)
{
	ifstream in("Reader2.txt", ios::in);//открываем файл 
	if (!in)
	{
		throw Exception(FILE_CANNOT_OPEN, "Ошибка файл не открыт");
	}
	if (in.eof())
	{
		throw Exception(FILE_IS_EMPTY, "Файл пустой");
	}
	while (!in.eof())//пока не конец файла читаем и3 него
	{
		char sym;
		char info[20];
		int i = 0;
		int c = 0;
		Reader r;

		in.get(sym);
		while (sym != ' ')
		{
			info[i] = sym;
			i++;
			in.get(sym);
		}
		for (int j = 0; j < i; j++)
		{
			c = c * 10;
			c = info[j] - '0' + c;
		}
		r.id = c; //считали шифр книги

		in.get(sym);
		i = 0;
		while (sym != ' ')
		{
			info[i] = sym;
			i++;
			in.get(sym);
		}
		info[i++] = '\0';
		strcpy_s(r.autor, info);//считали автора

		in.get(sym);
		i = 0;
		while (sym != ' ')
		{
			info[i] = sym;
			i++;
			in.get(sym);
		}
		info[i++] = '\0';
		strcpy_s(r.name, info);//считали на3вание

		in.get(sym);
		i = 0;
		c = 0;
		while (sym != ' ')
		{
			info[i] = sym;
			i++;
			in.get(sym);
		}
		for (int j = 0; j < i; j++)
		{
			c = c * 10;
			c = info[j] - '0' + c;
		}
		r.year = c;//считали год

		in.get(sym);
		i = 0;
		c = 0;
		while (sym != ' ' && sym != '\n' && !in.eof())
		{
			info[i] = sym;
			i++;
			in.get(sym);
		}
		for (int j = 0; j < i; j++)
		{
			c = c * 10;
			c = info[j] - '0' + c;
		}
		r.num = c;//считали номер стилажа
		item.push_back(r);//3втолкнули в вектор
	}
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
		cout << "В коллеккции есть " << k << " книги " << iyear << " года"<< endl; // есть такой год выводим год и кол-ао книг
}