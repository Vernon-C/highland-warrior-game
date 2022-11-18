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
		top = nullptr;
		last = nullptr;
	}

	~Queue() {}

	void push(DataType _element)
	{
		SinglyLinkedList<DataType>* temp = new SinglyLinkedList<DataType>(_element);

		/* Creates new node if the queue is empty */
		if (last == nullptr)
		{
			top = temp;
			last = temp;
			return;
		}

		/* Add new node at the end and move the previous last node */
		last->next = temp;
		last = temp;
	}

	/* Removes the top element */
	void pop()
	{
		/* Return if queue is empty */
		if (top == nullptr)
			return;

		SinglyLinkedList<DataType>* temp = top;
		top = top->next;

		/* When top is null, last must be null */
		if (top == nullptr)
			last = nullptr;

		/* Frees up memory */
		delete(temp);
	}

	DataType peek()  // Can't name this pop()
	{
		return this->top->item;
	}

	bool isEmpty()
	{
		return top == nullptr;
	}
};
