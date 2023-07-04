#include<iostream>
#include<iomanip>
#include<string>
using namespace std;

// Run Successfully !

// Row Major
// _________ 

int main(){

    int NRows, NCols;
    cout << "Enter Number of Rows : " << endl;
    cin >> NRows;
    cout << "Enter Number of Columns : " << endl;
    cin >> NCols;

    int Data[NRows][NCols];
    
    cout << "Enter your Data here : " << endl;

    for(int i = 0; i < NRows; i++){
        for(int j = 0; j < NCols; j++){
            cin >> Data[i][j];
        }
    }
    
    cout << "Here is your Data following Row Major Technique:" << endl;
    cout << endl;
    for(int i = 0; i < NRows; i++){
        for(int j = 0; j < NCols; j++){
            cout<<" |" << Data[i][j] << " ";
        } 
        cout <<"|"<< endl;
    };  
    return 0;
    cout << endl;
}