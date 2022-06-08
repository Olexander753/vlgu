#ifndef JOURNAL_H
#define JOURNAL_H

#include "IItem.h"
#include <string>

class Journal : public IItem {
public:
	Journal(const std::string& title, double price, const std::string& volume);
	virtual ~Journal();

	// ���������� ���������� ��������� �������
	std::string GetTitle() const { return _title; }

	// ���������� ���������� ��������� �������
	double GetPrice() const { return _price; }

	// ������� �������� ���� (������) �������. 
	// ����������� �����, ������������� ��� �������
	std::string GetVolume() const { return _volume; }

private:
	std::string _title;
	double _price;
	std::string _volume;

};


#endif // !JOURNAL_H
