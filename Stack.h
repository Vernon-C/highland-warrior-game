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

	~Stack() {}

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

	/* Checks if the stack is empty */
	bool isEmpty()
	{
		return top == NULL;
	}

	/* Returns the element at the top */
	DataType peek()  // Can't name this pop()
	{
		if (!isEmpty())
			return top->item;
		else
			exit(1);
	}

	/* Removes the top element */
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
