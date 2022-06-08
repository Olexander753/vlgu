#include <iostream>
#include "f.h"
#include "Reader.h"

int main()
{
	setlocale(LC_ALL, "RUS");
	try
	{
		//первое 3адание
		f v("f.txt");

		//второе
		Reader a(1, "q", "xxx", 2005, 4);//со3даём книги
		Reader b(2, "w", "ttt", 2007, 5);
		Reader c(3, "r", "yyy", 2005, 1);
		Reader d(4, "q", "zzz", 2006, 8);

		vector<Reader> r;
		r.push_back(a);//толкаем в вектор
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
