#include <iostream>
using namespace std;

// Run successfully !

// Stack Program Via Static Array
// _______________________________

int stack[8];
int top = -1;

// pop function
// _____________

int pop(int *ret){
    if(top!=-1){
        *ret = stack[top];
        top--;
        return 0;
    }
    else{
        return -1;
    }
}
// push function
// ______________
int push(int data){
    if(top<8-1){
        top++;
        stack[top] = data;
        return 0;
    }
    else{
        return -1;
    }
}


main(void){
int r = stack[top];
if(pop(&r)!=0){
    cout << "Under Flow Error because stack is empty" << endl;
}
push(44);
push(45);
push(35);
push(54);
push(22);
push(10);
push(21);

for (int i = 0; i < 7;i++){
    cout <<"|" <<stack[i]<<"|" << endl;
    cout << "____"<<endl;
    if(i<6){}
    pop(&stack[i]); 
   
}
cout << "Now Stack is again empty " << endl;

}