#include <iostream>
#include <cstdlib>
using namespace std;

// Node structure for the queue
struct Node {
    int data;
    struct Node* next;
};

class Queue {
private:
    struct Node* front;
    struct Node* rear;

public:
    Queue() {
        front = NULL;
        rear = NULL;
    }

    // Checks if the queue is empty
    bool isEmpty() {
        return front == NULL;
    }

    // Inserts an element into the queue
    void enqueue(int value) {
        struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
        newNode->data = value;
        newNode->next = NULL;

        if (isEmpty()) {
            front = rear = newNode;
        } else {
            rear->next = newNode;
            rear = newNode;
        }
        cout << "Enqueued: " << value << "\n";
    }

    // Removes an element from the queue
    void dequeue() {
        if (isEmpty()) {
            cout << "Queue Underflow! No elements to dequeue.\n";
            return;
        }
        struct Node* temp = front;
        cout << "Dequeued: " << front->data << "\n";
        front = front->next;

        if (front == NULL) {
            rear = NULL;
        }

        free(temp);
    }

    // Returns the front element of the queue
    void peek() {
        if (isEmpty()) {
            cout << "Queue is empty! No front element.\n";
            return;
        }
        cout << "Front element: " << front->data << "\n";
    }

    // Displays all elements in the queue
    void display() {
        if (isEmpty()) {
            cout << "Queue is empty!\n";
            return;
        }
        cout << "Queue elements: ";
        struct Node* temp = front;
        while (temp != NULL) {
            cout << temp->data << " ";
            temp = temp->next;
        }
        cout << "\n";
    }

   
};

int main() {
    Queue q;
    int choice, value;

    while (true) {
        cout << "\nQueue Operations:\n";
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
