//To implement stack using arrays
#include <stdio.h>
#include <stdlib.h>
class stack{
    char *arr;
    int curr;
    int  size;
    public:
    stack(){
        size=5;
        arr=(char *)malloc(5*sizeof(char));
        curr=-1;
        
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
//Implementing Push operation
void stack::push(char a){
    if(curr+1>=size){
        printf("Stack is Overflowed");
    }else{
        curr=curr+1;
        arr[curr]=a;
    }
}
//Implementing Peek operation
char stack::peek(){
    char value=' ';
    if(curr==-1){
        printf("List is empty"); 
    }
    else{
        value=arr[curr];
    }
    return value;
    
}
//Implementing Pop operation
char stack::pop(){
    char val=' ';
    if(curr==-1){
        printf("Stack Underflow");
    }else{
        val=arr[curr];
        curr=curr-1;
    }
    return val;
}
