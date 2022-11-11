#pragma once
#include <string>

using namespace std;

class Iterator
{
private:
	int index;
	int size;
	string* array;

public:
	/* Default constructor */
	Iterator();

	/* Overloaded constructor */
	Iterator(string _array[], int _index, int _size);

	/* Constructor to use the begin() function */
	Iterator(int _index, int _size);

	/* Constructor to use the end() function */
	Iterator(const Iterator& _iter, int _index);

	/* Destructor */
	~Iterator();

	/* Iterator operators */
	Iterator& operator++();
	Iterator operator++(int);
	Iterator& operator--();
	Iterator operator--(int);

	string operator*();

	bool operator==(const Iterator& _other) const;
	bool operator!=(const Iterator& _other) const;

	Iterator begin() const;
	Iterator end() const;
};
