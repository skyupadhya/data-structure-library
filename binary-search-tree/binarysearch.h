#include<iostream>
using namespace std;

template <class elemType>
struct binaryNode
{
	elemType info;
	binaryNode<elemType> *left;
	binaryNode<elemType> *right;
};

template <class elemType>
class binarySearchTree
{
public:

	bool isEmpty() const;
	void inOrderTraversal() const;
	void postOrderTraversal() const;
	void preOrderTraversal() const;

	int treeHeight() const;
	int treeNodes() const;
	int treeLeaves() const;
	void destroyTree();
	void insertElement(const elemType &item);
	bool searchItem(const elemType &item);
	binarySearchTree();
	~binarySearchTree();
	binarySearchTree(const binarySearchTree<elemType> &otherTree);
	const binarySearchTree<elemType>& operator=(const binarySearchTree<elemType> &);

protected:
	binaryNode<elemType> *root;

private:
	void copyTree(const binarySearchTree<elemType> &otherTree);
	void inOrder(binaryNode<elemType> *p) const;
	void postOrder(binaryNode<elemType> *p) const;
	void preOrder(binaryNode<elemType> *p) const;
	int height(binaryNode<elemType> *p) const;
	int max(int x,int y) const;
	int treeNodesCount(binaryNode<elemType> *p) const;
	int treeLeavesCount(binaryNode<elemType> *p) const;
	void destroy(binaryNode<elemType>* &p);
	binaryNode<elemType>* insert(const elemType &item,binaryNode<elemType> *p);
	bool search(const elemType &item, binaryNode<elemType> *p);
};

template<class elemType>
bool binarySearchTree<elemType>::isEmpty() const
{
	return(root == NULL);
}

template<class elemType>
void binarySearchTree<elemType>::inOrderTraversal() const
{
	cout<<"\ninorder:";
	inOrder(root);
	cout<<endl;
}

template<class elemType>
void binarySearchTree<elemType>::postOrderTraversal() const
{
	cout<<"\npostorder:";
	postOrder(root);
	cout<<endl;
}

template<class elemType>
void binarySearchTree<elemType>::preOrderTraversal() const
{
	cout<<"\npreorder:";
	preOrder(root);
	cout<<endl;

}

template<class elemType>
int binarySearchTree<elemType>::treeHeight() const
{
	return height(root);
}

template<class elemType>
int binarySearchTree<elemType>::treeNodes() const
{
	return treeNodesCount(root);
}

template<class elemType>
int binarySearchTree<elemType>::treeLeaves() const
{
	return treeLeavesCount(root);
}

template<class elemType>
void binarySearchTree<elemType>::destroyTree() 
{
    destroy(root);
}

template<class elemType>
binarySearchTree<elemType>::binarySearchTree() 
{
	root = NULL;
}

template<class elemType>
binarySearchTree<elemType>::~binarySearchTree() 
{
	destroy(root);
}

template<class elemType>
binarySearchTree<elemType>::binarySearchTree(const binarySearchTree<elemType> &otherTree)
{
	copyTree(otherTree);
}

template<class elemType>
const binarySearchTree<elemType>& binarySearchTree<elemType>::operator=(const binarySearchTree<elemType> &otherTree)
{
	if(this != otherTree)
	{
		if(root != NULL)
			destroy(root);
		if(otherTree.root == NULL)
			root = NULL;
		else
			copyTree(otherTree);
	}	
}

template<class elemType>
void binarySearchTree<elemType>::inOrder(binaryNode<elemType> *p) const
{

	if( p!= NULL)
	{
		inOrder(p->left);
		cout << p->info <<" ";
		inOrder(p->right);
	}
}

template<class elemType>
void binarySearchTree<elemType>::postOrder(binaryNode<elemType> *p) const
{
	if( p!= NULL)
	{
		postOrder(p->left);
		postOrder(p->right);
		cout << p->info <<" ";
	}
}

template<class elemType>
void binarySearchTree<elemType>::preOrder(binaryNode<elemType> *p) const
{
	if( p!= NULL)
	{
		cout << p->info <<" ";
		preOrder(p->left);
		preOrder(p->right);
	}
}

template<class elemType>
int binarySearchTree<elemType>::height(binaryNode<elemType> *p) const
{
	if(p == NULL)
		return 0;
	else
		return 1 + max(height(p->left) , height(p->right));
	
}

template<class elemType>
int binarySearchTree<elemType>::max(int x,int y) const
{
	if(x >= y)
		return x;
	else
		return y;
}

template<class elemType>
int binarySearchTree<elemType>::treeNodesCount(binaryNode<elemType> *p) const
{
	if(p == NULL)
		return 0;
	else
		return 1 + treeNodes(p->left) + treeNodes(p->right);
}

template<class elemType>
int binarySearchTree<elemType>::treeLeavesCount(binaryNode<elemType> *p) const
{
	if(p == NULL)
		return 0;
	else if(p->left == NULL && p->right == NULL)
		return 1;
	else
		return treeLeavesCount(p->left) + treeLeavesCount(p->right);
		
}

template<class elemType>
void binarySearchTree<elemType>::destroy(binaryNode<elemType>* &p)
{
	if(p != NULL)
	{
		destroy(p->left);
		destroy(p->right);
		delete p;
		p = NULL;
	}
}

template<class elemType>
binaryNode<elemType>*  binarySearchTree<elemType>::insert(const elemType &item, binaryNode<elemType> *p)
{

	if(p == NULL)
	{
		binaryNode<elemType>* newNode = new binaryNode<elemType>;
		newNode->info = item;
		newNode->left = NULL;
		newNode->right = NULL;
		return newNode;
	}
	else
	{
		if(item < p->info)
		{
			p->left =insert(item,p->left);
		}
		else
		{
			p->right = insert(item,p->right);
		}
		return p;
	}
}

template<class elemType>
void binarySearchTree<elemType>::insertElement(const elemType &item)
{
	root = insert(item,root);
}

template<class elemType>
bool binarySearchTree<elemType>::searchItem(const elemType &item) 
{
	return search(item, root);
}

template<class elemType>
bool binarySearchTree<elemType>::search(const elemType &item,binaryNode<elemType> *p)
{
	if(p == NULL)
		return false;
	else if(p->info == item)
		return true;
	else if(item < p->info)
	{
		return search(item,p->left);
	}
	else
	{
		return search(item,p->right);
	}
}