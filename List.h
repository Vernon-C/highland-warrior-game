#pragma once

//A modified version of a Doubly Linked List Class is needed.
#include"DoublyLinkedList.h"

/*
* Here be a weird List ADT
* It is not a traditional List, because it does not Push/Pop from both ends, nor does it Insert within the list.
* Instead, it Appends, Prepends, Removes and has a [] operator.
*/
template<class DataType>
class List
{
private:
	//Use pointers to hold the First and Last Node in the Linked List (LL).
	DoublyLinkedNode<DataType>* fTop;
	DoublyLinkedNode<DataType>* fLast;

	//Use fCount to keep track of how many Nodes is currently in the LL.
	int fCount;

public:
	//Default Constructor. Just initialize everything to NUll and zero.
	List()
	{
		fTop = nullptr;
		fLast = nullptr;
		fCount = 0;
	}

	//Destructor. Before this List is erased, you'll have to manually
	//loop through the LL and delete each Node. 
	~List()
	{
		while (fTop != &(DoublyLinkedNode<DataType>::NIL))	//While not yet at the end of the List
		{
			DoublyLinkedNode<DataType>* Temp = fTop;		//Use a Temp pointer to hold the current Node
			fTop = &fTop->getNext();						//Move the Top pointer to 1 node forwards.
			Temp->remove();									//Delete the Node Temp was pointing to.
			fCount--;										//Don't forget to reduce the fCount.
		}
	}

	//Helper function. Checks if the LL is empty.
	bool isEmpty() const
	{
		if (fCount == 0)
			return true;
		else
			return false;
	}

	//Helper function. Returns the current number of Nodes in the LL.
	int size() const
	{
		return fCount;
	}

	//AKA Add new node at the Top of the List. aElement is the new item (not new Node!).
	void prepend(const DataType& aElement)
	{
		//Create a new node and put that item inside.
		DoublyLinkedNode<DataType>* NewNode = new DoublyLinkedNode<DataType>(aElement);

		if (isEmpty())	//If the current LL is empty, then let both pointers point to the new Node.
		{
			fTop = NewNode;
			fLast = NewNode;
		}
		else			//Otherwise, fTop must point to the New Node, and New Node's Next points to the previous fTop.
		{
			DoublyLinkedNode<DataType>* Temp = fTop;
			fTop = NewNode;
			fTop->append(*Temp);
		}

		fCount++;		//You've added a new node into the LL, so increment this fCount.
	}

	//AKA Add new node at the End of the List. aElement is the new item (not new Node!).
	void append(const DataType& aElement)
	{
		//Create a new node and put that item inside.
		DoublyLinkedNode<DataType>* NewNode = new DoublyLinkedNode<DataType>(aElement);

		if (isEmpty())	//If the current LL is empty, then let both pointers point to the new Node.
		{
			fTop = NewNode;
			fLast = NewNode;
		}
		else			//Otherwise, fLast must point to the New Node, and New Node's Prev points to the previous fLast.
		{
			DoublyLinkedNode<DataType>* Temp = fLast;
			fLast = NewNode;
			fLast->prepend(*Temp);
		}

		fCount++;		//You've added a new node into the LL, so increment this fCount.
	}

	//This function Removes the first element (from the backside) whose item matches the aElement.
	void remove(const DataType& aElement)
	{
		DoublyLinkedNode<DataType>* Cursor = fTop;

		int aIndex = fCount - 1;	//Because max aIndex value is fCount - 1

		while (aIndex != 0)			//Loop through the whole LL.
		{
			//If there is a match, remove this Node from the LL, decrement your Node Count, then exit the Loop.	
			if (Cursor->getValue() == aElement)
			{
				Cursor->remove();
				fCount--;
				break;
			}
			else	//Else, move the temp pointer forwards and decrement the Index (else infinite loop).							
			{
				Cursor = &Cursor->getNext();
				aIndex--;
			}
		}
	}

	//Makes the List behave like an Array, by implementing some sort of [] indexing system.
	const DataType& operator[](int aIndex) const
	{
		if ((aIndex < fCount) && (aIndex >= 0))	//Make sure the Index is not some -ve number or outside the bounds.
		{
			const DoublyLinkedNode<DataType>* Cursor = fLast;	//Start indexing from the Last (the oldest Node)

			//Keep looping until the number of "index" is reached.
			while (aIndex != 0)
			{
				aIndex--;
				Cursor = &Cursor->getPrevious();
			}

			//Return the value stored at the "destination index" node.
			return (Cursor->getValue());
		}
	}
};