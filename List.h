#pragma once
#include "DoublyLinkedList.h"

template<class DataType>

class List
{
private:
	DoublyLinkedList<DataType>* top;
	DoublyLinkedList<DataType>* last;
	int count;

public:
	/* Default constructor */
	List()
	{
		top = nullptr;
		last = nullptr;
		count = 0;
	}

	/* Destructor */
	~List()
	{
		while (top != &(DoublyLinkedList<DataType>::NIL))
		{
			DoublyLinkedList<DataType>* Temp = top;
			top = &top->getNext();
			Temp->remove();
			count--;
		}
	}

	bool isEmpty() const
	{
		if (count == 0)
			return true;
		else
			return false;
	}

	/* Returns size of the list */
	int size() const
	{
		return count;
	}

	/* Adds an element to the list at the top point */
	void prepend(const DataType& aElement)
	{
		DoublyLinkedList<DataType>* NewNode = new DoublyLinkedList<DataType>(aElement);

		if (isEmpty())
		{
			top = NewNode;
			last = NewNode;
		}
		else
		{
			DoublyLinkedList<DataType>* Temp = top;
			top = NewNode;
			top->append(*Temp);
		}

		count++;
	}

	/* Adds an element to the list at the last point */
	void append(const DataType& aElement)
	{
		DoublyLinkedList<DataType>* NewNode = new DoublyLinkedList<DataType>(aElement);

		if (isEmpty())
		{
			top = NewNode;
			last = NewNode;
		}
		else
		{
			DoublyLinkedList<DataType>* Temp = last;
			last = NewNode;
			last->prepend(*Temp);
		}

		count++;
	}

	/* Removes an element from the list */
	void remove(const DataType& aElement)
	{
		DoublyLinkedList<DataType>* Cursor = top;

		int index = count - 1;

		while (index != 0)
		{
			if (Cursor->getValue() == aElement)
			{
				Cursor->remove();
				count--;
				break;
			}
			else						
			{
				Cursor = &Cursor->getNext();
				index--;
			}
		}
	}

	/* Index operator */
	const DataType& operator[](int _index) const
	{
		if ((_index < count) && (_index >= 0))
		{
			const DoublyLinkedList<DataType>* Cursor = last;

			while (_index != 0)
			{
				_index--;
				Cursor = &Cursor->getPrevious();
			}

			return (Cursor->getValue());
		}
	}
};