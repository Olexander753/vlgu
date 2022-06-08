#include <iostream>

using namespace std;

template <class Tarr>
class Array
{
	Tarr* arr;
	int size{ 0 };
	int max{ 5 };

public:

	Array();
	~Array();
	void print();
	void input(Tarr value);
	void operator-(Array& arr);
	//void operator-(Tarr value);
	void operator-(int j);
	void operator[](int j);

};


template <class Tarr>
Array<Tarr>::Array()
{
	size = 0;
	arr = new Tarr[size];
}

template <class Tarr>
Array<Tarr>::~Array()
{
	delete[] arr;
	arr = NULL;
}

template <class Tarr>
void Array<Tarr>::input(Tarr value)
{
	if (size == max)
	{
		throw ("Over max size ");
	}
	else
	{
		auto* new_arr = new Tarr[size+1];
		for (int i = 0; i < size; i++)
		{
			new_arr[i] = this->arr[i];
		}
		new_arr[size] = value;
		size++;
		delete[] this->arr;
		this->arr = new_arr;
	}
}

template <class Tarr>
void Array<Tarr>::print()
{
	for (int i = 0; i < size; i++)
	{
		cout << arr[i] << " ";
	}
	cout << endl;
}

template <class Tarr>
void Array<Tarr>::operator-(Array& arr)
{
	auto* arr1 = this->arr;
	auto* arr2 = arr.arr;

	if (size < arr.size) 
	{

		for (int i = 0; i < size; i++)
		{
			arr1[i] = arr1[i] - arr2[i];
		}
	}
	else
	{
		for (int i = 0; i < arr.size; i++)
		{
			arr1[i] = arr1[i] - arr2[i];
		}
	}
}

/*template <class Tarr>
void Array<Tarr>::operator-(Tarr value)
{
	auto* arr1 = this->arr;

	for (int i = 0; i < size; i++)
	{
		arr1[i] = arr1[i] - value;
	}
}*/

template <class Tarr>
void Array<Tarr>::operator-(int j)
{
	if (j > size)
		throw ("Have not this element ");
	j--;
	auto* new_arr = new Tarr[size-1];

	for (int i = 0; i < j; i++)
	{
		new_arr[i] = arr[i];
	}
	for (int k = j + 1; k < size; k++)
	{
		new_arr[k-1] = arr[k];
	}
	size--;
	delete[] arr;
	this->arr = new_arr;
	
}

template <class Tarr>
void Array<Tarr>::operator[](int j)
{
	if (j > size)
		throw ("Have not this element ");
	j--;
	cout << arr[j] << endl;
}