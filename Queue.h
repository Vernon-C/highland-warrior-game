#pragma once
#include "SinglyLinkedList.h"

template <class DataType>

class Queue
{
private:
	SinglyLinkedList<DataType>* top;
	SinglyLinkedList<DataType>* last;

public:
	Queue()
	{
		top = NULL;
		last = NULL;
	}

	~Queue() {}

	void push(DataType _element)
	{
		SinglyLinkedList<DataType>* temp = new SinglyLinkedList<DataType>(_element);

		if (last == NULL)
		{
			top = temp;
			last = temp;
			return;
		}

		last->next = temp;
		last = temp;
	}

	void pop()
	{
		if (top == NULL)
			return;

		SinglyLinkedList<DataType>* temp = top;
		top = top->next;

		if (top == NULL)
			last = NULL;

		delete(temp);
	}

	DataType peek()
	{
		return this->top->item;
	}

	bool isEmpty()
	{
		return top == NULL;
	}
};
