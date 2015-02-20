#include <iostream>
#include <cassert>
using namespace std;

template<class Type>
class queueType
{
public:
	void initializeQueue();
	bool isEmpty() const;
	bool isFull() const;
	Type front() const;
	Type back() const;
	void add(const Type &newElement);
	void deleteQueue();
	int sizeQueue();
	void moveNthFront(int n);
	void display();

	queueType(int size=100);
	~queueType();
	queueType(const queueType<Type> &);
	queueType<Type>& operator=(const queueType<Type>&);
private:
	int maxQueue;
	int count;
	int queueRear;
	int queueFront;
	Type *list;
	void copyQueue(const queueType<Type>&);
};

template<class Type>
void queueType<Type>::initializeQueue()
{
	count = 0;
	queueFront = 0;
	queueRear = maxQueue-1;
}

template<class Type>
bool queueType<Type>::isEmpty() const
{
	return (count == 0);
}

template<class Type>
bool queueType<Type>::isFull() const
{
	return (count == maxQueue);
}

template<class Type>
Type queueType<Type>::front() const
{
	assert(!isEmpty());
	return list[queueFront];
}

template<class Type>
Type queueType<Type>::back() const
{
	assert(!isEmpty());
	return list[queueRear];
}

template<class Type>
queueType<Type>::queueType(int size)
{
	if(size <= 0)
	{
		maxQueue = 100;
	}
	else
		maxQueue = size;
	queueFront = 0;
	queueRear = maxQueue-1;
	count = 0;
	list = new Type[maxQueue];
}

template<class Type>
queueType<Type>::~queueType()
{
	delete [] list;
}

template<class Type>
queueType<Type>::queueType(const queueType<Type> &otherQueue)
{
	this->copyQueue(otherQueue);
}

template<class Type>
void queueType<Type>::add(const Type &newElement)
{
	if(!isFull())
	{
		queueRear = (queueRear + 1) % maxQueue;
		count++;
		list[queueRear] = newElement;
	}
	else
	    cout<<"\nCannot add an element.Queue is full.\n";
}
template<class Type>
void queueType<Type>::deleteQueue()
{
	assert(!isEmpty());
	queueFront = (queueFront + 1) % maxQueue;
	count--;
}

template<class Type>
queueType<Type>& queueType<Type>::operator=(const queueType<Type>& otherQueue)
{
	this->copyQueue(otherQueue);
}

template<class Type>
int queueType<Type>::sizeQueue()
{
	return count;
}

template<class Type>
void queueType<Type>::copyQueue(const queueType<Type>& otherQueue)
{
	this->initializeQueue();
	count = otherQueue.count;
	maxQueue = otherQueue.maxQueue;
	queueFront = otherQueue.queueFront;
	queueRear = otherQueue.queueRear;
	list = new Type[maxQueue];
	for(int i = queueFront;i <= queueRear; i++)
	{
		list[i] = otherQueue.list[i];
	}
}

template<class Type>
void queueType<Type>::moveNthFront(int n)
{
	Type temp = list[n-1];
	for(int i = n-1; i > queueFront; i--)
	{
		list[i] = list[i-1];
	}
	list[queueFront] = temp;
}

template<class Type>
void queueType<Type>::display()
{
	cout<<endl;
	for(int i = queueFront; i <= queueRear; i++)
	{
		cout<<list[i]<<" ";
	}
}

