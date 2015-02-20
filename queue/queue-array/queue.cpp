#include "queueType.h"

int main()
{
	queueType<int> queue;
	queueType<int> assign;
	queueType<int> queueTochkisFull(2);

	queue.add(1);
	queue.add(2);
	queue.add(3);

	assign = queue;
	queueType<int> copy(queue);

	cout<<"1st element of queue:"<<queue.front()<<endl;
	cout<<"Last element of queue:"<<queue.back()<<endl;
	cout<<"1st element of queue assign:"<<assign.front()<<endl;
	cout<<"Last element of queue assign:"<<assign.back()<<endl;
	cout<<"1st element of queue copy:"<<copy.front()<<endl;
	cout<<"Last element of queue copy:"<<copy.back()<<endl;
	cout<<endl;

	while(!queue.isEmpty())
	{
		cout<<queue.front() <<" ";
		queue.deleteQueue();

	}
	cout<<endl<<"Size of queue is:"<<queue.sizeQueue()<<endl;
	cout<<endl<<"Size of queue assign is:"<<assign.sizeQueue()<<endl;
	cout<<endl<<"Size of queue copy is:"<<copy.sizeQueue()<<endl;

	queueTochkisFull.add(1);
	queueTochkisFull.add(2);
	queueTochkisFull.add(3);
	queueTochkisFull.add(5);

	copy.add(4);
	copy.add(5);
	cout<<"\nMoving the 3rd element in the copy queue to front.\n";
	copy.moveNthFront(4);
	copy.display();

        return 0;
}
