#include "stackType.h"

int main()
{
	stackType<int> stack(50);
	stackType<int> copyStack(50);
	stackType<int> dummyStack(100);

	stack.initializeStack();
	stack.push(23);
	stack.push(10);
	stack.push(11);
	stack.push(31);
	copyStack = stack;
	cout<<"\nThe elements of the copyStack: ";
	while(!copyStack.isEmpty())
	{
		cout<<copyStack.top()<<" ";
		copyStack.pop();
	}
	cout<<endl;
	if(copyStack == stack)
		cout<<"\ncopystack and stack are identical.\n";
	else
		cout<<"\ncopystack and stack are not identical.\n";
	dummyStack = stack;
	//dummyStack.push(1);
	if(dummyStack == stack)
		cout<<"\ndummyStack and stack are identical.\n";
	else
		cout<<"\ndummyStack and stack are not identical.\n";
	stackType<int> revStack(10) ;
	stack.reverseStack(revStack);
	while(!revStack.isEmpty())
	{
		cout<<revStack.top()<<" ";
		revStack.pop();
	}

	stackType<int> postfixstack(50);
	int result = postfixstack.stackPostFix("#35 #27 +#3 *=");
	cout << "\nPostfix result for #35#27+#3*=is : " <<result<<endl;

        return 0;
}
