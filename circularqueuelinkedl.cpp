//CIRCULAR QUEUE IN LINKED LIST
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

        if(front==NULL && rear==NULL)
        {
            front=rear=ptr;
            front->next=front;
        }
        else
        {
            rear->next=ptr;
            rear=ptr;
            rear->next=front;
        }
    }

    void dequeue()
    {
        if(front==NULL && rear==NULL)
        {
            cout << "Queue Underflow" << endl;
            return;
        }
        else if(front==rear)
        {
            ptr=front;
            front=rear=NULL;
            cout << "The value being deleted is " << ptr->data << endl;
        }
        else
        {
            ptr=front;
            cout << "The value being deleted is " << ptr->data << endl;
            front=front->next;
            rear->next=front;
            delete ptr;
        }
    }


    void display_lq()
    {
        if (front == NULL)
        {
            cout << "Queue is Empty" << endl;
            return;
        }
        ptr = front;
        do
        {
            cout << ptr->data << " ";
            ptr = ptr->next;
        }
        while (ptr != front);
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

