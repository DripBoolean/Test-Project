#pragma once
#include <string>
#include <iostream>

std::string msg();

//template classes are superior.
template <typename T> class Array {
private:
    T* ptr;
    int size;
    T test;

public:
    Array(T arr[], int s);
    void print();
    void get(int index);
};

template <typename T> Array<T>::Array(T arr[], int s)
{
    ptr = new T[s];
    size = s;
    for (int i = 0; i < size; i++)
        ptr[i] = arr[i];
}

template <typename T> void Array<T>::print()
{
    for (int i = 0; i < size; i++)
        std::cout << " " << *(ptr + i) << std::endl;
}

template <typename T> void Array<T>::get(int index)
{
    if (index >= size)
    {
        throw std::out_of_range("Index given is out of range.");
    }
    else
    {
        std::cout << "Number at index " << index << " is: " <<  * (ptr + index) << std::endl;
    }
}