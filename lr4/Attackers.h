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

	friend void writeData(vector<attackers>& q);
	friend void readData(vector<attackers>& q);
	friend istream& operator>> (istream& in, attackers& item);
	friend ostream& operator<< (ostream& out, attackers& item);
	friend void best(vector<attackers> q);

private:
	char name[20];    //���
	int nogs = { 0 }; //����� ����������� ��� ����
	int noa = { 0 };  //����� ��������� ������� �������
	int time = { 0 }; //������������ �������� �����
};


attackers::attackers(const char* iname, int inogs, int inoa, int itime)
{
	strcpy_s(name, iname);
	nogs = inogs;
	noa = inoa;
	time = itime;
}

void writeData(vector<attackers>& q)
{
	ofstream fout;
	fout.open("y.dat", ofstream::app | ofstream::binary);

	for (int i = 0; i < q.size(); i++) {
		fout.write((char*)&q[i], sizeof(attackers));
	}

	fout.close();
}

void readData(vector<attackers>& q)
{
	ifstream fin;
	fin.open("y.dat", ifstream::in | ifstream::binary);
	int i{ 0 };
	attackers temp;

	while (fin.read((char*)&temp, sizeof(attackers))) {
		q.push_back(temp);
		i++;
	}

	fin.close();
}


istream& operator>>(istream& in, attackers& item)
{
	cout << "Fulfil the information:" << endl;
	cout << "Name: ";
	in >> item.name;
	cout << "����� ����������� ��� ����: ";
	in >> item.nogs;
	cout << "����� ��������� ������� �������: ";
	in >> item.noa;
	cout << "3����������� �������� �����: ";
	in >> item.time;
	return in;
}

ostream& operator<<(ostream& out, attackers& item)
{
	out << endl << "Information about '" << item.name << "': " << endl;
	out << " ����� ����������� ��� ����: " << item.nogs << endl;
	out << " ����� ��������� ������� �������: " << item.noa << endl;
	out << " 3����������� �������� �����: " << item.time << endl;
	return out;
}


void best(vector<attackers> q)
{
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