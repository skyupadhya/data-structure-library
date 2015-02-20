#include <iostream>

using namespace std;
template<class Type>
struct nodeType
{
	Type info;
	nodeType<Type> *link;
};
template<class Type>
class queueType
{
public:
	void initializeQueue();
	Type front();
	Type back();
	void add(const Type &newElement);
	void deleteElement();
	bool isEmpty();
	bool isFull();
	int queueCount();

	queueType();
	~queueType();
	queueType(const queueType& otherQueue);
	queueType<Type> & operator=(const queueType& otherQueue);

private:
	nodeType<Type> *frontPtr,*backPtr;
	int count;
	void copyQueue(const queueType<Type> &);

};

template<class Type>
queueType<Type>::queueType()
{
	frontPtr = NULL;
	backPtr =NULL;
	count = 0;
}

template<class Type>
queueType<Type>::~queueType()
{
	nodeType<Type> *temp;
	while(frontPtr != NULL)
	{
		temp = frontPtr;
		frontPtr = frontPtr->link;
		delete temp;
	}
	backPtr = NULL;
}
template<class Type>
void queueType<Type>::initializeQueue()
{
	nodeType<Type> *temp;
	count = 0;
	while(frontPtr != NULL)
	{
		temp = frontPtr;
		frontPtr = frontPtr->link;
		delete temp;
	}
	backPtr = NULL;
}

template<class Type>
Type queueType<Type>::front()
{
	if(frontPtr != NULL)
		return frontPtr->info;
	else
		cout<<"\nEmpty queue.\n";
}

template<class Type>
Type queueType<Type>::back()
{
	if(frontPtr != NULL)
		return backPtr->info;
	else
		cout<<"\nEmpty queue.\n";
}

template<class Type>
void queueType<Type>::add(const Type &newElement)
{
	nodeType<Type> *newNode = new nodeType<Type>;
	newNode->info = newElement;
	newNode->link = NULL;
	count++;
	if(frontPtr == NULL)
	{
		frontPtr = newNode;
		backPtr = newNode;
	}
	else
	{
		backPtr->link = newNode;
		backPtr = newNode;
	}
}

template<class Type>
void queueType<Type>::deleteElement()
{
	nodeType<Type> *temp;
	if(frontPtr != NULL)
	{
		//case 1 only one node - need to change frontptr and backptr
		//case 2 more than 1 node - need to change frontptr

		if(frontPtr == backPtr)
		{
			temp = frontPtr;
			delete temp;
			count--;
			frontPtr = NULL;
			backPtr = NULL;
		}
		else
		{
			temp = frontPtr;
			frontPtr = frontPtr->link;
			delete temp;
			count--;
		}

	}
}

template<class Type>
bool queueType<Type>::isEmpty()
{
	return (frontPtr == NULL);
}

template<class Type>
bool queueType<Type>::isFull()
{
	return false;
}

template<class Type>
void queueType<Type>::copyQueue(const queueType<Type> &otherQueue)
{
	nodeType<Type> *current, *newNode;
	if(frontPtr != NULL)
		initializeQueue();
	if(otherQueue.frontPtr == NULL)
	{
		frontPtr = NULL;
		backPtr = NULL;
	}
	else
	{
		current = otherQueue.frontPtr;

		frontPtr = new nodeType<Type>;
		frontPtr->info = current->info;
		frontPtr->link = NULL;
		backPtr = frontPtr;
		current = current->link;

		while(current != NULL)
		{
			newNode = new nodeType<Type>;
			newNode->info = current->info;
			newNode->link = NULL;
			backPtr->link = newNode;
			backPtr = newNode;
			current = current->link;
		}
	}
	count = otherQueue.count;
}

template<class Type>
queueType<Type>::queueType(const queueType& otherQueue)
{
	frontPtr = NULL;
	backPtr = NULL;
	copyQueue(otherQueue);
}
template<class Type>
queueType<Type>& queueType<Type>::operator=(const queueType& otherQueue)
{
	//if(this != otherQueue)
		copyQueue(otherQueue);
}

template<class Type>
int queueType<Type>::queueCount()
{
	return count;
}