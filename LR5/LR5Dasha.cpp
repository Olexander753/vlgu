#include <iostream>
#include "Baze.h"

int main()
{
	setlocale(LC_ALL, "RUS");
	Baze b;

	Description* des1 = new Structure("Сахар, мука, Е321, Е434, соль");
	Description* des2 = new Date_of_manufacture("Годен до 11.11.21");

	Tovar a("Хлеб", 12, 6, 20);
	Tovar x("Лаваш", 16, 2, 40);
	a.addNewDescription(des1);
	a.addNewDescription(des2);

	Postavchik e("Игорь", 22, "12.11.12", 12);
	Postavchik r("Валера", 23, "23.10.12", 70);

	b.addTovar(a);
	b.addTovar(x);
	b.addPostavchik(e);
	b.addPostavchik(r);

	b.outTovar();
	b.outPostavchik();

}