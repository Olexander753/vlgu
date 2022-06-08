#ifndef PURCHASEEXPENSIVESTRATEGY_H
#define PURCHASEEXPENSIVESTRATEGY_H

#include "IPurchaseStrategy.h"
//
// ���������� ��������� ������� ��������� �������: ��������, ����
// ��������� ����� �� ���� ��������.
//
class PurchaseExpensiveStrategy : public IPurchaseStrategy {

public:
	bool IsAcceptable(const IItem& item);
	PurchaseExpensiveStrategy(int minPrice);
	virtual ~PurchaseExpensiveStrategy();


private:
	double _minPrice;
};

PurchaseExpensiveStrategy::PurchaseExpensiveStrategy(int minPrice) : _minPrice(minPrice) {}

PurchaseExpensiveStrategy::~PurchaseExpensiveStrategy() {}

bool PurchaseExpensiveStrategy::IsAcceptable(const IItem& item) {
	bool result = true;
	if (item.GetPrice() < _minPrice) {
		result = false;
	}
	return result;
}


#endif // !PURCHASEEXPENSIVESTRATEGY_h
