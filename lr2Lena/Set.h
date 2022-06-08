#pragma once
#include <iostream>

using namespace std;

template <class T>
class Set
{
	T* set;
	int size{ 0 };
	int max{ 2 };

public:
	Set();
	~Set();
	void print();
	void input(T item); //���������� �������� � ���������
	void operator+(T item); //���������� �������� � ���������
	void operator*(Set &item); //����������
	int power() { return size; }; //��������
};


template <class T> Set<T>::Set()
{
	size = 0;
	set = new T[size];
}

template <class T> Set<T>::~Set()
{
	delete[] set;
	set = NULL;
}

template <class T> void Set<T>::print()
{
	if (size == 0)
		throw("��������� � ������� ���������");
	for (int i = 0; i < size; i++)
	{
		cout << set[i] << endl;
	}
}

template <class T> void Set<T>::input(T item)
{
	if (size == max)
	{
		throw ("������������ ");
	}
	else
	{
		auto* new_set = new T[size + 1];
		for (int i = 0; i < size; i++)
		{
			new_set[i] = this->set[i];
		}
		new_set[size] = item;
		size++;
		delete[] this->set;
		this->set = new_set;
	}
}

template <class T> void Set<T>::operator+(T item)
{
	this->input(item); //������ ������������ ������� input
}

template <class T> void Set<T>::operator*(Set &item)
{
	if (size == 0)
		throw("��������� � ������� ���������");
	if (item.size == 0)
		throw("��������� � ������� ���������");
	auto set1 = this->set;
	auto set2 = item.set;

	for (int i = 0; i < size; i++)
	{
		for (int j = 0; j < item.size; j++)
		{
			if (set1[i] == set2[j])
				cout << set1[i] << endl;
		}
	}
}