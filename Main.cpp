#include <iostream>
#include "DynamicArray.h"

template<typename AnyType>
AnyType add(AnyType a, AnyType b)
{
	return a + b;
}

template<typename AnyType>
void print(AnyType value)
{
	std::cout << value << std::endl;
}

template<typename AnyType, int size>
void printArray(AnyType items[])
{
	for (int i = 0; i < size; i++)
	{
		print(items[i]);
	}
}

int main()
{
	
}