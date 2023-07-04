#include <iostream>
using namespace std;

// Run Suuccessfully

// Linear Searching
// _________________

// function to search a value and return its position if it is in the list.
int linearsearch(int arr[], int size, int value)
{

    for (int i = 0; i < size; i++)
    {
        if (arr[i] == value)
        {
            return i + 1; // return index of searched value
        }
    }

    return -1; // return -1 when value is not present in the list
}

int main()
{
    int array[] = {5, 10, 15, 20, 25, 30, 35, 40, 45, 50};
    cout << "\nWe have following Collection : \n";
    cout << "===============================\n";
    for (int i = 0; i < 9; ++i)
    {
        cout << array[i] << "  ";
    }
    cout << endl;

    int sz = sizeof(array) / sizeof(array[0]); // caculating size of an array
    cout << "Size of an array is : " << sz << endl;
    cout << "========================\n";
    int input;
    cout << "Enter value which you want to search ?" << endl;
    cout << "=======================================\n";
    cin >> input;
    int Result = linearsearch(array, sz, input);
    if (Result == -1)
    {
        cout << "Oops ! Value = " << input << " Not Found :( \n";
        cout << "===========================\n";
    }
    else
    {
        cout << "Value = " << input << " Found At Position \'" << Result << "\' :)" << endl;
        cout << "===============================\n";
    }
    return 0;
}