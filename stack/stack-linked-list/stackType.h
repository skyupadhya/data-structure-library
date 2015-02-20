#include <iostream>
#include <cassert>
using namespace std;

template<class Type>
struct nodeType
{
	Type info;
	nodeType<Type> *link;
};

template<class Type>
class stackType
{
public:
	const stackType<Type>& operator=(const stackType<Type>&);
	bool operator==(stackType<Type>&);
	void initializeStack();
	bool isEmpty() const;
	bool isFull() const;
	void push(const Type& newElement);
	Type top() const;
	void pop();
	void reverseStack(stackType<Type> &otherStack);

	stackType();
	~stackType();
	stackType(const stackType<Type> &otherStack);

private:
	nodeType<Type> *stackTop;

	void copyStack(const stackType<Type> &otherStack);
};

template<class Type>
const stackType<Type>& stackType<Type>::operator=(const stackType<Type> &otherStack)
{
	if(stackTop != NULL)
		initializeStack();
	else
		copyStack(otherStack);
}

template<class Type>
void stackType<Type>::initializeStack()
{
	nodeType<Type> *temp;
	while(stackTop!= NULL)
	{
		temp = stackTop;
		stackTop = stackTop->link;
		delete temp;
	}
}

template<class Type>
bool stackType<Type>::isEmpty() const
{
	return(stackTop == NULL);
}

template<class Type>
bool stackType<Type>::isFull() const
{
	return false;
}

template<class Type>
void stackType<Type>::push(const Type& newElement)
{
	nodeType<Type> *newNode;
	newNode = new nodeType<Type>;

	newNode->info = newElement;
	newNode->link = stackTop;
	stackTop = newNode;
}

template<class Type>
Type stackType<Type>::top() const
{
   if(!isEmpty())
   {
   		return stackTop->info;
	}
	else
	{
		cout<<"\nStack is empty.\n";
	}
}

template<class Type>
void stackType<Type>::pop()
{
	assert(stackTop != NULL);
	nodeType<Type> *temp;
	temp = stackTop;
	stackTop = stackTop->link;
	delete temp;
}

template<class Type>
void stackType<Type>::copyStack(const stackType<Type> &otherStack)
{
	nodeType<Type> *current, *last, *newNode;
	if(stackTop != NULL)
		initializeStack();
	if(otherStack.stackTop == NULL)
		stackTop = NULL;
	else
	{
		current = otherStack.stackTop;

		stackTop = new nodeType<Type>;
		stackTop->info = current->info;
		stackTop->link = NULL;
		last = stackTop;
		current = current->link;
		while(current != NULL)
		{
			newNode = new nodeType<Type>;
			newNode->info = current->info;
			newNode->link = NULL;
			last->link = newNode;
			last = newNode;
			current = current->link;
		}
	}
}
template<class Type>
stackType<Type>::stackType()
{
	stackTop = NULL;
}
template<class Type>
stackType<Type>::~stackType()
{
	nodeType<Type> *temp;
	while(stackTop != NULL)
	{
		temp = stackTop;
		stackTop = stackTop->link;
		delete temp;
	}
}
template<class Type>
stackType<Type>::stackType(const stackType<Type> &otherStack)
{
	stackTop = NULL;
	copyStack(otherStack);
}

template<class Type>
bool stackType<Type>::operator==(stackType<Type> &otherStack)
{
	Type temp1, temp2;
	stackType<Type> tempStack1, tempStack2;
	tempStack1 = *this;
	tempStack2 = otherStack;
	while(!tempStack1.isEmpty() && !tempStack2.isEmpty())
	{
		if(tempStack1.top() != tempStack2.top())
			return false;
		else
		{
			temp1 = tempStack1.top();
			tempStack1.pop();
			temp2 = tempStack2.top();
			tempStack2.pop();
		}
	}
	if(tempStack1.isEmpty() && !tempStack2.isEmpty())
	{
		return false;
	}
	else if(!tempStack1.isEmpty() && tempStack2.isEmpty())
	{
		return false;
	}
	else if(tempStack1.isEmpty() && tempStack2.isEmpty())
	{
		return true;
	}
}

template<class Type>
void stackType<Type>::reverseStack(stackType<Type> &otherStack)
{
	otherStack.initializeStack();
	stackType<Type> tempStack = *this;
	Type temp;

	while(!tempStack.isEmpty())
	{
		temp = tempStack.top();
		otherStack.push(temp);
		tempStack.pop();
	}
}

