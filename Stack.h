#pragma once
#include "List.h"
#include "SinglyLinkedList.h"

template <class DataType>

class Stack
{
private:
	SinglyLinkedList<DataType>* top;

public:
	Stack()
	{
		top = NULL;
	}

	void push(DataType _element)
	{
		SinglyLinkedList<DataType>* temp = new SinglyLinkedList<DataType>(_element);

		if (!temp)
		{
			cout << endl << "Stack Overflow" << endl;
			exit(1);
		}

		temp->item = _element;
		temp->next = top;
		top = temp;
	}

	bool isEmpty()
	{
		return top == NULL;
	}

	DataType peek()
	{
		if (!isEmpty())
			return top->item;
		else
			exit(1);
	}

	void pop()
	{
		SinglyLinkedList<DataType>* temp;

		if (top == NULL)
		{
			cout << endl << "Stack Underflow" << endl;
			exit(1);
		}
		else
		{
			temp = top;
			top = top->next;

			free(temp);
		}
	}
};
