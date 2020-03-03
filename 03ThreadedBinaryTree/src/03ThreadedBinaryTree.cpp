//============================================================================
// Name        : 03ThreadedBinaryTree.cpp
// Author      : Sanchit Raina
// Version     :
// Copyright   : https://github.com/Sanchitraina1999/ADSL/blob/master/03ThreadedBinaryTree/src/03ThreadedBinaryTree.cpp
// Description : Hello World in C++, Ansi-style
//============================================================================

/*
 Create inorder threaded binary tree and perform inorder, preorder traversal.
 */
#include<iostream>
using namespace std;

class node
{
	int data;
	int lbit, rbit;
	node *lchild, *rchild;
public:
	node()
	{
		data = 0;
		lchild = rchild = NULL;
	}
	node(int data)
	{
		this->data = data;
	}
	friend class tbst;
};
class tbst
{
	node *root;
	node *current;
	bool directionRight;
	bool directionLeft;

public:
	tbst()
	{
		root = new node(1);
		root->lbit = 0;
		root->rbit = 1;
		root->lchild = root->rchild = root;

		///////////////////////////
		bool directionRight = false;
		bool directionLeft = false;
	}
	void create(int data)
	{
		node* nod = new node(data);
		if (root->lchild == root &&root->rchild == root) //then always node attached to lchild && start building tree from this node
		{
			nod->lbit = root->lbit;
			nod->lchild = root->lchild;
			root->lchild = nod;
			root->lbit = 1;
			nod->rbit = 0;
			nod->rchild = root;

		}
		else {
			current = root->lchild;
			while (true)
			{
				if (nod->data < current->data)
				{
					if (current->lbit == 0)
					{
						directionLeft = true;
						directionRight = false;
						break;
					}
					else
						current = current->lchild;

				}
				else if (nod->data > current->data)
				{
					if (current->rbit == 0)
					{
						directionLeft = false;
						directionRight = true;
						break;
					}
					else
						current = current->rchild;
				}
				else
				{
					cout<<"\nAlready Exists. Duplicate entries not allowed";
					return;
				}

			}

			if (directionLeft)
			{
				nod->lbit = current->lbit;
				nod->lchild = current->lchild;
				current->lchild = nod;
				current->lbit = 1;
				nod->rbit = 0;
				nod->rchild = current;
			}
			else if (directionRight)
			{
				nod->rbit = current->rbit;
				nod->rchild = current->rchild;
				current->rchild = nod;
				current->rbit = 1;
				nod->lbit = 0;
				nod->lchild = current;
			}
			else
			{
				cout << "fail";
			}
		}
		cout << "node added";
	}
	void insert()
	{
		char ch='y';
		int value;
		do{
			cout<<"Enter the data";
			cin>>value;
			create(value);
			cout<<"Do you want to continue...";
			cin>>ch;

		}while(ch!='n');
	}
	node* ro()
		{
			return root;
		}
	void InOrderRecursive( node* temp)
		{
			if (temp != root) {
				if (temp->lbit != 0)
					InOrderRecursive(temp->lchild);
				cout << temp->data<<"\t";
				if (temp->rbit != 0)
					InOrderRecursive(temp->rchild);
			}

		}
	void InOrder()
	{
		current = root->lchild;
		while (current->lbit == 1)
		{
			current = current->lchild;
		}
		while (current != root)
		{
			cout << current->data << "\t";
			current = nextInOrder(current);
		}
	}

	node* nextInOrder(node* current)
	{
		if (current->rbit == 0) {
			return current->rchild; //inorder successor
		}
		current = current->rchild;
		while (current->lbit == 1)
		{
			current = current->lchild;
		}
		return current;
	}



	void preorder()
	{
		current=root->lchild;
		cout<<current->data<<"\t";
		while(current!=root)
		{

			while(current->lbit!=0)
			{
				current=current->lchild;
				cout<<current->data<<" ";
			}
			while(current->rbit==0)
				current=current->rchild;
			current=current->rchild;
			if(current!=root)
				cout<<current->data<<" ";
		}

	}
};



int main()
{
	tbst p;
	p.insert();
	cout<<"Inorder:";
	p.InOrder();
	cout<<endl<<"Preorder:";
	p.preorder();


	return 0;
}
