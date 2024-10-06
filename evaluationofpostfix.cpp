#include <iostream>
#include <conio.h>
using namespace std;
#define MAX 100
float st[MAX];
int top=-1;

void push(float st[], float val)
{
    if(top==MAX-1)
    {
        cout << "Stack Overflow" << endl;
    }
    else
    {
        top++;
        st[top]=val;
    }
}

float pop(float st[])
{
    float val=-1;
    if(top==-1)
    {
        cout << "Stack Underflow" << endl;
        return -1;
    }
    else
    {
        val=st[top];
        top--;
        return val;
    }
}

float eva_postfix(char exp[])
{
    int i=0;
    float op1, op2, value;
    while(exp[i] != '\0')
    {
        if(isdigit(exp[i]))
        {
            push(st, (float)(exp[i]-'0'));
        }
        else
        {
            op2 = pop(st);
            op1 = pop(st);
            switch(exp[i])
            {
            case '+':
                value= op1+op2;
                break;
            case '-':
                value= op1-op2;
                break;
            case '/':
                value= op1/op2;
                break;
            case '*':
                value= op1*op2;
                break;
            case '%':
                value= (int)op1 % (int)op2;
                break;
            }
            push(st, value);
        }
        i++;
    }
    return (pop(st));
}

int main()
{
    float val;
    char exp[100];
    cout << "Enter postfix expression: ";
    cin >> exp;
    val=eva_postfix(exp);
    cout << "Value of postfix expression is " << val;
    getch();
    return 0;
}
