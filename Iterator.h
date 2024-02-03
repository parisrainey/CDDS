#pragma once
#include <iostream>
#include "Node.h"

//Iterator()
template<typename T>
class Iterator
{
public:
	//Iterator(Node<T>* node)
	template<typename T>
	inline bool Iterator<T>::Iterator(Node<T> * node)
	{
		 
	}

	//operator ++(): Iterator<T>
	bool operator ++ (Iterator<T>)
	{

	}

	//operator --(): Iterator<T>
	bool operator -- (Iterator<T>)
	{

	}

	//operator == (const Iterator<T> & iter): const bool
	template<typename T>
	inline bool Iterator<T>::operator==(const Iterator<T>& iter) const
	{
		return false;
	}

	//operator != (const Iterator<T> & iter): const bool
	bool operator != (const Iterator<T> & iter) const 
	{
		
	}

	//operator*(): T
	
private:
	//m_current : Node<T>*
	Node<T>::int m_current
};