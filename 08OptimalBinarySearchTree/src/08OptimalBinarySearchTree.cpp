//============================================================================
// Name        : 08OptimalBinarySearchTree.cpp
// Author      : Sanchit Raina
// Version     :
// Copyright   : https://www.github.com/Sanchitraina1999/ADSL
// Description : Hello World in C++, Ansi-style
//============================================================================

/*

Given sequence k = k1 <k2 < ... < kn of n sorted keys, with a search
probability pi for each key ki . Build the Binary search tree that has
the least search cost given the access probability for each key.

*/

#include <iostream>
using namespace std;

float C[20][20];
int R[20][20];

class node{
	char data;
	node *lchild,*rchild;
public:
	node(){
		data='\0';
		lchild=rchild=NULL;
	}
	friend class OBST;
};

class OBST{
	node *root;
	int n;
public:
	OBST(int d){
		n=d;
		root=NULL;
	}
	void optimal(char[], float[], float[ ]);
	int find(int, int);
	node* construct(char[], int, int);
	void traversal();
	void postorder(node* );
	void preorder(node* );
	void inorder(node*);
	void mainmenu();
};

void OBST::optimal(char, float, float){

}

int main(){
	OBST t;
	int choice;
	char yn='y';
up:
	t.mainmenu();
	cin>>choice;
	switch(choice){
	case 1:

		break;
	}
	cout<<"\nDo you want to continue? (y/n) : ";
	cin>>yn;
	if(yn=='y')
		goto up;
	return 0;
}
