#ifndef LIBRARYITEM_H
#define LIBRARYITEM_H

#include "IItem.h"
#include "Reader.h"

//
// ��������� ��� ������� ��������. 
// ��������� ��������� � ��������� ����������� ��� �������������
// ������� ����������: ����������� �����, ������ �� ��������, 
//
class LibraryItem : IItem {
public:
	IItem* GetItem();

	int GetInventoryNumber() const { return _inventoryNumber; }

	int GetHoldPeriod() const { return _holdPeriod; }

	void SetHolderPeriod(int holdPeriod) { _holdPeriod = holdPeriod; }

	// ������ NULL, ���� ����� - � ����������
	Reader* GetReader() { return _reader; }

	// ���������� ��������� ������� ��������. ���� ����� �������, 
	// ������� �������� ��������� � ����������, �� ���� ����������
	// �������� NULL
	void SetReader(Reader* reader) { _reader = reader; }

	// ��� �������� ���������� ��������� �������, ����� �� 
	// ���� ��������� ��� ����������� �����.
	LibraryItem(IItem* item, int inventoryNumber);

	//
	// ��� ����������� ���������� ���� ���������� � "���������" ������
	// ����� �� ����� ��������� "�����" � ������
	//
	virtual ~LibraryItem();

	std::string GetTitle() const { return _item->GetTitle(); }

	double GetPrice() const { return _item->GetPrice(); }

private:
	// ��� ��������� �� "��������� ������"
	IItem* _item;

	//
	// �������������� (������������) ���������� ��������, ������������
	// ������� �������� � ����������
	//

	// ����������� �����
	int _inventoryNumber;

	// ����� �������� ������ ���������
	int _holdPeriod;

	// ����� ������� ������ ��������, ������� ������� ������ � ���������� ������.
	// ���� ����� ��������� � ����������, �� �� ������ ���� NULL
	Reader* _reader;

};

#endif // !LIBRARYITEM_H
