#pragma once

template<class DataType>

class DoublyLinkedList
{
private:
	DataType value;
	DoublyLinkedList<DataType>* next;
	DoublyLinkedList<DataType>* previous;

	/* Default constructor */
	DoublyLinkedList()
	{
		value = DataType();
		next = &NIL;
		previous = &NIL;
	}

public:
	static DoublyLinkedList<DataType> NIL;
	DoublyLinkedList(const DataType& aValue);
	void prepend(DoublyLinkedList<DataType>& _node);
	void append(DoublyLinkedList<DataType>& _node);
	void remove();

	const DataType& getValue() const
	{
		return value;
	}

	DoublyLinkedList<DataType>& getNext() const
	{
		return *next;
	}

	DoublyLinkedList<DataType>& getPrevious() const
	{
		return *previous;
	}
};

/* Define NIL */
template<class DataType>
DoublyLinkedList<DataType> DoublyLinkedList<DataType>::NIL;

/* Overloaded constructor */
template<class DataType>
DoublyLinkedList<DataType>::DoublyLinkedList(const DataType& aValue)
{
	value = aValue;
	next = &NIL;
	previous = &NIL;
}

/* Add element to the top node */
template<class DataType>
void DoublyLinkedList<DataType>::prepend(DoublyLinkedList<DataType>& _node)
{
	_node.next = this;

	if (previous != &NIL)
	{
		_node.previous = previous;
		previous->next = &_node;
	}

	previous = &_node;
}

/* Add element to the last node */
template<class DataType>
void DoublyLinkedList<DataType>::append(DoublyLinkedList<DataType>& _node)
{
	_node.previous = this;

	if (next != &NIL)
	{
		_node.next = next;
		next->previous = &_node;
	}

	next = &_node;
}

/* Removes a node */
template<class DataType>
void DoublyLinkedList<DataType>::remove()
{
	if (next == &NIL)
	{
		previous->next = &NIL;
	}
	else if (previous == &NIL)
	{
		next->previous = &NIL;
	}
	else
	{
		previous->next = next;
		next->previous = previous;
	}

	delete this;
}

