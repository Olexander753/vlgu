#include <iostream>
#include <fstream>
using namespace std;

class Faile
{
	ifstream file;
	char ch;

	char getCursor(char ch);


public:
	explicit Faile(const char* path);
	~Faile() = default;
};

Faile::Faile(const char* path)
{
	file.open(path, ios::in);
	if (!file.is_open())	
		throw ("Error: Can't open file");	

	char ch = -1;

	int a = 0;
	int b = 0;
	if (file.eof())
		throw("Ïףסעמי פאיכ ");
	while (!file.eof())
	{
		while (ch == -1 || ch == ' ' || ch == '\r' || ch == '\n' || ch == '\t')
		{
			file.get(ch);
			if (file.eof()) return;
		}
		if (ch == '{')
			a++;
		if (ch == '}')
			b++;

		file.get(ch);
	}
	if (a == b)
	{
		cout << "Chislo skobok sootv  " << endl;
	}
	else
	{
		cout << "Chislo skobok nesootv" << endl;
	}
	file.close();
}

char Faile::getCursor(char ch) 
{ 
	file.seekg(-1, ios::cur); 
	file.get(ch); 
	return ch;		 	
}		
	