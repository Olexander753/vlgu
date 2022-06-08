#include "Train.h"

Train::Train(int Tnumbertrain, const char* Tstation, int Th, int Tm, int Ttimeinroud, int Ttikkets)
{
	numbertrain = Tnumbertrain;
	strcpy_s(station, Tstation);
	h = Th;
	m = Tm;
	timeinroud = Ttimeinroud;
	tikkets = Ttikkets;
}

istream& operator>>(istream& in, Train& item)
{
	cout << "���������� � �������:" << endl;
	cout << "����� ������: ";
	in >> item.numbertrain;
	cout << "������� ��3�������: ";
	in >> item.station;
	cout << "����� ����������� ";
	in >> item.h;
	cout << ":";
	in >> item.m;
	cout << "����� � ����: ";
	in >> item.timeinroud;
	cout << "���������� �������: ";
	in >> item.tikkets;
	return in;
}

ostream& operator<<(ostream& out, Train& item)
{
	out << endl << "���������� � ������ '" << item.numbertrain << "': " << endl;
	out << " ������� ��3�������: " << item.station << endl;
	out << " ����� �����������: " << item.h << ":" << item.m << endl;
	out << " ����� � ����: " << item.timeinroud << endl;
	out << " ���������� �������: " << item.tikkets << endl;
	return out;
}

void writeData(const char* path, vector<Train>& q) {
	ofstream fout;
	fout.open(path, ofstream::app | ofstream::binary);

	for (int i = 0; i < q.size(); i++) {
		fout.write((char*)&q[i], sizeof(Train));
	}

	fout.close();
}

void readData(const char* path, vector<Train>& q) {
	ifstream fin;
	fin.open(path, ifstream::in | ifstream::binary);
	int i{ 0 };
	Train temp;

	while (fin.read((char*)&temp, sizeof(Train))) {
		q.push_back(temp);
		i++;
	}

	fin.close();
}



void timetoroud(vector<Train> t, const char* city, int ah, int am, int bh, int bm)
{
	cout << "� ���������� � " << ah << ":" << am << " �� " << bh << ":" << bm << " �� ������� " << city << endl;
	int a, b, c;
	int k;
	int w = 0;
	int q = 0;
	char icity[20];
	a = ah * 60 + am;
	b = bh * 60 + bm;
	for (int i = 0; i < t.size(); i++)
	{
		strcpy_s(icity, city);
		int j = 0;
		while (t[i].station[j] != '\0')
		{
			k = 0;
			if (t[i].station[j] == icity[j])
			{
				k = 1;
			}
			j++;
		}
		if (k == 1)
		{
			q++;
			c = t[i].h * 60 + t[i].m;
			if (c > a)
			{
				if (c < b)
				{
					cout << "����������� ����� � ������� " << t[i].numbertrain << " � " << t[i].h << ":" << t[i].m << endl;
					w++;
				}
			}
		}
	}
	if (q == 0)
	{
		throw ("������� � ����������� � ������ ����� ��� ");
	}
	if (w == 0)
	{
		throw ("������� � ����������� � ������ ��������� ��� ");
	}
}

void havetikkets(vector<Train> t, int inumbertrain)
{
	int k = 0;
	for (int i = 0; i < t.size(); i++)
	{
		if (t[i].numbertrain == inumbertrain)
		{
			cout << "�� ����� � ������� " << t[i].numbertrain << " � ������ ���� " << t[i].tikkets << " �������" << endl;
			if (t[i].tikkets == 0)
			{
				throw ("������� �� ������ ����� ��� ");
			}
			k++;
		}
	}
	if (k == 0)
	{
		throw ("������ ������ ��� ");
	}
}