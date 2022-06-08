#include "f.h"

f::f(const char* path)
{
	ifstream in(path, ios::in);
	if (!in.is_open())
		throw ("Error: Can't open file");


	ch = -1;
	int a = 0;
	int b = 0;
	int c = 0;
	int d = 0;
	int e = 0;
	int f = 0;

	while (!in.eof())
	{
		while (ch == -1 || ch == ' ' || ch == '\r' || ch == '\n' || ch == '\t')
		{
			in.get(ch);
			if (in.eof()) return;
		}
		if (ch == 'a')
			a++;
		if (ch == 'b')
			b++;
		if (ch == 'c')
			c++;
		if (ch == 'd')
			d++;
		if (ch == 'e')
			e++;
		if (ch == 'f')
			f++;

		in.get(ch);
	}
	cout << "a: " << a << endl << "b: " << b << endl << "c: " << c << endl
		 << "d: " << d << endl << "e: " << e << endl << "f: " << f << endl;
	in.close();

	ofstream out("g.txt", ios::out);
	if (out.is_open())
	{
		out << "Буква 'a' входит в файл " << a << " раз" << endl;
		out << "Буква 'b' входит в файл " << b << " раз" << endl;
		out << "Буква 'c' входит в файл " << c << " раз" << endl;
		out << "Буква 'd' входит в файл " << d << " раз" << endl;
		out << "Буква 'e' входит в файл " << e << " раз" << endl;
		out << "Буква 'f' входит в файл " << f << " раз" << endl << endl;

		out << "a: " << a << "  //Количество вхождений в файл буквы 'а'" << endl 
			<< "b: " << b << "  //Количество вхождений в файл буквы 'b'" << endl
			<< "c: " << c << "  //Количество вхождений в файл буквы 'c'" << endl
			<< "d: " << d << "  //Количество вхождений в файл буквы 'd'" << endl
			<< "e: " << e << "  //Количество вхождений в файл буквы 'e'" << endl
			<< "f: " << f << "  //Количество вхождений в файл буквы 'f'" << endl;

	}
	else
	{
		throw ("Error: Can't open file");
	}
	out.close();
}

f::~f() = default;
