#include<iostream>
using namespace std;

template <class type>
struct nodeType
{
	type info;
	nodeType<type>* link;
};

template<class type>
class llist
{
public:
	void initializeList();
	int length();
	bool isEmpty();
	void insertLast(const type& newElement);
	void deleteElement(const type &Element);
	void displayLL();
	void insertionSort();
	//chapter 2 Q#2.1 -deletes duplicate value in a LL using an array
	void deleteDuplicate(); 
	//chapter 2 Q#2.1 -deletes duplicate value in a LL without temporary buffer
	void deleteDuplicate2();
	//chapter 2 Q#2.2 -find kth element from the last
	type findKFromLast(int k);
	//chapter 2 Q#2.3 - delete the middle value of LL 
	//given the pointer is pointing only to middle element
	void deleteMid();

	llist();
	~llist();
	llist(const llist & otherllist);
	llist<type> & operator=(const llist& otherllist);

private:
	int count;
	nodeType<type> *first,*last;
    void copyllist(const llist& otherllist);
};

template <class type>
void llist<type>::initializeList()
{
	nodeType<type> *temp;
	while(first != NULL)
	{
		temp = first;
		first = first->link;
		delete temp;
	}
	last = NULL;
	count = 0;
}

template <class type>
int llist<type>::length()
{
	return count;
}

template <class type>
bool llist<type>::isEmpty()
{
	return(first == NULL);
}

template<class type>
void llist<type>::insertLast(const type &newElement)
{
	if(first == NULL)
	{
		first = new nodeType<type>;
		first->info = newElement;
		first->link = NULL;
		last = first;
		count++;
	}	
	else{
		nodeType<type>* newNode = new nodeType<type>;
		newNode->info = newElement;
		newNode->link = NULL;
		last ->link = newNode;
		last = newNode;
		count++;
	}
}

template<class type>
void llist<type>::deleteElement(const type &Element)
{
	nodeType<type> *current,*prev;
	current = first;
	prev = NULL;
	if(first == NULL)
	{
		cout <<"Empty list"<<endl;
	}
	else 
	{
		while(current !=NULL)
		{
			if(current->info == Element)
			{
				if(last->info == Element)
				{
					last = prev;
				}
				if(prev == NULL)
				{
					first = current->link;
					delete current;
					count--;
				}
				else
				{
					prev->link = current->link;
					delete current;
					count--;
				}
			}
			prev = current;
			current = current->link;
		}
	}

}

template<class type>
llist<type>::llist()
{
	first = NULL;
	last = NULL;
	count = 0;
}

template<class type>
llist<type>::~llist()
{
	initializeList();
}

template<class type>
void llist<type>::copyllist(const llist<type> &otherllist)
{
	nodeType<type> *current;
	current = otherllist.first;
	initializeList();
	count = otherllist.count;
	first = new nodeType<type>;
	first->info = current->info;
	first->link = NULL;
	last = first;
	while (current !=NULL)
	{
		nodeType<type> *newNode = new nodeType<type>;
		newNode->info = current->info;
		newNode->link = NULL;
		last->link = newNode;
		last = newNode;
		current = current->link;
	}
}

template<class type>
llist<type>::llist(const llist<type> &otherllist)
{
	first = NULL;
	last = NULL;
	count = 0;
	copyllist(&otherllist);
}

template<class type>
llist<type> & llist<type>::operator=(const llist<type> &otherllist)
{
	if(this != otherllist)
	{
		initializeList();
		copyllist(&otherllist);
	}
	return *this;
}

template<class type>
void llist<type>::displayLL()
{
	nodeType<type> * current = first;
	while(current!= NULL)
	{
		cout << current->info<<"  ";
		current = current->link;
	}
	cout<<endl;
}

template<class type>
void llist<type>::insertionSort()
{

}
template<class type>
void llist<type>::deleteDuplicate()
{
	int arr[100] = {0};
	int index = first->info;
	nodeType<type> *current = first;
	nodeType<type> *prev = NULL;

	while (current != NULL)
	{
		index = current->info;
		if(arr[index] != 1)
		{
			arr[index] = 1;
			prev = current;
			current = current->link;	
		}
		else
		{
			prev->link = current->link;
			delete current;
			count--;
			current = prev->link;
		}
	}
}

template <class type>
void llist<type>::deleteDuplicate2()
{
	nodeType<type> *current = first;
	nodeType<type> *prevInCurr = NULL;
	nodeType<type> *InCurr = NULL;

	while(current != NULL)
	{
		prevInCurr = current;
		InCurr = current->link;
		while(InCurr != NULL)
		{
			if(current->info != InCurr->info)
			{
				prevInCurr = InCurr;
				InCurr = InCurr->link;
			}
			else
			{
				prevInCurr->link = InCurr->link;
				delete InCurr;
				count--;
				InCurr = prevInCurr->link;
			}
		}
		current = current->link;
	}
}

template<class type>
type llist<type>::findKFromLast(int k)
{
	nodeType<type> *current = first;
	nodeType<type> *prev = first;
	if(k > count)
	   return -1;
	else
	{
		while(k != 0)
		{
			current = current->link;
			k--;
		}
	}
	while(current != NULL)
	{
		current = current->link;
		prev = prev->link;
	}
	return prev->info;
}

template<class type>
void llist<type>::deleteMid()
{
	int counter = 1;
	nodeType<type> *current = first;
	nodeType<type> *next = NULL;

	while(counter != (count+1)/2)
	{
		counter++;
		current = current->link;
	}

	next = current->link;

	current->info = next->info;
	current->link = next->link;
	delete next;
	count--;
}