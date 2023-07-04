#include <iostream>
using namespace std;

// Run successfully !

// Expression Tree (In Order, Pre Order, Post Order traversal)
// ____________________________________________________________

struct node // structure to make Node
{
    char data;
    struct node *lc, *rc;
};

struct node *etroot(char data) // structure to make root node
{
    struct node *temp = new node;
    temp->data = data;
    temp->lc = temp->rc = NULL;
    return temp;
};

// function for in order traversal
void inorder(struct node *root) // left-node-right
{
    if (root->lc != NULL)
    {
        inorder(root->lc);
    }
    cout << root->data;
    if (root->rc != NULL)
    {
        inorder(root->rc);
    }
}

// function for pre order traversal
void preorder(struct node *root) // node-left-right
{
    cout << root->data;
    if (root->lc != NULL)
    {
        preorder(root->lc);
    }
    if (root->rc != NULL)
    {
        preorder(root->rc);
    }
}

// function for post order traversing
void postorder(struct node *root) // left-right-node
{
    if (root->lc != NULL)
    {
        postorder(root->lc);
    }
    if (root->rc != NULL)
    {
        postorder(root->rc);
    }
    cout << root->data;
}

int main()
{
    // (a+b)*(c-d)--> Expression Tree
    // total nodes = 7
    struct node *root = etroot('*');
    root->lc = etroot('+');
    root->rc = etroot('-');
    root->lc->lc = etroot('a');
    root->lc->rc = etroot('b');
    root->rc->lc = etroot('c');
    root->rc->rc = etroot('d');

    cout << "\nInorder traversal of expression tree is :\n";
    cout << "==========================================\n";
    inorder(root);

     cout << "\nPreorder traversal of binary tree is \n";
    cout << "==========================================\n";
    preorder(root);

     cout << "\nPostorder traversal of binary tree is \n";
    cout << "==========================================\n";
    postorder(root);

    return 0;
}