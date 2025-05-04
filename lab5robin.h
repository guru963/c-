#include <stdio.h>
#include <stdlib.h>

class roundrobin {
    struct node {
        int data;
        struct node* next;
    } *head, *temp, *tempdisplay;
    
    int curr;  
public:
    // Constructor: Initializes the circular linked list
    roundrobin() {
        head = NULL;
        temp = head;
        curr = -1;
        tempdisplay = NULL;
    }

    // Function to insert a process with given burst time
    void insertprocess(int value) {
        struct node* newnode = (struct node*)malloc(sizeof(struct node));
        newnode->data = value;
        if (head == NULL) {  
            // If the list is empty, create the first node
            newnode->next = newnode;
            head = newnode;
        } else {  
            // Insert at the end of the circular list
            temp = head;
            while (temp->next != head) {
                temp = temp->next;
            }
            newnode->next = head;
            temp->next = newnode;
        }
        curr++;
    }

    // Function to execute processes using Round Robin Scheduling
    void executeprocess(int target) {
        temp = head;
        struct node* temp2;
        
        while (head != NULL && curr != -1 && temp != NULL) {
            int value = temp->data - target;  // Reduce burst time
            
            if (value <= 0) {  
                // If process is completed
                temp2 = head;
                if (head == temp) {  
                    // Deleting head process
                    if (curr - 1 == -1) {  
                        // If it's the last process, free memory
                        free(head);
                        head = NULL;
                        temp = NULL;
                        curr = -1;
                        printf("Process Completed\n");
                        break;
                    } else {  
                        // Remove head and update links
                        while (temp2->next != head) {
                            temp2 = temp2->next;
                        }
                        temp2->next = temp->next;
                        head = temp->next;
                        free(temp);
                        temp = head;
                    }
                } else if (temp->next == head) {  
                    // Deleting the last process in the list
                    struct node* prev = NULL;
                    while (temp2->next != head) {
                        prev = temp2;
                        temp2 = temp2->next;
                    }
                    if (prev) prev->next = head;
                    free(temp2);
                } else {  
                    // Deleting a process in between
                    struct node* prev = NULL;
                    while (temp2->next != temp) {
                        prev = temp2;
                        temp2 = temp2->next;
                    }
                    prev->next = temp->next;
                    free(temp);
                    temp = prev->next;
                }
                curr--;
            } else {  
                // Process still needs more execution
                temp->data = value;
                temp = temp->next;
            }
            display();  // Display queue after each iteration
        }
    }

    // Function to display the process queue
    void display() {
        if (head == NULL) {
            printf("Queue is empty\n");
            return;
        }

        tempdisplay = head;
        while (tempdisplay->next != head) {
            printf("%d ", tempdisplay->data);
            tempdisplay = tempdisplay->next;
        }
        printf("%d\n", tempdisplay->data);
    }
};
