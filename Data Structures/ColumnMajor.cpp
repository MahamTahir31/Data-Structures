#include <iostream>
#include <iomanip>
#include <string>
using namespace std;

// Run Successfully !

// Column Major
// ____________

int main()
{

    int NRows, NCols;
    cout << "Enter number of Rows : " << endl;
    cin >> NRows;
    cout << "Enter number of Columns : " << endl;
    cin >> NCols;

    int Data[NRows][NCols];

    cout << "Enter your Data here : " << endl;

    for (int i = 0; i < NRows; i++)
    {
        for (int j = 0; j < NCols; j++)
        {
            cin >> Data[i][j];
        }
    }
    cout << "Here is your Data following Column Major Technique:" << endl;
    cout << endl;
    for (int i = 0; i < NRows; i++)
    {
        for (int j = 0; j < NCols; j++)
        {
            cout << " |" << Data[j][i] << " ";
        }
        cout << "|" << endl;
    };
    return 0;
    cout << endl;
}