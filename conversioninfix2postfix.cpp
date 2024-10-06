//conversion from infix to postfix
#include <iostream>
#include <conio.h>
#include <cstring>
using namespace std;
#define MAX 100
char st[MAX];
int top = -1;

void push(char st[], char val)
{
    if (top == MAX - 1)
    {
        cout << "Stack Overflow" << endl;
    }
    else
    {
        top++;
        st[top] = val;
    }
}

char pop(char st[])
{
    char val = ' ';
    if (top == -1)
    {
        cout << "Stack Underflow" << endl;
        return -1;
    }
    else
    {
        val = st[top];
        top--;
        return val;
    }
}

int getPriority(char op)
{
    if (op == '/' || op == '*' || op == '%')
        return 2;
    else if (op == '+' || op == '-')
        return 1;
    return 0;
}

void infix_postfix(char source[], char target[])
{
    int i = 0, j = 0;
    char temp;
    strcpy(target, "");
    while (source[i] != '\0')
    {
        if (source[i] == '(')
        {
            push(st, source[i]);
            i++;
        }
        else if (source[i] == ')')
        {
            while ((top != -1) && (st[top] != '('))
            {
                target[j] = pop(st);
                j++;
            }
            if (top == -1)
            {
                cout << "Incorrect Expression";
                exit(1);
            }
            temp = pop(st);
            i++;
        }
        else if (isdigit(source[i]) || isalpha(source[i]))
        {
            target[j] = source[i];
            j++;
            i++;
        }
        else if (source[i] == '+' || source[i] == '-' || source[i] == '*' || source[i] == '/' || source[i] == '%')
        {
            while ((top != -1) && (st[top] != '(') && (getPriority(st[top]) >= getPriority(source[i])))
            {
                target[j] = pop(st);
                j++;
            }
            push(st, source[i]);
            i++;
        }
        else
        {
            cout << "Incorrect Element in Expression" << endl;
            exit(1);
        }
    }
    while ((top != -1) && (st[top] != '('))
    {
        target[j] = pop(st);
        j++;
    }
    target[j] = '\0';
}

int main()
{
    char infix[100], postfix[100];
    cout << "Enter any infix expression: ";
    cin >> infix;
    strcpy(postfix, "");
    infix_postfix(infix, postfix);
    cout << "The corresponding postfix expression is " << postfix;
    getch();
    return 0;
}
