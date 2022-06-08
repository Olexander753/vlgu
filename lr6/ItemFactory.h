#ifndef ITEMFACTORY_H
#define ITEMFACTORY_H

#include "Book.h"
#include "Journal.h"
#include "Vocabulary.h"

class ItemFactory {
public:
	// ��������� ����� ��� �������� ���������� �����.
	// �� ����������� ������� �������� ������.
	Journal* CreateJournal();

	// ��������� ����� ��� �������� ���������� �������.
	// �� ����������� ������� �������� ������.
	Book* CreateBook();

	Vocabulary* CreateGeo_map();

	// ������� ������ �� ��������� "��������", ������� � ���� ��������� �������.
	static ItemFactory& Instance();

	virtual ~ItemFactory();

private:

	// ������������ ��������� "��������" - ����������� ����
	static ItemFactory s_instance;

	// ������� ��������� "���������" - �������� �������.
	// ��� ���� ������� (�� ����������� ����). ��� ������������� ��� ���������
	// ������������� ����������� �������� �������.
	int _counter;

	// �������� ����������� ��� ����, ����� ������� ������ �� ����� ���������
	// ��������� �������. ��� ����������� ������ �������������� "��������".
	ItemFactory();

};



#endif // !ITEMFACTORY_H
