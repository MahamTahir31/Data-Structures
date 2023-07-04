#include <iostream>
#include <cstdlib>
using namespace std;

// Run Successfully !

// Stack via Dynamic Linked List
// _____________________________

class Node {
    public:
        int data; //items of stack
        Node *next; // pointer to point the next item of stack
    Node(int x) {
        data = x;
        next = NULL;
    }
};

class Stack {
    public:
        Node *top;
        
        // functio to add the items on top of the stack
        void push(Node *n) {
            n->next = top;
            top = n;
        }

        // function to delete the items from top of the stack
        void pop() {
            Node* n = top;
            top = top->next;
            delete(n);
        }

        // functions to display the items of stack
        void print() {
            Node* ptr = top;
            while(ptr != NULL) {
                cout <<"| "<< ptr->data<<" |"<<endl;
                ptr = ptr->next;
            }
        }

        // constructor to empty the pointer top 
        Stack() {
            top = NULL;
        }
};

int main() {
    // instantiating an object of stack on the stack segment
    Stack S;
    
    // instantiating the objects of node on the heap
    Node *n1 = new Node(67);
    Node *n2 = new Node(42);
    Node *n3 = new Node(36);
    
    // adding elements to the stack
    S.push(n1);
    S.push(n2);
    S.push(n3);
    
    // display the stack
    cout << "Your stack is ready :" <<endl;
    cout << "====================" << endl;
    S.print();
    
    cout << endl;
    
    // pop last added element to the stack
    S.pop();
    // now display the stack
    cout << "we popped the last element from your stack :|" << endl;
    cout << "=============================================" << endl;
    S.print();

    // releasing memory reserved by objects of Node
    delete [] n1;
    delete [] n2;
    delete [] n3;
    
    return 0;
}