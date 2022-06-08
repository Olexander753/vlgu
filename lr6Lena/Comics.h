#ifndef Comics_H
#define Comics_H

#include "IItem.h"

class Comics : public IItem {
public:
	Comics(const std::string& ititle, double iprice, const std::string& year);
	virtual ~Comics();

	// ���������� ���������� ��������� �������
	std::string GetTitle() const { return title; }

	// ���������� ���������� ��������� �������
	double GetPrice() const { return price; }

	// �������� ��� �3����� �������. 
	// ����������� �����, ������������� ��� �������
	std::string GetYear() const { return year; }

private:
	std::string title;
	double price;
	std::string year;;
};

#endif // !Comics_H

//�������� ���� ����� 
//��������� ������� 
//� ��� ������

