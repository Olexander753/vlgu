#ifndef PURCHASESTATICSTRATEGY_H
#define PURCHASESTATICSTRATEGY_H

#include "IPurchaseStrategy.h"

class PurchaseStaticStrategy : public IPurchaseStrategy {
public:
	bool IsAcceptable(const IItem& item);
	PurchaseStaticStrategy(int sPrice);
	virtual ~PurchaseStaticStrategy();

private:
	double sPrice;
};


PurchaseStaticStrategy::PurchaseStaticStrategy(int isPrice) : sPrice(isPrice) {}

PurchaseStaticStrategy::~PurchaseStaticStrategy() {}

bool PurchaseStaticStrategy::IsAcceptable(const IItem& item) {
	bool result = true;

	if (sPrice != item.GetPrice()) {
		result = false;
	}

	return result;
}
#endif // !PURCHASESTATICSTRATEGY_H
