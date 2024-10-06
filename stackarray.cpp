#include <iostream>
#include <conio.h>
using namespace std;
#define MAX 3
int st[MAX], top=-1;

void push(int st[], int val)
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

int pop(int st[])
{
    int val;
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

int peep(int st[])
{
    if(top==-1)
    {
        cout << "Stack is Empty" << endl;
        return -1;
    }
    else
    {
        return st[top];
    }
}

int change(int st[], int val)
{
    int rep;
    if(top==-1)
    {
        cout << "Stack is empty" << endl;
        return -1;
    }
    else if(val>MAX || val<0)
    {
        cout << "Index should be within the size limit." << endl;
        return -1;
    }
    else
    {
        cout << "Enter the replaced value: ";
        cin >> rep;
        st[val]=rep;
        cout << "Value changed at " << val << " index." << endl;
    }
}

void display(int st[])
{
    int i;
    if(top==-1)
    {
        cout << "Stack is Empty" << endl;
    }
    else
    {
        for(i=top; i>=0; i--)
        {
            cout << st[i] << " ";
        }
    }
}

int main()
{
    int val, option;
    cout << " SIZE IS 3" << endl;
    cout << "1: PUSH" << endl;
    cout << "2: POP" << endl;
    cout << "3: PEEP" << endl;
    cout << "4: CHANGE" << endl;
    cout << "5: DISPLAY" << endl;

    do
    {
        cout << "Enter your option: ";
        cin >> option;

        switch(option)
        {
        case 1:
            cout << "Enter the number to be pushed on stack: ";
            cin >> val;
            push(st, val);
            break;
        case 2:
            val=pop(st);
            if(val!=-1)
            {
                cout << "The value deleted from stack is " << val << endl;
            }
            break;
        case 3:
            val=peep(st);
            if(val!=-1)
            {
                cout << "The value stored at the top of stack is " << val << endl;
            }
            break;
        case 4:
            cout << "Enter the index that you want to change: ";
            cin >> val;
            change(st, val);
            break;
        case 5:
            display(st);
            cout << endl;
            break;
        }
    }
    while(option!=6);
    getch();
    return 0;
}


