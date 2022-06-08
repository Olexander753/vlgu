#ifndef BOOK_H
#define BOOK_H

#include "IItem.h"

class Book : public IItem {
public:
	Book(const std::string& title, double price, const std::string& author);
	virtual ~Book();

	// ���������� ���������� ��������� �������
	std::string GetTitle() const { return _title; }

	// ���������� ���������� ��������� �������
	double GetPrice() const { return _price; }

	// ����������� �����, ������������� ��� �����
	std::string GetAuthor() const { return _author; }

private:
	std::string _title;
	double _price;
	std::string _author;

};


#endif // !BOOK_H

