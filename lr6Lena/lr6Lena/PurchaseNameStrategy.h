#ifndef PurchaseNameStrategy_H
#define PurchaseNameStrategy_H

#include "IPurchaseStrategy.h"

class PurchaseNameStrategy : public IPurchaseStrategy {
public:
	bool IsAcceptable(const IItem& item);
	PurchaseNameStrategy(const char* isname);
	virtual ~PurchaseNameStrategy();

private:
	const char* sname;
};


PurchaseNameStrategy::PurchaseNameStrategy(const char* isname) : sname(isname) {}

PurchaseNameStrategy::~PurchaseNameStrategy() {}

bool PurchaseNameStrategy::IsAcceptable(const IItem& item) {
	bool result = true;
	//если на3вание книги совадает с на3ванием пеатного и3ания
	//ука3анным в 3купке то покупаем ето печатное и3дание
	if (sname != item.GetTitle()) { 
		result = false;
	}

	return result;
}
#endif // !PurchaseNameStrategy_H


//разработли конкретную стратегию закупки печатных изданий;