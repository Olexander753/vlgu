#include <iostream>
#include "f.h"
#include "Train.h"

int main()
{
	try
	{
		setlocale(LC_ALL, "RUS");


		f v("test.txt");
		Train a(33, "x", 7, 1, 60, 5);
		Train b(34, "qw34e", 8, 12, 40, 8);
		Train c(35, "qwdase", 9, 8, 60, 9);
		Train d(36, "x", 11, 1, 65, 1);
		Train e(37, "x", 15, 3, 64, 7);
		vector<Train> t;
		t.push_back(a);
		t.push_back(b);
		t.push_back(c);
		t.push_back(d);
		t.push_back(e);

		read(t);
		write(t);

		timetoroud(t, "x", 7, 0, 11, 33);

		havetikkets(t, 31);
	}
	catch (const char* error)
	{
		cout << error << endl;
		exit(-231);
	}
}
