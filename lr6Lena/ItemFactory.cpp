//#define _CRT_SECURE_NO_WARNINGS
#include "ItemFactory.h"

//////////////////////////////////////////////////////////////////////
// Construction/Destruction
//////////////////////////////////////////////////////////////////////

// Инициализация статического поля класса,
// для него будет вызыван конструктор без параметров
ItemFactory ItemFactory::s_instance;

ItemFactory::ItemFactory() : _counter(0) {}

ItemFactory::~ItemFactory() {}

ItemFactory& ItemFactory::Instance() {
	return s_instance;
}

Book* ItemFactory::CreateBook() {
	_counter++;

	// Преобразование числа в строку
	char buffer[10];
	_itoa_s(_counter, buffer, 10);

	const std::string title = std::string("Краткое руководство по С++. Том ") + std::string(buffer);
	const double price = _counter;
	std::string author = std::string("Страуструп Б.");

	return new Book(title, price, author);
}

Journal* ItemFactory::CreateJournal() {
	_counter++;

	// Преобразование числа в строку
	char buffer[5];
	_itoa_s(_counter, buffer, 5);

	std::string title = std::string("Мурзилка");
	double price = _counter;
	std::string volume = std::string(buffer);

	return new Journal(title, price, volume);

}

//метод котрый мы добавили 
//новый метод для нового печатного и3дания комиксы
Comics* ItemFactory::CreateComics() { 
	_counter++;

	// Преобразование числа в строку
	char buffer[10];
	_itoa_s(_counter, buffer, 10);

	const std::string title = std::string("Комикс Капитан америка ");
	const double price = _counter;
	std::string year = std::string(" 1965");

	return new Comics(title, price, year);
}

//изменили алгоритм создания печатных изданий в фабрике печатных изданий 
//с учетом нового класса печатного издания.
