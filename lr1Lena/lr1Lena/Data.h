#pragma once
#include <iostream>
#include <string> 

using namespace std;

class Data
{
	int *day, *year, *month;
	string* day_of_week;
	int size;

public:
	Data()
	{
		size = 0;
		day = new int[size];            //число
		month = new int[size];          //месяц
		year = new int[size];           //год
		day_of_week = new string[size]; //день недели
	}
	Data(int iday, int imonth, int iyear, string iday_of_week)
	{
		size = 2;
		month = new int[size];
		//проверка на провильность месяца
		if (imonth < 1 || imonth > 12) 
			throw("Неверный месяц ");
		else
			month[0] = imonth;

		day = new int[size];
		//проверка на провильность числа в 3ависимости от месяца и года
		if (imonth == 1 || imonth == 3 || imonth == 5 || imonth == 7 || imonth == 8 || imonth == 10 || imonth == 12) 
		{
			if (iday < 1 || iday > 31)
				throw("Неверное число");
			else
				day[0] = iday;
		}

		if (imonth == 4 || imonth == 6 || imonth == 9 || imonth == 11)
		{
			if (iday < 1 || iday > 30)
				throw("Неверное число");
			else
				day[0] = iday;
		}

		if (iyear % 4 == 0)
		{
			if(imonth == 2)
				if (iday < 1 || iday > 29)
					throw("Неверное число");
				else
					day[0] = iday;
		}
		else
		{
			if (imonth == 2)
				if (iday < 1 || iday > 28)
					throw("Неверное число");
				else
					day[0] = iday;
		}
		//проверка на провильность года
		year = new int[size];
		if (iyear < 0)
			throw("Неверный год");
		else
			year[0] = iyear;
		//проверка на провильность дня недели
		day_of_week = new string[size];
		if (iday_of_week == "Понедельник" || iday_of_week == "Вторник" || iday_of_week == "Среда" || iday_of_week == "Четверг" || iday_of_week == "Пятница" || iday_of_week == "Суббота" || iday_of_week == "Воскресенье")
			day_of_week[0] = iday_of_week;
		else
			throw("Неверный день недели ");
	}

	~Data() = default;

	//во3ращает день недели
	string week()
	{
		if (size != 0)
			return day_of_week[0];
		else
			throw("Обраение к пустому объекту");
	}
};

