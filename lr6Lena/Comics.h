#ifndef Comics_H
#define Comics_H

#include "IItem.h"

class Comics : public IItem {
public:
	Comics(const std::string& ititle, double iprice, const std::string& year);
	virtual ~Comics();

	// Реализация интерфейса печатного издания
	std::string GetTitle() const { return title; }

	// Реализация интерфейса печатного издания
	double GetPrice() const { return price; }

	// Получить год и3дания комикса. 
	// Добавленный метод, специфический для комикса
	std::string GetYear() const { return year; }

private:
	std::string title;
	double price;
	std::string year;;
};

#endif // !Comics_H

//добавили один класс 
//печатного издания 
//у нас комикс

