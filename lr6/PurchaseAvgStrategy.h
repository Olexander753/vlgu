#ifndef PURCHASEAVERAGESTRATEGY_H
#define PURCHASEAVERAGESTRATEGY_H

#include "IPurchaseStrategy.h"

class PurchaseAvgStrategy : public IPurchaseStrategy {
public:
	bool IsAcceptable(const IItem& item);
	PurchaseAvgStrategy(int sPrice, int iPrice);
	virtual ~PurchaseAvgStrategy();

private:
	double aPrice;
	double bPrice;
};


PurchaseAvgStrategy::PurchaseAvgStrategy(int isPrice, int iPrice) : aPrice(isPrice), bPrice(iPrice) {}

PurchaseAvgStrategy::~PurchaseAvgStrategy() {}

bool PurchaseAvgStrategy::IsAcceptable(const IItem& item) {
	bool result = true;

	if (aPrice > item.GetPrice())
	{
		result = false;
	}
	if (bPrice < item.GetPrice())
	{
		result = false;
	}
	return result;
}
#endif // !PURCHASEAVERAGESTRATEGY_H
