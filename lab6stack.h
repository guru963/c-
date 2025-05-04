//Program for finding closed parenthesis
#include <stdio.h>
#include <stdlib.h>
#include <iostream>
#include <string>
using namespace std;
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
    //Push operation
    void push(char value){
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
    char peek(){
        char val=' ';
        if(head==NULL){
            printf("The stack is empty");
        }else{
            val=head->data;
        }
        return val;
    }
    //Pop operation
    char pop(){
        char val=' ';
        if(head==NULL){
            printf("Stack underflow");
        }else{
            val=head->data;
            head=head->next;
        }
        return val;
    }
    //Closed parenthesis operations
    bool parenthesis(string a){
        for(int i=0;i<a.length();i++){
            if(a[i]=='{'||a[i]=='['||a[i]=='('){
                push(a[i]);
                cout<<peek();
            }else{
                if(a[i]=='}'&& peek()=='{'){
                    cout<<pop();
                }else if(a[i]==']'&& peek()=='['){
                    cout<<pop();
                }else if(a[i]==')'&& peek()=='('){
                    cout<<pop();
                }
            }
        }
        if(head!=NULL){
            return false;
        }
        return true;
    
    }
};
