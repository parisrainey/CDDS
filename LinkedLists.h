#pragma once
#include <iostream>
#include "Node.h"
#include "Iterator.h"

//LinkedList()
template <typename T>
class LinkedList
{
public:
	//LinkedList(const LinkedList<T>& other)
	template<typename T>
	inline LinkedList<T>::LinkedList(const LinkedList<T> & other)
	{
		*this = other;

		m_first = other.m_first;

		for (Iterator<T> iter = other.begin(); iter != other.end(); ++iter)
		{
			pushBack(*iter);
		}
	}
	//~LinkedList()
	template<typename T>
	inline LinkedList<T>::~LinkedList()
	{
		delete this;
	}
	//destroy(): void

	//begin() const: Iterator<T>

	//end() const: Iterator<T>

	//first() const: T

	//last() const: T

	//contains(const T value)const : bool

	//pushFront(const T& value): void
	template<typename T>
	inline void LinkedList<T>::pushFront(const T& value)
	{
		//Create a new node that contains the given value.
		Node<T>* newNode = new Node<T>(value);
		//Set first's previous to be the new node.
		m_first->previous = newNode;
		//Set the new node's next to be first.
		newNode->next = m_first;
		//Set first to be the new node.
		m_first = newNode;
		//Increase Linked List node count.
		m_nodeCount++;
		//If node count is 1 make new node last.
		if (m_nodeCount == 0)
			m_last = newNode;
	}
	//pushBack(const T& value): void

	//popFront(): T

	//popBack(): T

	//insert(const T& value, int index): bool

	//remove(const T& value): bool

	//print() const:void

	//initialize():void

	//isEmpty() const:bool

	//getData(Iterator<T>& iter, int index):bool

	//getLength() const:int

	//operator = (const LinkedList<T> &otherLinkedList):void

	//sort():void
private:
	//m_first/m_head : Node<T>*

	//m_last/m_tail : Node<T>*

	//m_nodeCount : int
};