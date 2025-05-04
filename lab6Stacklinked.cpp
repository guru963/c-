//Stack using linked list
#include <stdio.h>
#include <stdlib.h>
class stack{
    struct node{
        char data;
        struct node *next;
    }*head,*temp;
    public:
    stack(){
        head=NULL;
        temp=head;
    }
    void push(char a);
    char peek();
    char pop();
};
int main(){
    stack st;
    int choice;
    char element;
    
    while (1) {
        printf("\nMenu:\n");
        printf("1. Push\n");
        printf("2. Peek\n");
        printf("3. Pop\n");
        printf("4. Exit\n");
        printf("Enter your choice: ");
        scanf(" %d", &choice);
        
        switch (choice) {
            case 1:
                printf("Enter the character to push: ");
                scanf(" %c", &element);
                st.push(element);
                break;
            case 2:
                printf("Top element: %c\n", st.peek());
                break;
            case 3:
                printf("Popped element: %c\n", st.pop());
                break;
            case 4:
                exit(0);
            default:
                printf("Invalid choice!\n");
        }
    }
    return 0;
    
}
//Push operation
void stack::push(char value){
    struct node* newnode=(struct node*)malloc(sizeof(struct node));
    newnode->data=value;
    if(head==NULL){
        newnode->next=0;
        head=newnode;
    }else{
        newnode->next=head;
        head=newnode;
    }
}
//Peek operation
char stack::peek(){
    char val=' ';
    if(head==NULL){
        printf("The stack is empty");
    }else{
        val=head->data;
    }
    return val;
}
//Pop operation
char stack::pop(){
    char val=' ';
    if(head==NULL){
        printf("Stack underflow");
    }else{
        val=head->data;
        head=head->next;
    }
    return val;
}