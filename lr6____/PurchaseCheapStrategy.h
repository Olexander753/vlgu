#ifndef PURCHASECHEAPSTRATEGY_H
#define PURCHASECHEAPSTRATEGY_H

#include "IPurchaseStrategy.h"

class PurchaseCheapStrategy : public IPurchaseStrategy {
public:

	// ���������� ������������ ������ �� ������������� ����������.
	// ��������� �������� ��������� ������� �� ���������� ����
	bool IsAcceptable(const IItem& item);

	PurchaseCheapStrategy(double maxPrice);
	virtual ~PurchaseCheapStrategy();

private:
	double _maxPrice;
};

PurchaseCheapStrategy::PurchaseCheapStrategy(double maxPrice) : _maxPrice(maxPrice) {}

PurchaseCheapStrategy::~PurchaseCheapStrategy() {}

bool PurchaseCheapStrategy::IsAcceptable(const IItem& item) {
	bool result = true;

	// ���� ���� ����� �������� ������������,
	// �� ������� �� ���������
	if (item.GetPrice() > _maxPrice) {
		result = false;
	}
	return result;
}
#endif // !PURCHASECHEAPSTRATEGY_H




