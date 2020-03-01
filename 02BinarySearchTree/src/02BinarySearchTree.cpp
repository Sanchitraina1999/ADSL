/*

 A Dictionary stores keywords & its meanings. Provide facility for
adding new keywords, deleting keywords, updating values of any
entry, assign a given tree into another tree (=). Provide facility to
display whole data sorted in ascending/ Descending order. Also find
how many maximum comparisons may require for finding any
keyword. Use Binary Search Tree for implementation.

*/

#include <iostream>
using namespace std;

class node
{
    int data, meaning;
    node *left, *right;

public:
    node()
    {
        left = right = NULL;
    }
    friend class bst;
};

class bst
{
    node *root;

public:
    bst();
    void mainmenu();
    void Add();
    node* Delete(node*, int);
    node* Findmax(node*);
    void Update(int);
    node* present(int);
    void Assign();
    void SortASC();
    void SORTDESC();
    int Comparisons(int);
    int findcomparisons(int);
    void inorderREC(node *);
    void RVLorderREcusive(node *);
    node* returnroot();
};

bst::bst()
{
    root = NULL;
    cout << "\nDictionary made with root as NULL";
}

void bst::mainmenu()
{
    cout << "\n1. Add keywords and its meaning";
    cout << "\n2. Delete keyword";
    cout << "\n3. Update entries";
    cout << "\n4. Assign this dictionary into another dictionary";
    cout << "\n5. Sort in ascending order";
    cout << "\n6. Sort in descending order";
    cout << "\n7. Number of comparisons for finding a keyword";
}

void bst::Add()
{
    node *toBeAdded = new node();
    cout << "\nEnter keyword and its meaning";
    cin >> toBeAdded->data >> toBeAdded->meaning;
    if (root == NULL)
    {
        root = toBeAdded;
        cout << "\nAdded as root in bst";
    }
    else
    {
        int flag = 0;
        node *current = root;
        while (flag == 0)
        {
            if (current->data == toBeAdded->data)
            {
                cout << "\nSame data exists already in the dictionary";
                flag = 1;
                return;
            }
            else if (toBeAdded->data < current->data)
            {
                if (current->left != NULL)
                    current = current->left;
                else
                {
                    current->left = toBeAdded;
                    flag = 1;
                }
            }
            else
            {
                if (current->right != NULL)
                    current = current->right;
                else
                {
                    current->right = toBeAdded;
                    flag = 1;
                }
            }
        }
        if (flag == 1)
            cout << toBeAdded->data << " inserted";
    }
}

node* bst::Delete(node* root,int key)
{
    node * temp ;
    if(root==NULL)
        cout<<"\nKeyword doesnt exist";
    else if(key < root->data)
        root->left = Delete(root->left,key);
    else if(key > root->data)
        root->right = Delete(root->right,key);
    else{   //Element found
        if(root->left && root->right){
            //replace with largest in left subtree
            temp = Findmax(root->left);
            root->data = temp->data;
            root->left = Delete(root->left,root->data);
        }
        else{
            //ONE child condition
            temp = root->left;
            if(root->left==NULL)
                root = root->right;
            if(root->right==NULL)
                root=root->left;
            delete(temp);
        }
    }
    return root;
}

node* bst::Findmax(node* root){
    if(!root)
        return NULL;
    else if(root->right==NULL)
        return root;
    else
        return (Findmax(root->right));    
}

void bst::Update(int key)
{
    if(root){
        if(present(key)){
            cout<<"Found Keyword "<< (present(key))->data <<" :>> "<< (present(key))->meaning;
            cout<<"\nYou want to change the meaning to ____? : ";
            cin>>(present(key))->meaning; 
        }
        else
            cout<<"\nKeyword "<< key <<" is not present in the dictionary";
    }
    else
        cout<<"\nDictionary empty";
}

node* bst::present(int key){
    int flag = 0;
    node* current=root;
    while(true){
        if(current->data==key){
            return current;
        }
        else if(key > current->data){
            current = current->right;
            if(current->data<key)
                return NULL;
        }
        else{
            current=current->left;
            if(current->data>key)
                return NULL;
        }
    }
}

void bst::Assign()
{
    bst t1;
    t1.SortASC();
}

void bst::SortASC()
{
    cout << "\nIncreasing order: ";
    inorderREC(root);
}

void bst::inorderREC(node *root)
{
    if (root)
    {
        inorderREC(root->left);
        cout << root->data << " :>> " << root->meaning << "\n";
        inorderREC(root->right);
    }
    return;
}

void bst::SORTDESC()
{
    if (root)
        RVLorderREcusive(root);
    else
        cout << "\nDictionary has no keywords\n";
}

void bst::RVLorderREcusive(node *root)
{
    if (root)
    {
        RVLorderREcusive(root->right);
        cout << root->data << " :>> " << root->meaning << "\n";
        RVLorderREcusive(root->left);
    }
}

int bst::Comparisons(int key)
{
    if (!root)
    {
        cout << "\nTree is empty. 0 comparisons";
    }
    else
    {
        if (root->data == key)
            return 1;
        else
            return findcomparisons(key);
    }
}

int bst::findcomparisons(int key)
{
    int level = 0, flag = 0;
    node *current = root;
    while (flag == 0)
    {
        if (current->data == key)
        {
            level++;
            flag = 1;
        }
        else if (key > current->data)
        {
            current = current->right;
            if (current->data < key)
            {
                return level;
            }
            level++;
        }
        else if (key < current->data)
        {
            current = current->left;
            if (current->data > key)
            {
                return level;
            }
            level++;
        }
    }
    return level;
}

node* bst::returnroot(){
    return root;
}
int main()
{
    bst t;
up:
    t.mainmenu();
    char continu = 'y';
    int choice, key, num;
    cout << "\nEnter choice : ";
    cin >> choice;
    switch (choice)
    {
    case 1:
        cout << "\nNumber of keywords : ";
        cin >> num;
        while (num--)
            t.Add(); //done
        break;
    case 2:
        cout<<"\nEnter keyword you want to delete : ";
        cin>>key;
        t.Delete(t.returnroot(),key);
        break;
    case 3:
        cout<<"\nEnter the keyword you want to update";
        cin>>key;
        t.Update(key); 
        break;
    case 4:
        t.Assign(); 
        break;
    case 5:
        t.SortASC(); 
        break;
    case 6:
        t.SORTDESC(); 
        break;
    case 7:
        cout << "Enter key you want to search ? ";
        cin >> key;
        cout << "\nNumber of Comparisons for finding " << key << " are: " << t.Comparisons(key) << "\n"; //done
        break;
    }
    cout << "\nDo you want to continue (y/n)";
    cin >> continu;
    if (continu == 'y')
        goto up;
    return 0;
}