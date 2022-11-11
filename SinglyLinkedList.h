#pragma once

template <class T>

class SinglyLinkedList
{
public:
	T item;
	SinglyLinkedList* next;

	/* Default constructor */
	SinglyLinkedList()
	{
		item = "";
		next = nullptr;
	}

	SinglyLinkedList(T n)
	{
		item = n;
		next = nullptr;
	}

	SinglyLinkedList(T n, SinglyLinkedList* p)
	{
		item = n;
		next = p;
	}

	/* Destructor */
	~SinglyLinkedList() {}
};
