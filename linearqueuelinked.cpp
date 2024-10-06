#include <iostream>
#include <conio.h>
using namespace std;
class node
{
public:
    int data ;
    node *next;

    node()
    {
        next=NULL;
    }
};

class slinkedlist
{
public:
    node *front, *rear, *ptr;

    slinkedlist()
    {
        front=NULL;
        rear=NULL;
    }

    void enqueue()
    {
        int val;
        ptr=new node();
        cout << "Enter the value: ";
        cin >> val;
        ptr->data=val;

        if(front==NULL)
        {
            front=rear=ptr;
            front->next=rear->next=NULL;
        }
        else
        {
            rear->next=ptr;
            rear=ptr;
            rear->next=NULL;
        }
    }

    void dequeue()
    {
        if(front==NULL)
        {
            cout << "Queue Underflow" << endl;
            return;
        }
        else
        {
            ptr=front;
            cout << "The value being deleted is " << ptr->data << endl;
            front=front->next;
            delete ptr;
        }
    }


    void display_lq()
    {
        ptr=front;
        if(ptr==NULL)
        {
            cout << "Queue is Empty" << endl;
        }
        else
        {
            while(ptr!=NULL)
            {
                cout << ptr->data << " ";
                ptr=ptr->next;
            }
        }
    }
};

int main()
{
    slinkedlist sll;
    int option;
    cout << "1: Insert" << endl << endl;
    cout << "2: Delete" << endl << endl;
    cout << "3: Display" << endl << endl;

    do
    {
        cout << "Enter your option: ";
        cin >> option;
        switch(option)
        {
        case 1:
            sll.enqueue();
            break;
        case 2:
            sll.dequeue();
            break;
        case 3:
            sll.display_lq();
            cout << endl;
            break;
        }
    }while(option!=4);
    return 0;
}
