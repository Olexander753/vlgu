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
	cout << "Информация о поездах:" << endl;
	cout << "Номер поезда: ";
	in >> item.numbertrain;
	cout << "Станция на3начения: ";
	in >> item.station;
	cout << "Время отправления ";
	in >> item.h;
	cout << ":";
	in >> item.m;
	cout << "Время в пути: ";
	in >> item.timeinroud;
	cout << "Количество билетов: ";
	in >> item.tikkets;
	return in;
}

ostream& operator<<(ostream& out, Train& item)
{
	out << endl << "Информация о поезде '" << item.numbertrain << "': " << endl;
	out << " Станция на3начения: " << item.station << endl;
	out << " Время отправления: " << item.h << ":" << item.m << endl;
	out << " Время в пути: " << item.timeinroud << endl;
	out << " Количество билетов: " << item.tikkets << endl;
	return out;
}

void write(vector<Train> t)
{
	ofstream out("Train1.txt", ios::out);
	for (int i = 0; i < t.size(); i++)
	{
		out << t[i].numbertrain << " " << t[i].station << " " << t[i].h << " " << t[i].m
			<< " " << t[i].timeinroud << " " << t[i].tikkets << endl;
	}
	out.close();
}

void read(vector<Train>& x)
{
	ifstream in("Train2.txt", ios::in);
	if (!in)
	{
		throw("Ошибка файл не открыт ");
	}
	if (in.eof())
	{
		throw ("Файл пустой ");
	}
	while (!in.eof())
	{
		char sym;
		char info[20];
		int i = 0;
		int c = 0;
		Train t;
		
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
		t.numbertrain = c;

		in.get(sym);
		i = 0;
		while (sym != ' ')
		{
			info[i] = sym;
			i++;
			in.get(sym);
		}
		info[i++] = '\0';
		strcpy_s(t.station, info);

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
		if (c < 24 )
		{
			if (c >= 0)
			{
				t.h = c;
			}
			else
			{
				throw ("Неправильное время ");
			}
		}
		else
		{
			throw ("Неправильное время ");
		}

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
		if (c <= 59)
		{
			if (c >= 0)
			{
				t.m = c;
			}
			else
			{
				throw ("Неправильное время ");
			}
		}
		else
		{
			throw ("Неправильное время ");
		}

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
		t.timeinroud = c;

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
		t.tikkets = c;
		x.push_back(t);
	}
}

void timetoroud(vector<Train> t, const char* city, int ah, int am, int bh, int bm)
{
	cout << "В промежутке с " << ah << ":" << am << " до " << bh << ":" << bm << " до станции " << city << endl;
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
					cout <<"Отправляетс поезд с номером " << t[i].numbertrain <<  " в " <<t[i].h << ":" << t[i].m << endl;
					w++;
				}
			}
		}
	}
	if (q == 0)
	{
		throw ("Поездов с отправление в данный пункт нет ");
	}
	if (w == 0)
	{
		throw ("Поездов с отправление в данном интервале нет ");
	}
}

void havetikkets(vector<Train> t, int inumbertrain)
{
	int k = 0;
	for (int i = 0; i < t.size(); i++)
	{
		if (t[i].numbertrain == inumbertrain)
		{
			if (t[i].tikkets == 0)
			{
				throw ("Билетов на данный поезд нет ");
			}
			cout << "На поезд с номером " << t[i].numbertrain << " в наличе есть " << t[i].tikkets << " билетов" << endl;
			
			k = 1;
		}
	}
	if (k == 0)
	{
		throw ("Такого поезда нет ");
	}
}