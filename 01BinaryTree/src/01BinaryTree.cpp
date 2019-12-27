//============================================================================
// Name        : 01BinaryTree.cpp
// Author      : Sanchit Raina
// Version     :
// Copyright   : https://github.com/Sanchitraina1999/ADSL/blob/master/01BinaryTree/src/01BinaryTree.cpp
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
#include <stack>   //STL Stack
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
	void Delete(node* );
	void copyTree(node* );
	void mirrorImage(node* );
	void equal(node* );
	void preorderRecursive(node* );
	void preorderNonRecursive(node* );
	void inorderRecursive(node* );
	void inorderNonRecursive(node* );
	void postorderRecursive(node* );
	void postorderNonRecursive(node* );
	void display(node* );
};

void Tree::create(){
	char ch1;
	root=NULL;
	do{
		node *temp= new node(); //temp is the new node to be added to the tree
		cout<<"\nEnter data : ";
		cin>>temp->data;
		if(root==NULL){
			root=temp;
			cout<<"\n"<<root->data<<" added as ROOT node of the Binary Tree";
		}
		else{
			node *temp1=root;       //temp1 is for primary root nodes at each level
			int flag=0;           //flag 0 implies new node has NOT YET been added
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

void Tree::Delete(node* root){

}

void Tree::copyTree(node* root){

}

void Tree::mirrorImage(node* root){
	if(root){
		mirrorImage(root -> left);
		mirrorImage(root -> right);
		swap(root -> left, root -> right);
	}
}

void Tree::equal(node* root2){

}

void Tree::preorderRecursive(node* root){
	if (root)
	{
		cout << root->data << " ";
		preorderRecursive(root->left);
		preorderRecursive(root->right);
	}
}

void Tree::preorderNonRecursive(node* root){
	stack <node*> s;

	node* temp=root;
	int flag=0;

	while(flag==0){
		if(temp != NULL){
			cout<< temp -> data<<" ";
			s.push(temp);
			temp = temp -> left;
		}
		else if(!s.empty()){
			temp = s.top();
			s.pop();
			temp = temp -> right;
		}
		else
			flag=1;
	}

}

void Tree::inorderRecursive(node* root){
	if(root){
		inorderRecursive(root->left);
		cout<<root->data<<" ";
		inorderRecursive(root->right);
	}
}

void Tree::inorderNonRecursive(node* root){
	stack <node*> s;

	node* temp=root;
	int flag=0;

	while(flag==0){
		if(temp != NULL){
			s.push(temp);
			temp = temp -> left;
		}
		else if(!s.empty()){
			temp = s.top();
			s.pop();
			cout<< temp -> data<<" ";
			temp = temp -> right;
		}
		else
			flag=1;
	}

}

void Tree::postorderRecursive(node* root){
	if (root)
	{
		postorderRecursive(root->left);
		postorderRecursive(root->right);
		cout << root->data << " ";
	}
}

void Tree::postorderNonRecursive(node* root){
	stack <node*> s1,s2;
	s1.push(root);  			//s1 will always contain 1 element ..the node whose left and right nodes are to be chechked
	while(!s1.empty()){
		node* temp;
		temp=s1.top();
		s1.pop();           //s1 becomes empty
		s2.push(temp);

		if(temp->left!=NULL){
			s1.push(temp->left);
		}
		if(temp->right!=NULL)
			s1.push(temp->right);
											// if both of temp's left and temp's right are NULL, s1 remains empty
	}
	while(!s2.empty()){
		node* temp=s2.top();
		cout<<temp->data<<" ";
		s2.pop();
	}
}

void Tree::display(node* root){

	if(root==NULL){
		cout<<"\nTree is empty";
	}
	else{
		cout<<"\nRoot node is : "<<root->data;
		int l=0,in=-1;                // Stack is already having root..will be considered as interior node
		stack<node*> s;
		stack<int> Leaf,Interior;
		node *temp;
		s.push(root);
		if(root->left!=NULL || root->right!=NULL){
			while(!s.empty()){
				temp=s.top();
				s.pop();
				if(temp->left==NULL && temp->right==NULL){
					l++;
					Leaf.push(temp->data);
				}
				else{
					in++;
					Interior.push(temp->data);
				}
				if(temp->right!=NULL)
					s.push(temp->right);
				if(temp->left!=NULL)
					s.push(temp->left);
			}

			cout<<"\nTotal leaf nodes: "<<l<<" are:"<<endl;
			while(!Leaf.empty()){
				cout<<Leaf.top()<<" ";
				Leaf.pop();
			}
			cout<<"\nTotal internal nodes: "<<in<<" are:"<<endl;
			while(!Interior.empty()){
					cout<<Interior.top()<<" ";
					Interior.pop();
				}
		}
		else
			cout<<"\nOnly root: "<<root->data<<" is present";
	}

}

int main() {
	Tree t,t1,t2;
	cout<<"\n Enter a binary tree (Given)";        //done
	t.create();
start:
	cout<<"\nMAIN MENU";
	cout<<"\n1. Re-Enter binary tree ";        //done
	cout<<"\n2. Delete all nodes of the tree";
	cout<<"\n3. Assign this tree to another tree";
	cout<<"\n4. Create a mirror image of the tree";   //done
	cout<<"\n5. Check two binary trees are equal or not";
	cout<<"\n6. Tree Traversals";            //done
	cout<<"\n7. Print internal and leaf nodes";  //done
	cout<<"\n Enter your choice";
	int choice; 	cin>>choice;
	switch(choice){
	case 1:
		t.create();
		break;
	case 2:
		t.Delete(t.root);
		break;
	case 3:
		t.copyTree(t.root);
		break;
	case 4:
		t.mirrorImage(t.root);
		cout<<"\nTree has been mirrored";
		break;
	case 5:
		cout<<"\nANOTHER binary tree you want to check with given Binary tree";
		t2.create();
		t.equal(t2.root);
		break;
	case 6:
		cout<<"\n\tTREE TRAVERSALS";
		cout<<"\n\t1. Preorder Recursive";
		cout<<"\n\t2. Preorder Non-Recursive";
		cout<<"\n\t3. Inorder Recursive";
		cout<<"\n\t4. Inorder Non-Recursive";
		cout<<"\n\t5. Postorder Recursive";
		cout<<"\n\t6. Postorder Non-Recursive";
		cout<<"\n Enter your choice";
		int choice1;	cin>>choice1;
		switch(choice1){
			case 1:
				cout << "\nPreorder Traversal is : \n";
				t.preorderRecursive(t.root);
				break;
			case 2:
				cout << "\nPreorder Traversal is : \n";
				t.preorderNonRecursive(t.root);
				break;
			case 3:
				cout << "\nInorder Traversal is : \n";
				t.inorderRecursive(t.root);
				break;
			case 4:
				cout << "\nInorder Traversal is : \n";
				t.inorderNonRecursive(t.root);
				break;
			case 5:
				cout << "\nPostorder Traversal is : \n";
				t.postorderRecursive(t.root);
				break;
			case 6:
				cout << "\nPostorder Traversal is : \n";
				t.postorderNonRecursive(t.root);
				break;
			default:
				cout<<"\nNo such option for traversal !";
		}
		break;
	case 7:
		t.display(t.root);
		break;
	default:
		cout<<"\nNo such option in Main Menu !";
	}
	cout<<endl;
	goto start;
	return 0;
}
