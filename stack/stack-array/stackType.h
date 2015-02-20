#include<iostream>
#include<cassert>
#include<cstdlib>
#include<string>
using namespace std;

template <class Type>
class stackType
{
public:
	void initializeStack();
	bool isEmpty() const;
	bool isFull() const;
	Type top() const;
	void push(const Type& newItem);
	void pop();
	stackType(int size);
	stackType(const stackType<Type>&);
	const stackType<Type>& operator=(const stackType<Type> &otherStack);
	bool operator==(const stackType<Type> &otherStack);
	void reverseStack(stackType<Type> &otherStack);
	~stackType();

	Type stackPostFix(string str);

private:
	int maxStackSize;
	int count;
	int stackTop;
	Type* list;
};

template <class Type>
void stackType<Type>::initializeStack()
{
	//maxStackSize = 0;
	stackTop = 0;
} 

template <class Type>
bool stackType<Type>::isEmpty() const
{
	return (stackTop == 0);
}

template <class Type>
bool stackType<Type>::isFull() const
{
	return (stackTop == maxStackSize);
}

template <class Type>
Type stackType<Type>::top() const
{
	assert(!isEmpty());
	return list[stackTop-1];
}

template <class Type>
void stackType<Type>::push(const Type& newItem)
{
	if(!isFull())
	{
		list[stackTop] = newItem;
		stackTop++;
	}
	else
	{
		cout<<"\nList is full.\n";
	}
}

template <class Type>
void stackType<Type>::pop()
{
	if(!isEmpty())
		stackTop--;
	else
		cout<<"\nEmpty stack.\n";
}

template <class Type>
stackType<Type>::stackType(int size)
{
	if(size<= 0)
	{
		cout<<"\nCreating an array of 100 size.\n";
		maxStackSize = 100;
	}
	else
		maxStackSize = size;

	stackTop = 0;
	list = new Type[maxStackSize];
}

template <class Type>
stackType<Type>::stackType(const stackType<Type> &otherStack)
{
	stackTop = otherStack.stackTop;
	maxStackSize = otherStack.maxStackSize;
	list = new Type[maxStackSize];

	for(int j = 0; j < stackTop; j++)
		list[j] = otherStack.list[j];
}
template <class Type>
const stackType<Type>& stackType<Type>::operator=(const stackType<Type> &otherStack)
{
	if(this != &otherStack)
	{
		stackTop = otherStack.stackTop;
	maxStackSize = otherStack.maxStackSize;
	list = new Type[maxStackSize];

	for(int j = 0; j < stackTop; j++)
		list[j] = otherStack.list[j];		
	}

	return *this;
}

template <class Type>
stackType<Type>::~stackType()
{
	delete [] list;
}

template<class Type>
bool stackType<Type>::operator==(const stackType<Type> &otherStack)
{
	if(stackTop == otherStack.stackTop)
	{
		for(int i = stackTop - 1; i >=0 ; i--)
		{
			if(list[i] != otherStack.list[i])
				return false;
		}
		return true;
	}
	else 
		return false;
}

template<class Type>
void stackType<Type>::reverseStack(stackType<Type> &otherStack)
{
	otherStack.initializeStack();
	otherStack.maxStackSize = maxStackSize;
	otherStack.stackTop = stackTop;
	for(int i= 0 ; i < stackTop ;i++)
		otherStack.list[i] = list[stackTop-1-i];
}

template<class Type>
Type stackType<Type>::stackPostFix(string str)
{
	int i = 0;
	initializeStack();
	while(str[i] != '=')
	{
		if(str[i] == '#')
		{
			string tempStr = "";
			i++;
			while(str[i] != ' ')
			{		
				tempStr += str[i];
				i++;
			}
			int val = stoi(tempStr);
			cout<<"\nnumber to be pushed :"<<val<<endl;
			push(val);
		}
		else if(str[i] == '+' || str[i] == '-' ||
			    str[i] == '*' || str[i] == '/')
		{
			Type temp1,temp2;
			temp1 = top();
			pop();
			temp2 = top();
			pop();
			if(isEmpty())
			{
				if(str[i] == '+')
				 push(temp1 + temp2);
				else if(str[i] == '-')
					push(temp1 - temp2);
				else if(str[i] == '*')
					push(temp1 * temp2);
				else 
					push(temp1 / temp2);
			}
			else
			{
				return -1;
			}
		}
		else 
			return -1;
		i++;
	}
	if(str[i] == '=')
	{
		Type val = top();
		pop();
		return val;
	}
}