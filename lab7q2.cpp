//Implementing circular queue
#include <iostream>
using namespace std;

#define SIZE 5 

class CircularQueue {
private:
    int arr[SIZE]; 
    int front, rear; 

public:
    CircularQueue() {
        front = -1;
        rear = -1;
    }

    // Checks if the queue is empty
    bool isEmpty() {
        return (front == -1);
    }

    // Checks if the queue is full
    bool isFull() {
        return ((rear + 1) % SIZE == front);
    }

    // Inserts an element into the queue
    void enqueue(int value) {
        if (isFull()) {
            cout << "Queue Overflow! Cannot enqueue " << value << ".\n";
            return;
        }
        if (isEmpty()) {
            front = rear = 0;
        } else {
            rear = (rear + 1) % SIZE;
        }
        arr[rear] = value;
        cout << "Enqueued: " << value << "\n";
    }

    // Removes an element from the queue
    void dequeue() {
        if (isEmpty()) {
            cout << "Queue Underflow! No elements to dequeue.\n";
            return;
        }
        cout << "Dequeued: " << arr[front] << "\n";
        if (front == rear) { 
            front = rear = -1;
        } else {
            front = (front + 1) % SIZE;
        }
    }

    // Returns the front element of the queue
    void peek() {
        if (isEmpty()) {
            cout << "Queue is empty! No front element.\n";
            return;
        }
        cout << "Front element: " << arr[front] << "\n";
    }

    // Displays all elements in the queue
    void display() {
        if (isEmpty()) {
            cout << "Queue is empty!\n";
            return;
        }
        cout << "Queue elements: ";
        int i = front;
        while (true) {
            cout << arr[i] << " ";
            if (i == rear) break;
            i = (i + 1) % SIZE;
        }
        cout << "\n";
    }
};

int main() {
    CircularQueue q;
    int choice, value;

    while (true) {
        cout << "\nCircular Queue Operations:\n";
        cout << "1. Enqueue\n";
        cout << "2. Dequeue\n";
        cout << "3. Peek\n";
        cout << "4. Display Queue\n";
        cout << "5. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
            case 1:
                cout << "Enter value to enqueue: ";
                cin >> value;
                q.enqueue(value);
                break;
            case 2:
                q.dequeue();
                break;
            case 3:
                q.peek();
                break;
            case 4:
                q.display();
                break;
            case 5:
                cout << "Exiting program.\n";
                return 0;
            default:
                cout << "Invalid choice! Please enter a number between 1 and 5.\n";
        }
    }

    return 0;
}
