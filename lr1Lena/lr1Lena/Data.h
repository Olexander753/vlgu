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
		day = new int[size];            //�����
		month = new int[size];          //�����
		year = new int[size];           //���
		day_of_week = new string[size]; //���� ������
	}
	Data(int iday, int imonth, int iyear, string iday_of_week)
	{
		size = 2;
		month = new int[size];
		//�������� �� ������������ ������
		if (imonth < 1 || imonth > 12) 
			throw("�������� ����� ");
		else
			month[0] = imonth;

		day = new int[size];
		//�������� �� ������������ ����� � 3���������� �� ������ � ����
		if (imonth == 1 || imonth == 3 || imonth == 5 || imonth == 7 || imonth == 8 || imonth == 10 || imonth == 12) 
		{
			if (iday < 1 || iday > 31)
				throw("�������� �����");
			else
				day[0] = iday;
		}

		if (imonth == 4 || imonth == 6 || imonth == 9 || imonth == 11)
		{
			if (iday < 1 || iday > 30)
				throw("�������� �����");
			else
				day[0] = iday;
		}

		if (iyear % 4 == 0)
		{
			if(imonth == 2)
				if (iday < 1 || iday > 29)
					throw("�������� �����");
				else
					day[0] = iday;
		}
		else
		{
			if (imonth == 2)
				if (iday < 1 || iday > 28)
					throw("�������� �����");
				else
					day[0] = iday;
		}
		//�������� �� ������������ ����
		year = new int[size];
		if (iyear < 0)
			throw("�������� ���");
		else
			year[0] = iyear;
		//�������� �� ������������ ��� ������
		day_of_week = new string[size];
		if (iday_of_week == "�����������" || iday_of_week == "�������" || iday_of_week == "�����" || iday_of_week == "�������" || iday_of_week == "�������" || iday_of_week == "�������" || iday_of_week == "�����������")
			day_of_week[0] = iday_of_week;
		else
			throw("�������� ���� ������ ");
	}

	~Data() = default;

	//��3������ ���� ������
	string week()
	{
		if (size != 0)
			return day_of_week[0];
		else
			throw("�������� � ������� �������");
	}
};

