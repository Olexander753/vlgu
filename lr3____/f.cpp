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
		out << "����� 'a' ������ � ���� " << a << " ���" << endl;
		out << "����� 'b' ������ � ���� " << b << " ���" << endl;
		out << "����� 'c' ������ � ���� " << c << " ���" << endl;
		out << "����� 'd' ������ � ���� " << d << " ���" << endl;
		out << "����� 'e' ������ � ���� " << e << " ���" << endl;
		out << "����� 'f' ������ � ���� " << f << " ���" << endl << endl;

		out << "a: " << a << "  //���������� ��������� � ���� ����� '�'" << endl 
			<< "b: " << b << "  //���������� ��������� � ���� ����� 'b'" << endl
			<< "c: " << c << "  //���������� ��������� � ���� ����� 'c'" << endl
			<< "d: " << d << "  //���������� ��������� � ���� ����� 'd'" << endl
			<< "e: " << e << "  //���������� ��������� � ���� ����� 'e'" << endl
			<< "f: " << f << "  //���������� ��������� � ���� ����� 'f'" << endl;

	}
	else
	{
		throw ("Error: Can't open file");
	}
	out.close();
}

f::~f() = default;
