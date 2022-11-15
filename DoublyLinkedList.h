#pragma once
template<class DataType>
class DoublyLinkedNode
{
public:
	typedef DoublyLinkedNode<DataType> Node;
private:
	DataType fValue;
	Node* fNext;
	Node* fPrevious;
	DoublyLinkedNode()
	{
		fValue = DataType();
		fNext = &NIL;
		fPrevious = &NIL;
	}
public:
	static Node NIL;
	DoublyLinkedNode(const DataType& aValue);
	void prepend(Node& aNode);
	void append(Node& aNode);
	void remove();
	const DataType& getValue() const
	{
		return fValue;
	}

	//Slightly modified. Does not return a const reference anymore
	Node& getNext() const
	{
		return *fNext;
	}

	//Slightly modified. Does not return a const reference anymore
	Node& getPrevious() const
	{
		return *fPrevious;
	}
};

template<class DataType>
DoublyLinkedNode<DataType> DoublyLinkedNode<DataType>::NIL;

template<class DataType>
DoublyLinkedNode<DataType>::DoublyLinkedNode(const DataType& aValue)
{
	fValue = aValue;
	fNext = &NIL;
	fPrevious = &NIL;
}

template<class DataType>
void DoublyLinkedNode<DataType>::prepend(Node& aNode)
{
	aNode.fNext = this; // make this the forward pointer of aNode
	if (fPrevious != &NIL) // make this's backward pointer aNode's
	{ // backward pointer and make previous'
		aNode.fPrevious = fPrevious; // forward pointer aNode
		fPrevious->fNext = &aNode;
	}
	fPrevious = &aNode; // this' backward pointer becomes aNode
}

template<class DataType>
void DoublyLinkedNode<DataType>::append(Node& aNode)
{
	aNode.fPrevious = this; // make this the backward pointer of aNode
	if (fNext != &NIL) // make this's forward pointer aNode's
	{ // forward pointer and make next
		aNode.fNext = fNext; // forward pointer aNode
		fNext->fPrevious = &aNode;
	}
	fNext = &aNode; // this' backward pointer becomes aNode
}

template<class DataType>
void DoublyLinkedNode<DataType>::remove()
{
	if (fNext == &NIL)
	{
		fPrevious->fNext = &NIL;
	}
	else if (fPrevious == &NIL)
	{
		fNext->fPrevious = &NIL;
	}
	else
	{
		fPrevious->fNext = fNext;
		fNext->fPrevious = fPrevious;
	}

	//Uncommented this so we directly delete this Node. Only usable for Heap.
	delete this;
}

