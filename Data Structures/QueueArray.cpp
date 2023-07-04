#include <iostream>
#include <string>
using namespace std;

// Run Successfully !

// Queue By using Array
// ____________________

struct Queue
{
    int first, position, capacity;
    int *queue;
    Queue(int c)
    {
        first = position = 0;
        capacity = c;
        queue = new int;
    }

    // function to add the element to the queue
    void enqueue(int data)
    {

        if (capacity == position)
        {
            cout << "overflow error ! because queue is totally filled " << endl;
            cout << "===================================================" << endl;
            return;
        }
        else
        {
            queue[position] = data;
            position++;
        }
    }

    // function to remove the element from the queue
    void dequeue()
    {
        if (first == position)
        {
            cout << "Underflow Error !, as queue is already empty " << endl;
            cout << "=============================================" << endl;
        }
        else
        {
            for (int i = 0; i < position - 1; i++)
            {
                queue[i] = queue[i + 1];
            }
            position--;
        }
    }
    // function to diplay the queue
    void displayqueue()
    {

        if (first == position)
        {
            cout << "At this time, Queue is empty" << endl;
            cout << "============================" << endl;
        }
        else
        {

            // traverse front to rear and print elements
            cout << "Your queue is ready :" << endl;
            cout << "======================" << endl;
            for (int i = first; i < position; i++)
            {
                cout << "<--" << queue[i];
            }
        }
    }

    // function to display the front element of queue
    void queueFront()
    {
        if (first == position)
        {
            cout << "Queue is Empty" << endl;
        }
        cout << "Front Element is : " << queue[first] << endl;
        cout << "=====================" << endl;
    }
};
int main()
{

    Queue que(10);

    que.displayqueue();
    // adding elements to the queue
    que.enqueue(1);
    que.enqueue(2);
    que.enqueue(3);
    que.enqueue(4);
    que.enqueue(5);
    que.enqueue(6);
    que.enqueue(7);
    que.enqueue(8);
    que.enqueue(9);
    que.enqueue(10);
    que.displayqueue(); // display the queue
    cout << endl;
    // removing an element from the queue
    que.dequeue();

    cout << endl
         << "After deleting 1 node " << endl;
    cout << "======================" << endl;
    que.displayqueue();
    cout << endl;
    que.queueFront(); // display the front item of queue which is entered first
}