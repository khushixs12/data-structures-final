//BINARY SEARCH TREE (CREATION, INSERTION AND TRAVERSAL)
#include<iostream>
#include<conio.h>
using namespace std;
class node
{
public:
    node *left;
    int data;
    node *right;

    node()
    {
        left=NULL;
        right=NULL;
    }
};

class binary_search_tree
{
public:
    node *tree, *ptr, *parentptr, *nodeptr;

    binary_search_tree()
    {
        tree=NULL;
    }

    void insertElement(int val)
    {
        ptr=new node();
        ptr->data=val;
        ptr->left=NULL;
        ptr->right=NULL;
        if(tree==NULL)
        {
            tree=ptr;
            tree->left=NULL;
            tree->right=NULL;
        }
        else
        {
            parentptr=NULL;
            nodeptr=tree;
            while(nodeptr!=NULL)
            {
                parentptr=nodeptr;
                if(val < nodeptr->data)
                    nodeptr=nodeptr->left;
                else
                    nodeptr=nodeptr->right;
            }
            if(val < parentptr->data)
                parentptr->left=ptr;
            else
                parentptr->right=ptr;
        }
    }

    void preorderTraversal(node *tree)
    {
        if(tree!=NULL)
        {
            cout << tree->data << " ";
            preorderTraversal(tree->left);
            preorderTraversal(tree->right);
        }
    }

    void inorderTraversal(node *tree)
    {
        if(tree!=NULL)
        {
            inorderTraversal(tree->left);
            cout << tree->data << " ";
            inorderTraversal(tree->right);
        }
    }

    void postorderTraversal(node *tree)
    {
        if(tree!=NULL)
        {
            postorderTraversal(tree->left);
            postorderTraversal(tree->right);
            cout << tree->data << " ";
        }
    }
};

int main()
{
    binary_search_tree bst;
    node *tree;
    int option, val;
    cout << "1: Insert Element" << endl;
    cout << "2: Pre-order Traversal" << endl;
    cout << "3: In-order Traversal" << endl;
    cout << "4: Post-order Traversal" << endl;
    do
    {
        cout << "Enter your option: ";
        cin >> option;
        switch(option)
        {
        case 1:
            cout << "Enter the value of the new node: ";
            cin >> val;
            bst.insertElement(val);
            break;
        case 2:
            cout << "The elements of the tree are: ";
            bst.preorderTraversal(bst.tree);
            cout << endl;
            break;
        case 3:
            cout << "The elements of the tree are: ";
            bst.inorderTraversal(bst.tree);
            cout << endl;
            break;
        case 4:
            cout << "The elements of the tree are: ";
            bst.postorderTraversal(bst.tree);
            cout << endl;
            break;
        }
    }
    while(option!=5);
    getch();
    return 0;
}
