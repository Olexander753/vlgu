#ifndef GEO_MAP_H
#define GEO_MAP_H

#include "IItem.h"

class Geo_map : public IItem {
public:
	Geo_map(const std::string& ititle, double iprice, const std::string& year);
	virtual ~Geo_map();

	// ���������� ���������� ��������� �������
	std::string GetTitle() const { return title; }

	// ���������� ���������� ��������� �������
	double GetPrice() const { return price; }

	// �������� ����� ������ ������. 
	// ����������� �����, ������������� ��� �������������� �����
	std::string GetYear() const { return year; }

private:
	std::string title;
	double price;
	std::string year;;
};

#endif // !GEO_MAP_H

