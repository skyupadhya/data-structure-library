#include "stackType.h"

int main()
{
	stackType<int> stack;
	stackType<int> copy;
	stackType<int> reverseCopy;

	stack.push(2);
	stack.push(3);
	stack.push(7);

	copy = stack;  //assignment overloading
	stackType<int> newStack(stack);  //copy constructor
	cout<<endl<<"copy has:\n";
	while(!copy.isEmpty())
	{
		cout<<copy.top()<<" ";
		copy.pop();
	}
	cout<<endl<<"Newstack has:\n";
	while(!newStack.isEmpty())
	{
		cout<<newStack.top()<<" ";
		newStack.pop();
	}
	cout<<endl;

	copy = stack;
	copy.push(15);
	if(copy == stack)
	{
		cout<<"\nIdentical stacks.\n";
	}
	else
	{
		cout<<"\nDifferent stacks.\n";
	}
	stack.reverseStack(reverseCopy);
	cout<<endl<<"reverseStack has:\n";
	while(!reverseCopy.isEmpty())
	{
		cout<<reverseCopy.top()<<" ";
		reverseCopy.pop();
	}

}