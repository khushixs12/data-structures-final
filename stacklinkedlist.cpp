#include <iostream>
#include <conio.h>
using namespace std;

class node
{
public:
    int data;
    node *next;

    node()
    {
        next = NULL;
    }
};

class slinkedlist
{
private:
    int node_count;

public:
    node *newnode, *top, *ptr;

    slinkedlist()
    {
        top=NULL;
        node_count = 0;
    }

    void push(node *&top, int val)
    {
        newnode = new node();
        newnode->data = val;
        if (top == NULL)
        {
            newnode->next = NULL;
            top = newnode;
        }
        else
        {
            newnode->next = top;
            top = newnode;
        }
        node_count++;
    }

    void pop(node *&top)
    {
        if(top==NULL)
        {
            cout << "Underflow" << endl;
            return;
        }
        ptr=top;
        top=top->next;
        cout << "The value being deleted is " << ptr->data << endl;
        delete ptr;
        node_count--;
    }

    int peep(node *&top)
    {
        if(top==NULL)
            return -1;
        else
            return top->data;
    }

    void change(node *&top, int pos)
    {
        if(pos> node_count || pos < 1)
        {
            cout << "Position does not exist." << endl;
            return;
        }
        ptr=top;
        for(int i=1; i<node_count-pos+1; i++)
        {
            ptr=ptr->next;
        }
        cout << "Enter the replaced value: ";
        cin >> ptr->data;
        cout << "Value changed at position " << pos << endl;
    }

    void display(node *top)
    {
        ptr = top;
        if (top == NULL)
        {
            cout << "Stack is Empty" << endl;
        }
        else
        {
            while (ptr != NULL)
            {
                cout << ptr->data << " ";
                ptr = ptr->next;
            }
            cout << endl;
        }
    }
};

int main()
{
    slinkedlist sll;
    node *top = NULL;
    int val, pos, option;

    cout << "1: PUSH" << endl;
    cout << "2: POP" << endl;
    cout << "3: PEEP" << endl;
    cout << "4: CHANGE" << endl;
    cout << "5: DISPLAY" << endl;

    do
    {
        cout << "Enter your option: ";
        cin >> option;

        switch (option)
        {
        case 1:
            cout << "Enter the number to be pushed on stack: ";
            cin >> val;
            sll.push(top, val);
            break;
        case 2:
            sll.pop(top);
            break;
        case 3:
            val = sll.peep(top);
            if (val != -1)
            {
                cout << "The value at the top of stack is " << val << endl;
            }
            else
            {
                cout << "Stack is Empty" << endl;
            }
            break;
        case 4:
            cout << "Enter the position of the node you want to change: ";
            cin >> pos;
            sll.change(top, pos);
            break;
        case 5:
            sll.display(top);
            break;
        }
    }
    while (option != 6);
    getch();
    return 0;
}
