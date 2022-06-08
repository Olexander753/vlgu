#include "Library.h"
#include "PublicLibraryStrategy.h"
#include "UniversityLibraryStrategy.h"
#include "PurchaseCheapStrategy.h"
#include "PurchaseExpensiveStrategy.h"
#include "PurchaseNameStrategy.h"
#include "Student.h"
#include "Lecturer.h"
#include "Programmer.h"
#include "ItemFactory.h"
#include <windows.h>
#include "LibraryItem.h"
#include <iostream>
#include "Book.h"
#include "Journal.h"
#include "Comics.h"

//
// Показать состояние библиотеки и книг в ней
//
void Show(Library& lib);

int main(int argc, char* argv[]) {
	setlocale(LC_ALL, "rus");
	//
	// Библиотеки с различными стратегиями
	//
	Library vlsuLibrary(
		std::string("Библиотека ВлГУ"),
		new PurchaseNameStrategy("Комикс Капитан америка "), //добавить конкретную стратегию закупки печатных изданий;
		new UniversityLibraryStrategy(50));
	Library regionLibrary(
		std::string("Областная библиотека"),
		new PurchaseExpensiveStrategy(4),
		new PublicLibraryStrategy(65));

	//
	// Читатели разлчиных категорий
	//
	Student st1(std::string("Петров"), 1);
	Student st2(std::string("Иванов"), 4);
	Student st3(std::string("Сидоров"), 5);

	Lecturer lec1(std::string("Кутузов"), std::string("доцент"));
	Lecturer lec2(std::string("Суворов"), std::string("профессор"));

	Programmer pr1(std::string("Леонтьев"), 5);//со3дали программистa
	Programmer pr2(std::string("Максимов"), 2);//со3дали программистa

	//
	// Регистрируем читателей в библиотеках. Некоторые из читателей -
	// в нескольких библиотеках
	//
	vlsuLibrary.AddReader(&st1);
	vlsuLibrary.AddReader(&st2);
	regionLibrary.AddReader(&st3);

	vlsuLibrary.AddReader(&lec1);
	vlsuLibrary.AddReader(&lec2);
	regionLibrary.AddReader(&lec1);
	regionLibrary.AddReader(&lec2);

	vlsuLibrary.AddReader(&pr1);//добавили программистa в библиотеку
	vlsuLibrary.AddReader(&pr2);//добавили программистa в библиотеку


	//
	// Генерировать несколько печатных изданий и "продать" их библиотекам
	//
	for (int i = 0; i < 10; i++) {
		IItem* item;

		// В половине случаев (i - четное) будем создавать журналы,
		// в половине - книги
		if (i % 2 == 0) {
			// Создать экземпляр журнала
			item = ItemFactory::Instance().CreateJournal();
		}
		else if (i % 3 == 0) {
			// Создать экземпляр книги
			item = ItemFactory::Instance().CreateBook();
		}
		// добавили для нового печатного и3дания комиксы
		else {
			// Создать экземпляр комикса
			item = ItemFactory::Instance().CreateComics();
		}

		//
		// Библиотеки поочередно пытаются закупить печатное издание
		//
		bool isSold = false;

		if (!isSold) {
			isSold = vlsuLibrary.PurchaseItem(item);
		}
		if (!isSold) {
			isSold = regionLibrary.PurchaseItem(item);
		}


		//
		// Если экземпляр не куплен, надо его уничтожить, чтобы не было
		// мусора (в динамической памяти, а не в прямом смысле)
		//
		if (!isSold) {
			delete item;
		}

	}

	//
	// Моделируем выдачу печатных изданий читателям
	//
	vlsuLibrary.LetLibItemOut(vlsuLibrary.GetLibItems()[0], &st1);
	vlsuLibrary.LetLibItemOut(vlsuLibrary.GetLibItems()[0], &pr1);//добавили для программиста
	regionLibrary.LetLibItemOut(regionLibrary.GetLibItems()[0], &st3);

	vlsuLibrary.LetLibItemOut(vlsuLibrary.GetLibItems()[0], &lec1);
	regionLibrary.LetLibItemOut(regionLibrary.GetLibItems()[1], &lec1);
	regionLibrary.LetLibItemOut(regionLibrary.GetLibItems()[2], &pr2);//добавили для программиста

	//
	// Показать состояние библиотек и книг
	//

	Show(vlsuLibrary);
	Show(regionLibrary);

	return 0;
}


void Show(Library& lib) {
	//
	// Сведения о библиотеке
	//
	std::cout << "\n" << "Название библиотеки: " << lib.GetName() << std::endl;

	//
	// Сведения о всех читателях библиотеки
	//
	std::cout << "\n" << "Читатели:" << std::endl;
	std::vector<Reader*> readers = lib.GetReaders();
	for (int iReader = 0; iReader < readers.size(); iReader++) {
		std::cout << iReader << ") " << readers[iReader]->GetName() << std::endl;
	}


	//
	// Сведения о книгах
	//
	std::cout << "\n" << "Экземпляры:" << std::endl;
	std::vector<LibraryItem*> items = lib.GetLibItems();
	for (int i = 0; i < items.size(); i++) {
		std::cout << i + 1 << ") " << items[i]->GetTitle();

		// Вывести информацию, специфическую для конкретного типа издания
		Book* book = dynamic_cast<Book*>(items[i]->GetItem());
		Journal* journal = dynamic_cast<Journal*>(items[i]->GetItem());
		Comics* geo_map = dynamic_cast<Comics*>(items[i]->GetItem());

		if (book != NULL) {
			std::cout << " автор " << book->GetAuthor();
		}
		else {
			if (journal != NULL) {
				std::cout << " номер " << journal->GetVolume();
			}
			if (geo_map != NULL) {
				std::cout << " год " << geo_map->GetYear();
			}
		}

		if (items[i]->GetReader() != NULL) {
			std::cout << " на руках: "
				<< items[i]->GetReader()->GetName()
				<< " на " << items[i]->GetHoldPeriod() << " дней" << std::endl;
		}
		else {
			std::cout << " на полке" << std::endl;
		}

		std::cout
			<< "Инв.№ " << items[i]->GetInventoryNumber()
			<< " Стоимость " << items[i]->GetPrice() << std::endl;

	}
}
