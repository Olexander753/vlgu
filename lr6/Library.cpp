#include "Library.h"

//////////////////////////////////////////////////////////////////////
// Construction/Destruction
//////////////////////////////////////////////////////////////////////

Library::Library(
	const std::string& name, IPurchaseStrategy* purchaseStrategy, IDeliveryStrategy* deliveryStrategy)
	: _name(name), _purchaseStrategy(purchaseStrategy), _deliveryStrategy(deliveryStrategy), _lastInventoryNumber(0)
{}

Library::~Library() {
	if (_purchaseStrategy != NULL) {
		delete _purchaseStrategy;
	}

	if (_deliveryStrategy != NULL) {
		delete _deliveryStrategy;
	}

	for (int i = 0; i < _libItems.size(); i++) {
		delete _libItems[i];
	}
}

bool Library::PurchaseItem(IItem* item) {
	bool result = true;
	// ���������, �������� �� ���������� �������� �������
	// � ������������ � ��������� ������������
	if (_purchaseStrategy->IsAcceptable(*item)) {
		// �������� ������� �������������, ��� ���������� 
		// �������� ��������. ������� ��������� ���������
		// ����������. ����������� ����������� �����
		_lastInventoryNumber++;
		LibraryItem* libItem = new LibraryItem(item, _lastInventoryNumber);

		_libItems.push_back(libItem);
	}
	else {
		// ������ �����������
		result = false;
	}
	return result;
}

void Library::AddReader(Reader* reader) {
	_readers.push_back(reader);
}

void Library::LetLibItemOut(LibraryItem* item, Reader* reader) {
	// �������� ����� ����� ������ ��������, �������������������
	// � ������ ����������
	if (find(_readers.begin(), _readers.end(), reader) != _readers.end()) {
		// ����� ����� ������, ���� ��� �� ���� ����� ������  ��� ���� ���������
		if (item->GetReader() == NULL) {
			// �������� �������� ������� �������� ������ � ������������ � 
			// �� ���������� � ������ �����
			int holdPeriod = _deliveryStrategy->HoldPeriod(*reader);

			item->SetHolderPeriod(holdPeriod);
			item->SetReader(reader);
		}
	}
}

void Library::PutLibItemBack(LibraryItem* libItem) {
	libItem->SetReader(NULL);
}

std::vector<Reader*>& Library::GetReaders() {
	return _readers;
}

std::vector<LibraryItem*> Library::GetLibItems() {
	return _libItems;
}
