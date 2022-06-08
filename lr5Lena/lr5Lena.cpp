#include <iostream>
#include "Organization.h"
int main()
{
	setlocale(LC_ALL, "RUS");

	Organization a;

	Worker* w1 = new Engineer("Василий", "Владимир проспект Ленина 3", "89991112233", 10543.14, "11.12.21"); //со3даём сотрудников 
	Worker* w2 = new Engineer("Егро", "Владимир проспект Ленина 8", "89992223344", 17856.78, "01.06.22");
	Worker* w3 = new Programmer("Кирилл", "Владимир проспект Ленина 22", "89993334455", 25324.53, "21.05.22");
	Worker* w4 = new Programmer("Сергей", "Владимир проспект Ленина 56", "89994445566", 21698.31, "25.09.21");
	
	Contract* c1 = new Rent("ФУ123ТН", "Ситилинк", "12.03.21", 50000); //со3даём договоры
	Contract* c2 = new Leasing("НГ672ОС", "DNS", "01.01.21", 100000);

	c1->addWorker(w1); //3аталкиваем сотрудников в контракты
	c1->addWorker(w3);
	c2->addWorker(w2);
	c2->addWorker(w4);

	a.addContract(c1); //3аталкиваем в органи3ацию контракты
	a.addContract(c2);

	a.getContracts(); //выводим контракты
}