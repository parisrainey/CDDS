#pragma once
#include <iostream>

//Node();
template<typename AnyType>
struct Node
{
	Node();
	Node(AnyType value);

	Node<AnyType>* next;
	Node<AnyType>* previous;
	
	AnyType data;
};

template<typename AnyType>
inline Node<AnyType>::Node()
{
	next = nullptr;
	previous = nullptr;
}

template<typename AnyType>
inline Node<AnyType>::Node(AnyType newData)
{
	next = nullptr;
	previous = nullptr;
	data = newData;
}
