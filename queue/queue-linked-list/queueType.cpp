#include "queueType.h"

int main()
{
	queueType<int> queue;
	queueType<int> assign;

	queue.add(1);
	queue.add(2);
	queue.add(3);

	assign = queue;
	queueType<int> copy(queue);

	cout<<"1st element of queue:"<<queue.front()<<endl;
	cout<<"Last element of queue:"<<queue.back()<<endl;
	cout<<"NO of elements in queue :" << queue.queueCount() <<endl;
	cout<<"1st element of queue assign:"<<assign.front()<<endl;
	cout<<"Last element of queue assign:"<<assign.back()<<endl;
	cout<<"NO of elements in assign queue :" << assign.queueCount() <<endl;
	cout<<"1st element of queue copy:"<<copy.front()<<endl;
	cout<<"Last element of queue copy:"<<copy.back()<<endl;
	cout<<"NO of elements in copy queue :" << copy.queueCount() <<endl;
	cout<<endl;
	
	while(!queue.isEmpty())
	{
		cout<<queue.front() <<" ";
		queue.deleteElement();

	}
	cout<<"NO of elements in queue :" << queue.queueCount() <<endl;

        return 0;
}
