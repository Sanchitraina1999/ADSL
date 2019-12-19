//============================================================================
// Name        : 01BinaryTree.cpp
// Author      : Sanchit Raina
// Version     :
// Copyright   : https://www.github.com/Sanchitraina1999/ADSL
// Description : Hello World in C++, Ansi-style
//============================================================================

/*
 Given binary tree with n nodes and perform following operations on
it.
a) Assign this tree to another [operator=]
b) Erase all nodes in a binary tree
c) Create a mirror image of the tree
d) Check two binary trees are equal or not
e) Inorder, Preorder, Postorder traversal of tree(recursive and
non-recursive)
f) Print internal and leaf nodes
 */


#include <iostream>
using namespace std;

class node{
public:
	int data;
	node *left,*right;
	node(){
		data=0;
		left=NULL;
		right=NULL;
	}
};

class Tree{
public:
	node *root;
	Tree(){
		root=NULL;
	}
	void create();
	void copyTree(Tree &);
	void mirrorImage();
	void equal(Tree &);
	void preorderRecursive();
	void preorderNonRecursive();
	void inorderRecursive(node *);
	void inorderNonRecursive();
	void postorderRecursive();
	void postorderNonRecursive();
	void display();
};

void Tree::create(){
	char ch1;
	root=NULL;
	do{
		node *temp= new node(); //temp is the new node to be added
		cout<<"\nEnter data : ";
		cin>>temp->data;
		if(root==NULL){
			root=temp;
			cout<<"\n"<<root->data<<" added as ROOT node of the Binary Tree";
		}
		else{
			node *temp1=root;       //temp1 is for primary root nodes at each level
			int flag=0;           //flag 0 implies new node has NOT been added YET
			while(flag==0){
			cout<<"\nDo you place "<< temp->data <<" left or right of "<< temp1->data<<" (l/r) : ";
			char ch;	cin>>ch;
			if(ch=='l'){
				if(temp1->left==NULL){
					temp1->left=temp;
					flag=1;
					cout<<"\n"<<temp->data<<" added to the left of "<<temp1->data;
				}
				else{
					temp1=temp1->left;
				}
			}
			else{
				if(temp1->right==NULL){
					temp1->right=temp;
					flag=1;
					cout<<"\n"<<temp->data<<" added to the right of "<<temp1->data;
				}
				else{
					temp1=temp1->right;
				}
			}
			}
		}
		cout<<"\nDo you want to add more nodes to the tree: (y/n)";
		cin>>ch1;
	}while(ch1=='y'||ch1=='Y');

}

void Tree::copyTree(Tree &t){

}

void Tree::mirrorImage(){

}

void Tree::equal(Tree &t){

}
void Tree::preorderRecursive(){

}

void Tree::preorderNonRecursive(){

}

void Tree::inorderRecursive(node *temp){
	if(temp){
		inorderRecursive(root->left);
		cout<<temp->data<<" ";
		inorderRecursive(root->right);
	}
}

void Tree::inorderNonRecursive(){

}

void Tree::postorderRecursive(){

}

void Tree::postorderNonRecursive(){

}

void Tree::display(){

}

int main() {
	Tree t,t1,t2;
start:
	cout<<"\nMAIN MENU";
	cout<<"\n1. Enter a binary tree (Given)";
	cout<<"\n2. Assign this tree to another tree";
	cout<<"\n3. Create a mirror image of the tree";
	cout<<"\n4. Check two binary trees are equal or not";
	cout<<"\n5. Tree Traversals";
	cout<<"\n6. Print internal and leaf nodes";
	cout<<"\n Enter your choice";
	int choice; 	cin>>choice;
	switch(choice){
	case 1:
		t.create();
		break;
	case 2:
		t.copyTree(t1);
		break;
	case 3:
		t.mirrorImage();
		break;
	case 4:
		cout<<"\nANOTHER binary tree you want to check with given Binary tree";
		t2.create();
		t.equal(t2);
		break;
	case 5:
		cout<<"\n\t\tTREE TRAVERSALS";
		cout<<"\n\t\t1. Preorder Recursive";
		cout<<"\n\t\t2. Preorder Non-Recursive";
		cout<<"\n\t\t3. Inorder Recursive";
		cout<<"\n\t\t4. Inorder Non-Recursive";
		cout<<"\n\t\t5. Postorder Recursive";
		cout<<"\n\t\t6. Postorder Non-Recursive";
		cout<<"\n Enter your choice";
		int choice1;	cin>>choice1;
		switch(choice1){
			case 1:
				t.preorderRecursive();
				break;
			case 2:
				t.preorderNonRecursive();
				break;
			case 3:
				cout<<"\nInoder Traversal is : \n";
				t.inorderRecursive(t.root);
				break;
			case 4:
				t.inorderNonRecursive();
				break;
			case 5:
				t.postorderRecursive();
				break;
			case 6:
				t.postorderNonRecursive();
				break;
			default:
				cout<<"\nNo such option for traversal !";
		}
		break;
	case 6:
		t.display();
		break;
	default:
		cout<<"\nNo such option in Main Menu !";
	}
	goto start;
	return 0;
}
