#ifndef LIBRARY_H
#define LIBRARY_H

#include "IPurchaseStrategy.h"
#include "IDeliveryStrategy.h"
#include "IItem.h"
#include "LibraryItem.h"
#include <vector>
#include <algorithm>

class Library {
public:
	std::vector<LibraryItem*> GetLibItems();
	std::vector<Reader*>& GetReaders();

	// ��� �������� ���������� ������ ���������� ���� �������
	// ��������� ������������ �������� ������� � ���������� 
	// ������� �������� �������� �������� ����������.
	Library(
		const std::string& name,
		IPurchaseStrategy* purchaseStrategy,
		IDeliveryStrategy* deliveryStrategy);

	// ��� ����������� �������, ���� ���������� � ������� 
	// ���������, � ������� ��������
	virtual ~Library();

	// �������� ����������
	std::string GetName() { return _name; }

	// ���������� ���������� �������� �������.
	// ���� ��� �����������, �� ������������ true,
	// � ��������� ������ - false
	bool PurchaseItem(IItem* item);

	// ���������������� ��������
	void AddReader(Reader* reader);

	// ������ ����� ��������
	void LetLibItemOut(LibraryItem* item, Reader* reader);

	// ������� ����� � ����������
	void PutLibItemBack(LibraryItem* libItem);

private:

	std::string _name;
	// ���������
	IPurchaseStrategy* _purchaseStrategy;
	IDeliveryStrategy* _deliveryStrategy;

	// ��������� ����������� ����������� �����
	int _lastInventoryNumber;

	// ��� ������ ��������
	std::vector<LibraryItem*> _libItems;

	// ��� ��������
	std::vector<Reader*> _readers;
};


#endif // !LIBRARY_H
