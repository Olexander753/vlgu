#include <iostream> 
#include <vector> 
#include <fstream>

using namespace std;

class attackers 
{
public:
	attackers() = default;
	attackers(const char* iname, int inogs, int inoa, int itime); 
	~attackers() = default; 

	friend void writeData(vector<attackers> q); 
	friend void readData(vector<attackers>& q);
	friend istream& operator>> (istream& in, attackers& item); 
	friend ostream& operator<< (ostream& out, attackers& item); 
	friend void best(vector<attackers> q);

private: 
	char name[20];    //Имя
	int nogs = { 0 }; //Число заброшенных ими шайб
	int noa = { 0 };  //число сделанных голевых передач
	int time = { 0 }; //заработанное штрафное время
};


attackers::attackers(const char* iname, int inogs, int inoa, int itime)
{
	strcpy_s(name, iname);
	nogs = inogs;
	noa = inoa;
	time = itime;
}

void writeData(vector<attackers> q)
{
	ofstream out("x.txt");
	for (int i = 0; i < q.size(); i++)
	{
		out << q[i].name << " " << q[i].nogs << " " << q[i].noa << " " << q[i].time << " " << endl;
	}
	out.close();
}

void readData(vector<attackers>& q)
{ 
	ifstream in("y.txt", ios::in); 
	if (!in)
	{
		throw("Error in file ");
	} 
	while (!in.eof())
	{
		char sym;
		char word1[20];
		char word2[20];
		char word3[20];
		char word4[20];
		attackers x;
		int i = 0;
		in.get(sym);
		while (sym != '0' && sym != '1' && sym != '2' && sym != '3' && sym != '4' && sym != '5' && sym != '6' && sym != '7' && sym != '8' && sym != '9' && sym != ' ' && sym != '\n')
		{
			word1[i] = sym;
			i++;
			in.get(sym);
		}
		for (int g = i; g < 20; g++)
		{
			word1[g] = { '\0' };
		}
		strcpy_s(x.name, word1);
		if (sym == ' ')
		{
			int k = 0;
			in.get(sym);
			while (sym == '0' || sym == '1' || sym == '2' || sym == '3' || sym == '4' || sym == '5' || sym == '6' || sym == '7' || sym == '8' || sym == '9' || sym != ' ')
			{
				word2[k] = sym;
				k++;
				in.get(sym);
			}
			int j = 0;
			int z = 0;
			while (word2[j] == '0' || word2[j] == '1' || word2[j] == '2' || word2[j] == '3' || word2[j] == '4' || word2[j] == '5' || word2[j] == '6' || word2[j] == '7' || word2[j] == '8' || word2[j] == '9')
			{
				z = z * 10;
				z = (word2[j] - '0') + z ;
				j++;
			}
			x.nogs = z;
		}
		if (sym == ' ')
		{
			int k = 0;
			in.get(sym);
			while (sym == '0' || sym == '1' || sym == '2' || sym == '3' || sym == '4' || sym == '5' || sym == '6' || sym == '7' || sym == '8' || sym == '9' || sym != ' ')
			{
				word3[k] = sym;
				k++;
				in.get(sym);
			}
			int j = 0;
			int z = 0;
			while (word3[j] == '0' || word3[j] == '1' || word3[j] == '2' || word3[j] == '3' || word3[j] == '4' || word3[j] == '5' || word3[j] == '6' || word3[j] == '7' || word3[j] == '8' || word3[j] == '9')
			{
				z = z * 10;
				z = (word3[j] - '0') + z;
				j++;
			}
			x.noa = z;
		}
		if (sym == ' ')
		{
			int k = 0;
			in.get(sym);
			while (sym == '0' || sym == '1' || sym == '2' || sym == '3' || sym == '4' || sym == '5' || sym == '6' || sym == '7' || sym == '8' || sym == '9' || sym != ' ' && sym != '\n')
			{
				if (in.eof())
					break;
				word4[k] = sym;
				k++;
				in.get(sym);
			}
			int j = 0;
			int z = 0;
			while (word4[j] == '0' || word4[j] == '1' || word4[j] == '2' || word4[j] == '3' || word4[j] == '4' || word4[j] == '5' || word4[j] == '6' || word4[j] == '7' || word4[j] == '8' || word4[j] == '9')
			{
				z = z * 10;
				z = (word4[j] - '0') + z;
				j++;
			}
			x.time = z;
		}
		q.push_back(x);
	}
}


istream& operator>>(istream& in, attackers& item)
{
	cout << "Fulfil the information:" << endl;
	cout << "Name: ";
	in >> item.name;
	cout << "Число заброшенных ими шайб: ";
	in >> item.nogs;
	cout << "Число сделанных голевых передач: ";
	in >> item.noa;
	cout << "3аработанное штрафное время: ";
	in >> item.time;
	return in;
}

ostream& operator<<(ostream& out, attackers& item)
{ 
	out << endl << "Information about '" << item.name << "': " << endl; 
	out << " Число заброшенных ими шайб: " << item.nogs << endl; 
	out << " Число сделанных голевых передач: " << item.noa << endl; 
	out << " 3аработанное штрафное время: " << item.time << endl;
	return out; 
}


void best(vector<attackers> q)
{ 
	if (q.size() == 0)
	{
		throw ("Пустой список игроков ");
	}
	for (int i = 0; i < q.size() - 1; i++)
	{
		for (int j = 0; j < q.size() - i - 1; j++)
		{
			if (q[j].noa + q[j].nogs < q[j + 1].noa + q[j + 1].nogs)
			{
				attackers arr = q[j];
				q[j] = q[j + 1];
				q[j + 1] = arr;
			}
		}
	}

	for (int i = 0; i < 4; i++)
	{
		cout << q[i] << endl;
	}
}