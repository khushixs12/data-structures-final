#include <iostream>
#include <conio.h>
using namespace std;
#define MAX 3
int queue[MAX], front=-1, rear=-1;
void enqueue()
{
    int num;
    cout << "Enter the number you want to insert in the queue: ";
    cin >> num;
    if(rear==MAX-1)
    {
        cout << "Queue Overflow" << endl;
        return;
    }
    if(front==-1 && rear==-1)
    {
        front=rear=0;
    }
    else
    {
        rear++;
    }
    queue[rear]=num;
}

int dequeue()
{
    int val;
    if(front==-1 || front>rear)
    {
        cout << "Queue Underflow" << endl;
        return -1;
    }
    else
    {
        val=queue[front];
        front++;
        return val;
    }
}
void display()
{
    if(front==-1 || front>rear)
        cout << "Queue is empty." << endl;
    else
    {
        for(int i=front; i<=rear; i++)
        {
            cout << queue[i] << " ";
        }
    }
}
int main()
{
    int option,val;
    cout << "Size of the array is 3." << endl << endl;
    cout << "1: Insert an element" << endl << endl;
    cout << "2: Delete an element" << endl << endl;
    cout << "3: Display the queue" << endl << endl;
    do
    {
        cout << "Enter your option: ";
        cin >> option;
        switch(option)
        {
        case 1:
            enqueue();
            break;
        case 2:
            val=dequeue();
            cout << "The number that was deleted is " << val << endl;
            break;
        case 3:
            display();
            cout << endl;
            break;
        }
    }
    while(option!=4);
    return 0;
}

