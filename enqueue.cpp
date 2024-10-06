
#include <iostream>
using namespace std;

#define MAX 5 

class Queue {
private:
    int arr[MAX]; 
    int front;    
    int rear;     

public:
    Queue() : front(-1), rear(-1) {} 

    
    bool isFull() {
        return (rear + 1) % MAX == front;
    }

    
    bool isEmpty() {
        return front == -1;
    }

    
    void enqueue(int value) {
        if (isFull()) {
            cout << "Queue is full! Cannot enqueue " << value << endl;
            return;
        }

        if (isEmpty()) {
            front = 0; 
        }

        rear = (rear + 1) % MAX; 
        arr[rear] = value; 
        cout << value << " enqueued to queue." << endl;
    }

    
    int dequeue() {
        if (isEmpty()) {
            cout << "Queue is empty! Cannot dequeue." << endl;
            return -1; 
        }

        int value = arr[front]; 
        if (front == rear) {
            front = rear = -1; 
        } else {
            front = (front + 1) % MAX;
        }
        return value; 
    }

    
    void display() {
        if (isEmpty()) {
            cout << "Queue is empty!" << endl;
            return;
        }

        cout << "Queue elements: ";
        int i = front;
        while (true) {
            cout << arr[i] << " ";
            if (i == rear) break; 
            i = (i + 1) % MAX; 
        }
        cout << endl;
    }
};

int main() {
    Queue q;

    
    q.enqueue(10);
    q.enqueue(20);
    q.enqueue(30);
    q.enqueue(40);
    q.enqueue(50);
    q.enqueue(60);

    
    q.display();

    
    cout << q.dequeue() << " dequeued from queue." << endl;
    cout << q.dequeue() << " dequeued from queue." << endl;

    
    q.display();

    return 0;
}

