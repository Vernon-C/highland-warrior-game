#pragma once

template <class DataType>

class DoublyLinkedList
{
private:
	DataType value;
	DoublyLinkedList* next;
	DoublyLinkedList* previous;

public:
	static DoublyLinkedList NIL;

	/* Constructor */
	DoublyLinkedList(const DataType& _value)
	{
		value = _value;
		next = &NIL;
		previous = &NIL;
	}

	void prepend(DoublyLinkedList _doublyLinkedList)
	{
		_doublyLinkedList.next = this;

		if (previous != &NIL)
		{
			_doublyLinkedList.previous = previous;
			previous->next = &_doublyLinkedList;
		}

		previous = _doublyLinkedList;
	}

	void append(DoublyLinkedList _doublyLinkedList)
	{
		_doublyLinkedList.previous = this;

		if (next != &NIL)
		{
			_doublyLinkedList.next = next;
			next->previous = &_doublyLinkedList;
		}

		next = _doublyLinkedList;
	}

	void remove()
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

	//May not be necessary
	const DataType& getValue() const
	{
		return value;
	}

	DoublyLinkedList& GetNext() const
	{
		return *next;
	}

	DoublyLinkedList& GetPrevious() const
	{
		return *previous;
	}
};
