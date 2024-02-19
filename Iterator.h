#pragma once
#include <iostream>
#include "Node.h"

//Iterator()
template<typename AnyType>
class Iterator
{
public:
	Iterator();
	Iterator(Node<AnyType>* node);

	Iterator<AnyType> operator ++();
	Iterator<AnyType> operator--();
	const bool operator==(const Iterator<AnyType>& iter);
	const bool operator !=(const Iterator<AnyType>& iter);
	AnyType operator *();

private:
	Node<AnyType> m_current;
};

template<typename AnyType>
inline Iterator<AnyType>::Iterator()
{
	m_current = nullptr;
}

template<typename AnyType>
inline Iterator<AnyType>::Iterator(Node<AnyType>* node)
{
	m_current = node;
}

template<typename AnyType>
inline Iterator<AnyType> Iterator<AnyType>::operator++()
{
	if (!m_current)
		return Iterator<AnyType>(m_current);
	return Iterator<AnyType>(m_current->next);
}

template<typename AnyType>
inline Iterator<AnyType> Iterator<AnyType>::operator--()
{
	if (!m_current)
		return Iterator<AnyType>(m_current);

	return Iterator<AnyType>(m_current->previous);
}

template<typename AnyType>
inline const bool Iterator<AnyType>::operator==(const Iterator<AnyType>& iter)
{
	return m_current == iter.m_current;
}

template<typename AnyType>
inline const bool Iterator<AnyType>::operator!=(const Iterator<AnyType>& iter)
{
	return m_current != iter.m_current;
}

template<typename AnyType>
inline AnyType Iterator<AnyType>::operator*()
{
	return m_current->data;
}
