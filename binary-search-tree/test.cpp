#include "binarysearch.h"

using namespace std;

int main()
{
	binarySearchTree<int> tree;
	tree.insertElement(4);
	tree.insertElement(2);
	tree.insertElement(5);
	tree.insertElement(1);
	tree.insertElement(3);
	tree.inOrderTraversal();
	tree.postOrderTraversal();
	tree.preOrderTraversal();

	if(tree.searchItem(5))
	{
		cout<<"\nfound 5";
	}
	else
	{
		cout<<"\n not found 5";
	}
	if(tree.searchItem(12))
	{
		cout<<"\nfound 12";
	}
	else
	{
		cout<<"\nnot found 12";
	}
	cout << endl;
	tree.destroyTree();
	if(tree.searchItem(5))
	{
		cout<<"\nfound 5";
	}
	else
	{
		cout<<"\n not found 5";
	}
	tree.inOrderTraversal();

        return 0;
}
