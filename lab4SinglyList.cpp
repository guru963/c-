#include <stdio.h>
#include <stdlib.h>
#include <vector>

class ll {
    struct node {
        int data;
        struct node* next;
    } *head, *temp;

public:
    ll() {
        head = NULL;
        temp = head;
    }
    void insertatbeg(int value);
    void display();
    void insertatend(int value);
    void insertatpos(int value, int position);
    int deleteatbeg();
    int deleteatend();
    int deleteatpos(int position);
    int search(int target);
    void displayreverse(struct node*);
    void printreverse();
    void reverselink();
};

int main() {
    ll list1;
    int choice, value, position;
    while (1) {
        printf("\n1) Insert at beginning\n");
        printf("2) Insert at end\n");
        printf("3) Insert at position\n");
        printf("4) Delete at beginning\n");
        printf("5) Delete at end\n");
        printf("6) Delete at position\n");
        printf("7) Search an element\n");
        printf("8) Display list\n");
        printf("9) Display Reverse\n");
        printf("10) Reverse link\n");
        printf("11) Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);
        
        switch (choice) {
            case 1:
                printf("Enter the value: ");
                scanf("%d", &value);
                list1.insertatbeg(value);
                list1.display();
                break;
            case 2:
                printf("Enter the value: ");
                scanf("%d", &value);
                list1.insertatend(value);
                list1.display();
                break;
            case 3:
                printf("Enter the value: ");
                scanf("%d", &value);
                printf("Enter the position: ");
                scanf("%d", &position);
                list1.insertatpos(value, position);
                list1.display();
                break;
            case 4:
                printf("The element deleted is %d\n", list1.deleteatbeg());
                list1.display();
                break;
            case 5:
                printf("The element deleted is %d\n", list1.deleteatend());
                list1.display();
                break;
            case 6:
                printf("Enter the position: ");
                scanf("%d", &position);
                printf("The element deleted is %d\n", list1.deleteatpos(position));
                list1.display();
                break;
            case 7:
                printf("Enter the value to search: ");
                scanf("%d", &value);
                printf("Element found at position: %d\n", list1.search(value));
                break;
            case 8:
                list1.display();
                break;
            case 9:
                list1.printreverse();
                
                break;
            case 10:
                list1.reverselink();
                list1.display();
                break;
            case 11:
                printf("Exiting the program");
                exit(0);
            default:
                printf("Invalid choice, try again!\n");
        }
    }
    return 0;
}

void ll::insertatbeg(int value) {
    struct node* newnode = (struct node*)malloc(sizeof(struct node));
    newnode->data = value;
    newnode->next = head;
    head = newnode;
}

void ll::insertatend(int value) {
    struct node* newnode = (struct node*)malloc(sizeof(struct node));
    newnode->data = value;
    newnode->next = NULL;
    if (head == NULL) {
        head = newnode;
    } else {
        temp = head;
        while (temp->next != NULL) {
            temp = temp->next;
        }
        temp->next = newnode;
    }
}

void ll::insertatpos(int value, int position) {
    struct node* newnode = (struct node*)malloc(sizeof(struct node));
    newnode->data = value;
    temp = head;
    int i = 1;
    while (i < position - 1 && temp != NULL) {
        temp = temp->next;
        i++;
    }
    if (temp == NULL) {
        printf("Position out of range!\n");
        return;
    }
    newnode->next = temp->next;
    temp->next = newnode;
}

int ll::deleteatbeg() {
    if (head == NULL) {
        printf("Empty linked list\n");
        return -1;
    }
    int value = head->data;
    temp = head;
    head = head->next;
    free(temp);
    return value;
}

int ll::deleteatend() {
    if (head == NULL) {
        printf("Empty linked list\n");
        return -1;
    }
    temp = head;
    struct node* prev = NULL;
    while (temp->next != NULL) {
        prev = temp;
        temp = temp->next;
    }
    int value = temp->data;
    if (prev)
        prev->next = NULL;
    else
        head = NULL;
    free(temp);
    return value;
}

int ll::deleteatpos(int position) {
    if (head == NULL) {
        printf("Empty linked list\n");
        return -1;
    }
    temp = head;
    struct node* prev = NULL;
    int i = 1;
    while (i < position && temp != NULL) {
        prev = temp;
        temp = temp->next;
        i++;
    }
    if (temp == NULL) {
        printf("Position out of range!\n");
        return -1;
    }
    int value = temp->data;
    prev->next = temp->next;
    free(temp);
    return value;
}

int ll::search(int target) {
    temp = head;
    int i = 1;
    while (temp != NULL) {
        if (temp->data == target)
            return i;
        temp = temp->next;
        i++;
    }
    return -1;
}
void ll::displayreverse(struct node* head){
    if (head == NULL){
        return;
    } 
    displayreverse(head->next);  
    printf("%d ", head->data); 
}
void ll::printreverse(){
    if (head == NULL){
        printf("List is empty\n");
        return;
    }
    displayreverse(head);
    printf("\n");
}

void ll::reverselink() {
    struct node* prev = NULL;
    struct node* next = NULL;
    temp = head;
    while (temp != NULL) {
        next = temp->next;
        temp->next = prev;
        prev = temp;
        temp = next;
    }
    head = prev;
}

void ll::display() {
    temp = head;
    while (temp != NULL) {
        printf("%d ", temp->data);
        temp = temp->next;
    }
    printf("\n");
}
