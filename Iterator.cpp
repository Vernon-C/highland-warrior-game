#include "Iterator.h"

/* Default constructor */
Iterator::Iterator()
{
	index = 0;
	size = 0;
	array = nullptr;
}

/* Overloaded constructor */
Iterator::Iterator(string _array[], int _index, int _size)
{
	array = _array;
	index = _index;
	size = _size;
}

/* Constructor to use the begin() function */
Iterator::Iterator(int _index, int _size)
{
	index = _index;
	size = _size;
}

/* Constructor to use the end() function */
Iterator::Iterator(const Iterator& _iter, int _index)
{
	array = _iter.array;
	size = _iter.size;
	index = _index;
}

/* Destructor */
Iterator::~Iterator() {}

Iterator& Iterator::operator++()
{
	index++;
	return *this;
}

// Refrence: https://cplusplus.com/reference/iterator/move_iterator/operator++/
Iterator Iterator::operator++(int)
{
	Iterator temp = *this;
	++(*this);

	return temp;
}

Iterator& Iterator::operator--()
{
	index--;
	return *this;
}

Iterator Iterator::operator--(int)
{
	Iterator temp = *this;
	--(*this);

	return temp;
}

string Iterator::operator*()
{
	return array[index];
}

bool Iterator::operator==(const Iterator& _other) const
{
	return (index == _other.index);
}

bool Iterator::operator!=(const Iterator& _other) const
{
	return !(index == _other.index);
}

Iterator Iterator::begin() const
{
	return Iterator(0, size);
}

Iterator Iterator::end() const
{
	return Iterator(*this, size);
}
