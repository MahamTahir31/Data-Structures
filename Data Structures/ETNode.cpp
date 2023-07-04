#include <iostream>
#include <string.h>
#include <cstring>
#include <iomanip>
#include <cstdlib>

using namespace std;

// Expression Tree Node Program :
// ______________________________

struct ETnode{
    char ch;
    struct ETNode *LeftChild, *RightChild;
};
int IsOperator(char c)
{
    if (c == '^')
    {
        return 3;
    }
    else if (c == '*')
    {
        return 2;
    }
    else if (c == '/')
    {
        return 2;
    }
    else if (c == '%')
    {
        return 2;
    }
    else if (c == '+')
    {
        return 1;
    }
    else if (c == '-')
    {
        return 1;
    }
    else if (c == '(')
    {
        return 4;
    }
    else if (c == ')')
    {
        return 4;
    }
    else
    {
        return 0;
    }
}
int InOrder(struct ETnode *node){
    if(node->LeftChild!=NULL){
        InOrder(node->LeftChild);
    }
    else if(node->RightChild!=NULL){
        InOrder(node->RightChild);
        }
    cout << node->ch << endl;

}
int main(){
    struct ETNode *stack[10];
    int top = -1;
    struct ETnode *root = NULL;
    char infix[] = "AB+CD-*";
    for (int i = 0; i < strlen(infix);i++){
        struct ETnode *temp = (struct ETNode)malloc(sizeof(struct ETnode));
        temp->ch = infix[i];
        temp->LeftChild = temp->RightChild = NULL;
        if(IsOperator(infix[i]==0)){
            stack[++top] = temp;

        }
        else{
            temp->RightChild = stack[top--];
            temp->LeftChild = stack[top--];
            stack[++top] = temp;
        }
    }

        return 0;
}
