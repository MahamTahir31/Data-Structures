
#include <iostream>
#include <cstring>
using namespace std;

// Run Successfully !

// Expression Parser
// _________________

// function to compare the operators
int IsOperator(char op)
{
    {
        if (op == '^')
            return 3;
        else if (op == '*' || (op == '/') || (op == '%'))
            return 2;

        else if (op == '+' || (op == '-'))
            return 1;

        else if (op == '(' || (op == ')'))
            return 4;
    }

    return 0;
}

int main()
{
    char infix[15];

    cout << "Enter an infix expression:" << endl;
    cout << "==========================" << endl;
    cin >> infix;
    char stack[15]; // stack which can contain 15 items
    int top = -1;
    int j = 0;
    char postfix[15]; // array of postfix
    strcpy(postfix, "");

    for (int i = 0; i < strlen(infix); i++)
    {
        if (infix[i] == '(')
        {
            stack[++top] = '(';

            continue;
        }

        if (infix[i] == ')')
        {

            while (stack[top] != '(')

                postfix[j++] = stack[top--];
            top--;

            continue;
        }
        if (IsOperator(infix[i]) == 0) // means operand

            postfix[j++] = infix[i];
        else
        { // means operator
            if (stack[top] == '(' || top == -1)
            {
                stack[++top] = infix[i];

                continue;
            }

            while (top != -1 && IsOperator(infix[i]) <= IsOperator(stack[top]))
                postfix[j++] = stack[top--];
            stack[++top] = infix[i];

        } // end of else
    }     // end of loop
    while (top >= 0)
    {
        postfix[j++] = stack[top--];
    }
    postfix[j++] = '\0';
    
    cout << "Your infix expression has been successfully converted to the postfix....." << endl;
    cout << "============================================================================" << endl;
    cout << postfix << endl;
    return 0;
}