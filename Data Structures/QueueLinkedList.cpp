#include <iostream>
using namespace std;

// Run Successfully !

// Queue using Dynamic Linked List
// ________________________________

struct QueueNode
{
    int data;
    QueueNode *next;
    QueueNode(int d)
    {
        data = d;
        next = NULL;
    }
};
struct Queue
{
    QueueNode *first, *position;
    Queue() { first = position = NULL; }

    // function to add the elements to the queue
    void enqueue(int Data)
    {
        QueueNode *temp = new QueueNode(Data);

        if (position == NULL)
        {
            first = position = temp;
    
        }
        position->next = temp;
        position = temp;
    }
    // function to remove the elements from the queue
    void dequeue()
    {
        
        
        QueueNode *temp = first;
        first = first->next;
        if (first == NULL){
            position = NULL;
        }
        delete (temp);
    }

    // function to display the queue
    void Display()
    {
        struct QueueNode *temp;
        temp = first;
        if ((first == NULL) && (position == NULL))
        {
            cout << "Queue is empty" << endl;
            cout << "================" << endl;
        }
        else{
        cout << "Your queue is ready : "<<endl;
        cout << "=======================" << endl;
        while (temp != NULL)
        {
            cout << "<--"<<temp->data;
            temp = temp->next;
        }
        cout << endl;
        }
    }
};

int main()
{

    Queue q;
    q.enqueue(10);
    q.enqueue(20);
    q.enqueue(30);
    q.enqueue(40);
    q.enqueue(50);
    q.Display();

    q.dequeue();
    cout <<"After removing the front element from the queue "<<endl;
    cout << "=================================================" << endl;

    q.Display();

    cout << "Queue front element is : " << (q.first)->data << endl;
    cout << "=============================" << endl;

    cout << "Queue rear element is : " << (q.position)->data<<endl;
    cout << "=============================" << endl;
}