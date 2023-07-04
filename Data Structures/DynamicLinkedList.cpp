#include <iostream>
using namespace std;

// Run Successfully !

// Dynamic Linked List
// ____________________

class Node
{
public:
    int data;   // data of list
    Node *next; // pointer to point a next node
    Node(int x)
    {
        data = x;
        next = NULL;
    }
};

class LinkedList
{
public:
    Node *head;
    // function to add node at front
    void addAtFront(Node *n)
    {
        n->next = head;
        head = n;
    }
    // function to check whether the list is empty or not.
    bool isEmpty()
    {
        if (head == NULL)
        {
            return 1;
        }
        else
        {
            return 0;
        }
    }
    // function to add node at the end
    void addAtEnd(Node *n)
    {
        if (head == NULL)
        {
            head = n;
            n->next = NULL;
        }
        else
        {
            Node *n2 = getLastNode();
            n2->next = n;
        }
    }
    // function to get the last node
    Node *getLastNode()
    {
        Node *ptr = head;
        while (ptr->next != NULL)
        {
            ptr = ptr->next;
        }
        return ptr;
    }
    // function to search a value
    Node *search(int k)
    {
        Node *ptr = head;
        while (ptr != NULL && ptr->data != k)
        {
            ptr = ptr->next;
        }
        if(ptr!=NULL &&ptr->data == k){
            cout << k << " Found in the list " << endl;
        }
        else{
            cout <<k<< ", Not found :( " << endl;
        }
    }
    // function to delete any node
    Node *deleteNode(int x)
    {
        Node *n = search(x);
        Node *ptr = head;
        if (ptr == n)
        {
            head = n->next;
            return n;
        }
        else
        {
            while (ptr->next != n)
            {
                ptr = ptr->next;
            }
            ptr->next = n->next;
            return n;
        }
    }
    // function to print the list nodes
    void PrintList()
    {
        Node *ptr = head;
        while (ptr != NULL)
        {
            cout <<"| "<< ptr->data<<" |" << "->";
            ptr = ptr->next;
        }
    }

    LinkedList()
    {
        head = NULL;
    }
};

int main(){
    // instantiating an Object of Linked List on stack
    LinkedList L;

    // instantiating the objects of Node on heap
    Node *n1 = new Node(1);
    Node *n2 = new Node(2);
    Node *n3 = new Node(3);

    // Adding elements to the list
    L.addAtFront(n1);
    L.addAtFront(n2);
    L.addAtEnd(n3);

    // Display the linked list
    cout << "Your Linked List is Ready :"<<endl;
    cout << "___________________________" << endl;
    cout << endl;
    L.PrintList();
    cout << endl;
    
    // search whether the given number is present in the list or not
    
    L.search(4);
    L.search(2);

    // Release memory reserved by Objects of Node
    delete[] n1;
    delete[] n2;
    delete[] n3;

    return 0;
}