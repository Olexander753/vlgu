#include <iostream>
#include "Faile.h"
#include "Attackers.h"


int main()
{
	setlocale(LC_ALL, "RUS");
	try 
	{
		Faile x("input.txt");

		attackers a("a",  33, 7, 1); 
		attackers b("b",  12, 4, 5);
		attackers c("c",  1, 17, 7);
		attackers d("d",  22, 14, 11);
		attackers e("e",  45, 9, 17);
		attackers f("f",  7, 10, 16);
		vector<attackers> q;
		q.push_back(a); 
		q.push_back(b); 
		q.push_back(c); 
		q.push_back(d); 
		q.push_back(e); 
		q.push_back(f); 

		readData(q);

		writeData(q);
		best(q);

	}
	catch (const char* error)
	{
		cout << error << endl;
	}
}