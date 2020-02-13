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
#include <queue>
#define COUNT 5
using namespace std;

class node{
    int data;
    node *left,*right;
public:
    node(){
        data=0;
        left=NULL;
        right=NULL;
    }
    friend class Tree;
};

class Tree{
    node *root;
public:
    Tree(){
        root=NULL;
    }
    void create();
    void callDelete();
    node* Delete(node*);
    void callcopyTree(Tree);
    void copyTree(Tree);
    void callmirrorImage();
    void mirrorImage(node*);
    void callequal(Tree);
    void equal(node* );
    bool compare(node*, node*);
    void callpreorderRecursive();
    void preorderRecursive(node* );
    void callpreorderNonRecursive();
    void preorderNonRecursive(node* );
    void callinorderRecursive();
    void inorderRecursive(node* );
    void callinorderNonRecursive();
    void inorderNonRecursive(node* );
    void callpostorderRecursive();
    void postorderRecursive(node* );
    void callpostorderNonRecursive();
    void postorderNonRecursive(node* );
    void calldisplay();
    void display(node* );
    friend class node;
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

void Tree::callDelete(){
    if(root==NULL)
        {
            cout<<"The Tree is empty."<<endl;
            return;
        }
    root=Delete(root);
}

node* Tree::Delete(node* temp){
    if(temp->left==NULL&&temp->right==NULL)
        {
            //cout<<temp->data<<" has been deleted\n";
            delete temp;
            return NULL;
        }
        if(temp->left!=NULL)
            temp->left=Delete(temp->left);
        if(temp->right!=NULL)
            temp->right=Delete(temp->right);
        //cout<<temp->data<<" has been deleted\n";
        delete temp;
    return NULL;
}
void Tree::callcopyTree(Tree t){
    if(root)
        copyTree(t);
    else{
        cout<<"Tree is already empty\n";
    }
}

void Tree::copyTree(Tree t){
    Tree t3;          //another object of Tree class created
    t3=t;
    cout<<"\nAssigned Tree t to Tree t3";
    t3.calldisplay();
}

void Tree::callmirrorImage(){
    if(root)
        mirrorImage(root);
}

void Tree::mirrorImage(node* root){
    if(root){
        mirrorImage(root -> left);
        mirrorImage(root -> right);
        swap(root -> left, root -> right);
    }
}

void Tree::callequal(Tree temptree){
    if(temptree.root!=NULL && root!=NULL)
        equal(temptree.root);
    else
        cout<<"One of the tree is empty\n";
}

void Tree::equal(node* root){
    if (compare(this->root,root))
            cout<<"\nTrees are equal";
    else
        cout<<"\nTrees are NOT equal";
}

bool Tree::compare(node* root1,node* root2){
    if(root1==NULL&&root2==NULL)
        return true;
    else if(root1==NULL&&root2!=NULL)
        return false;
    else if(root1!=NULL&&root2==NULL)
        return false;
    else{
        if(root1->data==root2->data&&compare(root1->left,root2->left)&&compare(root1->right,root2->right))
            return true;
        else
            return false;
    }
}
void Tree::callpreorderRecursive(){
    if(root){
        cout << "\nPreorder Traversal is : \n";
        preorderRecursive(root);
    }
    else
        cout<<"Tree is empty\n";
}
void Tree::preorderRecursive(node* root){
    if (root)
    {
        cout << root->data << " ";
        preorderRecursive(root->left);
        preorderRecursive(root->right);
    }
}
void Tree::callpreorderNonRecursive(){
    if(root){
        cout << "\nPreorder Traversal is : \n";
        preorderNonRecursive(root);
    }
    else
        cout<<"Tree is empty\n";
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

void Tree::callinorderRecursive(){
    if(root){
        cout << "\nInorder Traversal is : \n";
        inorderRecursive(root);
    }
    else
        cout<<"Tree is empty\n";
}

void Tree::inorderRecursive(node* root){
    if(root){
        inorderRecursive(root->left);
        cout<<root->data<<" ";
        inorderRecursive(root->right);
    }
}

void Tree::callinorderNonRecursive(){
    if(root){
        cout << "\nInorder Traversal is : \n";
        inorderNonRecursive(root);
    }
    else
        cout<<"Tree is empty\n";
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

void Tree::callpostorderRecursive(){
    if(root){
        cout << "\nPostorder Traversal is : \n";
        postorderRecursive(root);
    }
    else
        cout<<"Tree is empty\n";
}

void Tree::postorderRecursive(node* root){
    if (root)
    {
        postorderRecursive(root->left);
        postorderRecursive(root->right);
        cout << root->data << " ";
    }
}

void Tree::callpostorderNonRecursive(){
    if(root){
        cout << "\nPostorder Traversal is : \n";
        postorderNonRecursive(root);
    }
    else
        cout<<"Tree is empty\n";
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

void Tree::calldisplay(){
    if(root){
        display(root);
    }
    else{
        cout<<"Tree is empty\n";
    }
}

void Tree::display(node* root){

    if(root==NULL){
        cout<<"\nTree is empty";
    }
    else{
        cout<<"\n\nRoot node is : "<<root->data;
        int l=0,in=-1;                // Stack is already having root..will be considered as interior node
        stack<node*> s;
        queue<int> Leaf,Interior;
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

            cout<<"\n\nTotal leaf nodes: "<<l<<" are:"<<endl;
            while(!Leaf.empty()){
                cout<<Leaf.front()<<" ";
                Leaf.pop();
            }
            Interior.pop();
            cout<<"\n\nTotal internal nodes: "<<in<<" are:"<<endl;
            while(!Interior.empty()){
                    cout<<Interior.front()<<" ";
                    Interior.pop();
                }
        }
        else
            cout<<"\nOnly root: "<<root->data<<" is present";
    }

}

int main() {
    Tree t,t1,t2;
    cout<<"\n Enter a binary tree (Given)";
    t.create();
start:
    cout<<"\nMAIN MENU";
    cout<<"\n1. Re-Enter binary tree ";
    cout<<"\n2. Delete all nodes of the tree";
    cout<<"\n3. Assign this tree to another tree";
    cout<<"\n4. Create a mirror image of the tree";
    cout<<"\n5. Check two binary trees are equal or not";
    cout<<"\n6. Tree Traversals";
    cout<<"\n7. Print internal and leaf nodes";
    cout<<"\n Enter your choice";
    int choice; 	cin>>choice;
    char yesno='n';
    switch(choice){
    case 1:
        t.create();
        break;
    case 2:
        t.callDelete();
        cout<<"Do you want to call display?(y/n): ";
        cin>>yesno;
        if(yesno!='n')
            t.calldisplay();
        break;
    case 3:
        t.callcopyTree(t);
        break;
    case 4:
        t.callmirrorImage();
        cout<<"\nTree has been mirrored";
        break;
    case 5:
        cout<<"\nANOTHER binary tree you want to check with given Binary tree";
        t2.create();
        t2.callequal(t);
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
                t.callpreorderRecursive();
                break;
            case 2:
                t.callpreorderNonRecursive();
                break;
            case 3:;
                t.callinorderRecursive();
                break;
            case 4:
                t.callinorderNonRecursive();
                break;
            case 5:
                t.callpostorderRecursive();
                break;
            case 6:
                t.callpostorderNonRecursive();
                break;
            default:

                cout<<"\nNo such option for traversal !";

        }
        break;
    case 7:
        t.calldisplay();
        break;
    default:
        cout<<"\nNo such option in Main Menu !";
    }
    cout<<endl;
    goto start;
    return 0;
}
//Working