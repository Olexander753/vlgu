#include <iostream>

using namespace std;
template <class S_type> class Stack

{
private:
    int size{ 0 };
    int capacity;
    S_type* arr{ nullptr };
    int max = 10;

public:
   
    Stack(int isize);
    ~Stack();
    void print();
    void pop();
};

template <class S_type>
Stack <S_type>::Stack(int isize)
{
    if (isize > max)
    {
        throw ("Too big size ");
    }
    arr = new S_type[isize];
    if (!arr)
    {
        throw ("Have not memory ");
    }
    capacity = isize;
    for (int i = 0; i < capacity; i++)
    {
        arr[i] = rand() % 20;
        size++;
    }
};

template <class S_type>
Stack <S_type>::~Stack()
{
    delete[] arr;
}


template <class S_type>
void Stack <S_type>::print()
{
    if (size == 0)
    {
        throw ("Stack is empty ");
    }
    for (int i = 0; i < size; i++)
    {
        cout << arr[i] << " ";
    }
    cout << endl;
}

template <class S_type>
void Stack <S_type>::pop()
{
    if (size == 0)
    {
        throw ("Stack is empty ");
    }
    if (capacity > size)
    {
        arr[size--] = 0;
        return;
    }
    size--;
    S_type* arrq = new S_type[size];
    for (int i = 0; i < size; i++)
    {
        arrq[i] = arr[i];
    }
    delete[] arr;
    arr = arrq;
}

int main()
{
    try
    {
        Stack <double> a(11);
        a.print();
        a.pop();
        a.print();
    }
    catch (const char* error)
    {
        cerr << error;
        exit(-231);
    }
}