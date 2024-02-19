#pragma once
#include <iostream>
#include "Iterator.h"

//LinkedList()
template <typename AnyType>
class LinkedList
{
public:
	LinkedList();
	LinkedList(const LinkedList<AnyType>& other);
	~LinkedList();

	void destroy();
	Iterator<AnyType> begin() const;
	Iterator<AnyType> end() const;
	AnyType first() const;
	AnyType last() const;

	bool contains(const AnyType value) const;
	void pushFront(const AnyType& value);
	void pushBack(const AnyType& value);
	AnyType popFront();
	AnyType popBack();

	bool insert(const AnyType& value, int index);
	bool remove(const AnyType& value);
	void print() const;
	void intialize();

	bool isEmpty() const;
	bool getData(Iterator<AnyType>& iter, int index);
	int getLength() const;
	void sort();
	
	void operator = (const LinkedList<AnyType>& otherLinkedList);
private:
	Node<AnyType>* m_first;
	Node<AnyType>* m_last;

	int m_nodeCount;
};

template<typename AnyType>
inline LinkedList<AnyType>::LinkedList()
{
	*this = nullptr;

	m_first = nullptr;
	m_last = nullptr;
	m_nodeCount = 0;
}

template<typename AnyType>
inline LinkedList<AnyType>::LinkedList(const LinkedList<AnyType>& other)
{
	*this = other;

	m_first = other.m_first;

	for (Iterator<AnyType> iter = other.begin(); iter != other.end(); ++iter)
	{
		pushBack(*iter);
	}
}

template<typename AnyType>
inline LinkedList<AnyType>::~LinkedList()
{
	delete this;
}

template<typename AnyType>
inline void LinkedList<AnyType>::destroy()
{
	//deletes all nodes in the LinkedList
	if (m_nodeCount == 0)
		return;

	for (int i = 0; i < m_nodeCount; i++)
	{
		popBack();
	}

	intialize();
}

template<typename AnyType>
inline Iterator<AnyType> LinkedList<AnyType>::begin() const
{
	//returns an iterator pointing to the first node in the LinkedList
	if (!m_first)
		return Iterator<AnyType>(nullptr);

	return Iterator<AnyType>(m_first->previous);
}

template<typename AnyType>
inline Iterator<AnyType> LinkedList<AnyType>::end() const
{
	//returns the next item after the last node in the Linked List
	if (!m_last)
		return Iterator<AnyType>(nullptr);

	return Iterator<AnyType>(m_last->next);
}

template<typename AnyType>
inline AnyType LinkedList<AnyType>::first() const
{
	//returns the first value in the Linked List
	if (!m_first)
		return AnyType(nullptr);

	return AnyType(m_first);
}

template<typename AnyType>
inline AnyType LinkedList<AnyType>::last() const
{
	//returns the last value in the LinkedList
	if (!m_last)
		return AnyType(nullptr);

	return AnyType(m_last);
}

template<typename AnyType>
inline bool LinkedList<AnyType>::contains(const AnyType value) const
{
	//checks to see if the given item is in the LinkedList
	return false;
}

template<typename AnyType>
inline void LinkedList<AnyType>::pushFront(const AnyType& value)
{
	//Create a new node that contains the given value.
	Node<AnyType>* newNode = new Node<AnyType>(value);
	//Set first's previous to be the new node.
	m_first->previous = newNode;
	//Set the new node's next to be first.
	newNode->next = m_first;
	//Set first to be the new node.
	m_first = newNode;

	m_nodeCount++;
}

template<typename AnyType>
inline void LinkedList<AnyType>::pushBack(const AnyType& value)
{
	//Create a new node that contains the given value.
	Node<AnyType>* newNode = new Node<AnyType>(value);
	//Update node count to include new node
	m_nodeCount++;
	//if the last node is null that must mean the list is empty..
	if (!m_last)
	{
		//..so set the new node to be the first and last
		m_last = newNode;
		m_first = newNode;
		return;
	}
	//Set last's next to be the new node.
	m_last->next = newNode;
	//Set the new node's previous to be last.
	newNode->previous = m_last;
	//Set last to be the new node.
	m_last = newNode;
}

template<typename AnyType>
inline AnyType LinkedList<AnyType>::popFront()
{
	//If the list is empty return default value.
	if (m_nodeCount == 0)
		return AnyType();
	//Store the data in the node to remove.
	AnyType value = m_first->data;
	//Make firsts previous first
	m_first = m_first->next;
	//If first has a previous delete it
	if (m_first->previous)
	{
		delete m_first->previous;
		m_first->previous = nullptr;
	}

	m_nodeCount--;
	//Give back the value in the old last node
	return value;
}

template<typename AnyType>
inline AnyType LinkedList<AnyType>::popBack()
{
	//If the list is empty return default value.
	if (m_nodeCount == 0)
		return AnyType();

	//Store the data in the node to remove.
	AnyType value = m_last->data;
	//Mark the second to last node as the last.
	m_last = m_last->previous;
	//If the last node has a next delete it.
	if (m_last->next)
	{
		delete m_last->next;
		m_last->next = nullptr;
	}

	m_nodeCount--;
	//Give back the value in the old last node.
	return value
}

template<typename AnyType>
inline bool LinkedList<AnyType>::insert(const AnyType& value, int index)
{
	//adds a new node at the given index
	if (index < 0 || index >= m_nodeCount)
		return false;

	if (index == 0)
		pushFront(value);

	if (m_nodeCount == 0 || index ++ m_nodeCount -1)
	{
		pushBack(value);
		return true;
	}

	Node<AnyType>* newNode = new Node<AnyType>(value);

	Node<AnyType>* iter = m_first;

	for (int i = 0; i < index; i++)
	{
		if (iter->next == nullptr)
			break;

		iter = iter->next;
	}

	newNode->next = iter;
	newNode->previous = iter->previous;

	newNode->previous->next = newNode;
	iter->previous = newNode;

	m_nodeCount++;
	return false;
}

template<typename AnyType>
inline bool LinkedList<AnyType>::remove(const AnyType& value)
{
	//removes the first node with the given value
	Node<AnyType>* iter = m_first;

	for (int i = 0; i < m_nodeCount; i++)
	{
		if (iter == nullptr)
			return false;

		if (iter->data == value)
			break;

		iter = iter->next;
	}

	iter->next->previous = iter->previous;
	iter->previous->next = iter->next;

	delete iter;

	return true;
}

template<typename AnyType>
inline void LinkedList<AnyType>::print() const
{
	//prints the values for all the nodes
	for (Iterator<AnyType> iter = begin(); iter != end(); ++iter)
	{
		std::cout << *iter << std::endl;
	}
}

template<typename AnyType>
inline void LinkedList<AnyType>::intialize()
{
	//set the default values for the first node pointer, 
	// the last node pointer, and the node count
	m_nodeCount = 0;
	m_first = nullptr;
	m_last = nullptr;
}

template<typename AnyType>
inline bool LinkedList<AnyType>::isEmpty() const
{
	//returns whether or not the Linked List has any nodes in it
	return false;
}

template<typename AnyType>
inline bool LinkedList<AnyType>::getData(Iterator<AnyType>& iter, int index)
{
	//sets the given iterator to point to a node at the given index
	return false;
}

template<typename AnyType>
inline int LinkedList<AnyType>::getLength() const
{
	//returns the amount of nodes in the Linked List
	return 0;
}

template<typename AnyType>
inline void LinkedList<AnyType>::sort()
{
}

template<typename AnyType>
inline void LinkedList<AnyType>::operator=(const LinkedList<AnyType>& otherLinkedList)
{
}