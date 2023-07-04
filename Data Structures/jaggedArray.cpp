#include <iostream>
#include <iomanip>
#include <string>
using namespace std;

// Run Successfully !
// __________________

// Jagged Array 
// ____________

int main(){
    int Rows=7;
    int NCols;
  
    int **TDA=new int*[Rows];

    cout << "Enter your data here Rows=Rows+(Rows-1) times"<< endl;
    for (int i = 0; i < Rows;i++){
        
        TDA[i] = new int[i+1];
        for (int j = 0; j < i+1;j++){
            cin >> TDA[i][j];
            
        }
    }
    cout << "Your Jagged Array is Ready :) to display : " << endl;
    cout << "==========================================="<<endl;
    for (int i = 0; i < Rows;i++){
        for (int j = 0; j <i+1;j++){
            cout << TDA[i][j] << " ";
        }
        cout << endl;
    }
    for (int i = 0; i < Rows;i++){
        delete[] TDA[i];
    }
    delete[] TDA;

    return 0;
}