#include<iostream>
#include<bits/stdc++.h>
#include<algorithm>
using namespace std;

class PriorityQueue {
    int heap[10];  
    int index;    
    
public:
    PriorityQueue() {
        index = 1;
        heap[0] = 0;  
    }

    void insert(int val);
    int deleteMax();
    int search(int val);
    void heapSort();
    void display();
};

int main() {
    PriorityQueue pq;
    int choice, val, result;

    while (true) {
        cout << "\nPriority Queue Menu:\n";
        cout << "1. Insert\n";
        cout << "2. Delete\n";
        cout << "3. Display\n";
        cout << "4. Search\n";
        cout << "5. Sort (Heap Sort)\n";
        cout << "6. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
            case 1:
                if (pq.index >= 10) {
                    cout << "Priority Queue is full!" << endl;
                    break;
                }
                cout << "Enter value to insert: ";
                cin >> val;
                pq.insert(val);
                break;
            case 2:
                val = pq.deleteMax();
                if (val != -1) {
                    cout << "Deleted element: " << val << endl;
                }
                break;
            case 3:
                pq.display();
                break;
            case 4:
                cout << "Enter value to search: ";
                cin >> val;
                result = pq.search(val);
                if (result == -1) {
                    cout << "Value not found in priority queue." << endl;
                } else {
                    cout << "Value found at position: " << result << endl;
                }
                break;
            case 5:
                cout << "Sorted elements: ";
                pq.heapSort();
                break;
            case 6:
                cout << "Exiting program..." << endl;
                exit(0);
            default:
                cout << "Invalid choice! Please try again." << endl;
        }
    }

    return 0;
}
// Function to insert a value into the priority queue
void PriorityQueue::insert(int val) {
    if (index == 1) {
        heap[index] = val;
        index++;
        return;
    }
    heap[index] = val;
    int i = index;
    int parent = i / 2;
    
    while (parent >= 1 && heap[i] > heap[parent]) {
        swap(heap[i], heap[parent]);
        i = parent;
        parent = i / 2;
    }
    index++;
}

// Function to delete the highest priority element (max in max-heap)
int PriorityQueue::deleteMax() {
    if (index == 1) {
        cout << "Heap is empty!" << endl;
        return -1;
    }
    int val = heap[1];
    heap[1] = heap[index - 1];
    index--;
    int i = 1;
    while (2 * i < index) {
        int left = 2 * i;
        int right = 2 * i + 1;
        int largest = i;
        if (left < index && heap[left] > heap[largest]) {
            largest = left;
        }
        if (right < index && heap[right] > heap[largest]) {
            largest = right;
        }
        if (largest != i) {
            swap(heap[i], heap[largest]);
            i = largest;
        } else {
            break;
        }
    }
    return val;
}

// Function to search for a value in the priority queue
int PriorityQueue::search(int val) {
    for (int i = 1; i < index; i++) {
        if (heap[i] == val) {
            return i;
        }
    }
    return -1;
}

// Function to perform heap sort
void PriorityQueue::heapSort() {
    int originalIndex = index;
    while (index > 1) {
        cout << deleteMax() << " ";
    }
    cout << endl;
    index = originalIndex; 
}

// Function to display the priority queue
void PriorityQueue::display() {
    if (index == 1) {
        cout << "Priority Queue is empty!" << endl;
        return;
    }
    for (int i = 1; i < index; i++) {
        cout << heap[i] << " ";
    }
    cout << endl;
}

