#include "LL.h"
using namespace std;

int main()
{
	llist<int> list1 ;
	int length = 0;
	int kVal = 0;

	list1.insertLast(10);
	list1.insertLast(11);
	list1.insertLast(5);
	list1.insertLast(1);
	list1.insertLast(11);
	list1.insertLast(5);
	list1.insertLast(88);
	list1.insertLast(66);

	length = list1.length();
	list1.displayLL();
	cout << "Total elements in list1 ="<<length<<endl;

	list1.deleteDuplicate();
	length = list1.length();
	list1.displayLL();
	cout << "Total elements in list1 ="<<length<<endl;
	kVal = list1.findKFromLast(7);
	cout <<"k val ="<< kVal<<endl;


	llist<int> list2 ;
	
	list2.insertLast(10);
	list2.insertLast(11);
	list2.insertLast(5);
	list2.insertLast(1);
	list2.insertLast(11);
	list2.insertLast(5);
	list2.insertLast(88);
	list2.insertLast(66);

	length = list2.length();
	list2.displayLL();
	cout << "Total elements in list2 ="<<length<<endl;
	kVal = list2.findKFromLast(3);
	cout <<"k val ="<< kVal<<endl;

	list2.deleteDuplicate2();
	length = list2.length();
	list2.displayLL();
	cout << "Total elements in list2 ="<<length<<endl;
	kVal = list2.findKFromLast(3);
	cout <<"k val ="<< kVal<<endl;

	list2.insertLast(9);
	list2.insertLast(6);
	list2.insertLast(61);
	length = list2.length();
	list2.displayLL();
	cout << "Total elements in list2 ="<<length<<endl;
	list2.deleteMid();
	list2.displayLL();
	length = list2.length();
	cout << "Total elements in list2 ="<<length<<endl;

        return 0;
}
