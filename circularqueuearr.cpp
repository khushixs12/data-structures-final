#include <iostream>
#include<conio.h>
using namespace std;

#define MAX 3
int queue[MAX], front = -1, rear = -1;

void enqueue() {
    int num;
    cout << "Enter the number you want to insert in the queue: ";
    cin >> num;

    
    if ((rear + 1) % MAX == front) {
        cout << "Queue Overflow" << endl;
        return;
    }

    
    if (front == -1 && rear == -1) {
        front = rear = 0;
    } else {
        rear = (rear + 1) % MAX;
    }

    queue[rear] = num;
}

int dequeue() {
    if (front == -1) {
        cout << "Queue Underflow" << endl;
        return -1; 
    }

    int val = queue[front];
    if (front == rear) {
        front = rear = -1; 
    } else {
        front = (front + 1) % MAX;
    }

    return val;
}

void display() {
    if (front == -1) {
        cout << "Queue is empty." << endl;
        return;
    }

    int i = front;
    do {
        cout << queue[i] << " ";
        i = (i + 1) % MAX;
    } while (i != (rear + 1) % MAX);
    cout << endl;
}

int main() {
    int option, val;
    cout << "Size of the array is " << MAX << "." << endl << endl;
    cout << "1: Insert an element" << endl;
    cout << "2: Delete an element" << endl;
    cout << "3: Display the circular queue" << endl;
    cout << "4: Exit" << endl << endl;

    do {
        cout << "Enter your option: ";
        cin >> option;

        switch (option) {
            case 1:
                enqueue();
                break;
            case 2:
                val = dequeue();
                if (val != -1) { 
                    cout << "The number that was deleted is " << val << endl;
                }
                break;
            case 3:
                display();
                break;
            case 4:
                cout << "Exiting program." << endl;
                break;
            default:
                cout << "Invalid option. Please try again." << endl;
        }
    } while (option != 4);

    return 0;
}

