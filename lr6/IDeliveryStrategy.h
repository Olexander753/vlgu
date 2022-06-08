#ifndef IDELIVERYSTRATEGY_H
#define IDELIVERYSTRATEGY_H

#include "Reader.h"

//
// ��������� ��������� ����������� ������� �������� ������
//
class IDeliveryStrategy {
public:

	// ��������� ������ (� ����) �������� ������ ��� ��������� ��������
	virtual int HoldPeriod(const Reader& reader) const = 0;

};


#endif // !IDELIVERYSTRATEGY_H
