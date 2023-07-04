#include <iostream>
#include <list>
using namespace std;

// Run Successfully

// Closed hashing
// ______________
class Hashing
{
private:
    int size;
    int *array;

public:
    // creating a dynamic array of size n
    void hashtable(int n)
    {
        this->size = n;
        array = new int[n];
        cout << "Array\'s size : " << size << endl;
        cout << "==================\n\n";
    }
    // function to assign a whole array to null
    void makingArrayNull()
    {

        cout << "WE ARE INITIALIZING ALL ARRAY VALUES TO -1" << endl; // because array has a garbage value
        cout << "============================================\n";

        for (int i = 0; i < size; i++)
        {
            array[i] = -1;
            cout << "array[" << i << "] => " << array[i] << endl;
        }
    }

    int hashindex(int key)
    {
        return key % size;
    }
    void insertdata(int value)
    {

        int ht = hashindex(value);

        if (array[ht] == -1) //  no collision
        {
            array[ht] = value;
        }
        else // collision happened
        {
            while (array[ht] != -1)
            { // if index is not empty

                ht = (ht + 1) % size; // move to empty index
            }
            array[ht] = value;
            ht++;
        }
    }
    int display() // display the hashtable
    {
        // cout << array[7] << endl;

        cout << "\nYour Hash Table is Ready :" << endl;
        cout << "===========================\n\n";
        cout << "__________\n|Key | Val|\n__________\n";
        for (int i = 0; i < size; i++)
        {
            cout << "| " << i << " | " << array[i] << " |\n";
            if (i == size - 1)
            {
                cout << "__________\n\n";
            }
        }
        return 0;
    }
};
int main()
{
    Hashing hash;
    hash.hashtable(10);
    hash.makingArrayNull();

    hash.insertdata(60);
    hash.insertdata(56);
    hash.insertdata(43);
    hash.insertdata(47);
    hash.insertdata(38);
    hash.insertdata(59);
    hash.insertdata(33);
    hash.insertdata(33);
    hash.insertdata(12);
    hash.insertdata(33);
    hash.display();

    return 0;
}