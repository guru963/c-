#include<stdio.h>
#include <stdlib.h>
class cll{
    struct node{
        int data;
        struct node* next;
    }*head,*temp;
    int curr;
    public:
    cll(){
        head=NULL;
        temp=head;
        curr=-1;
    }
    void insertatbeg(int value){
        struct node* newnode=(struct node*)malloc(sizeof(struct node));
        newnode->data=value;
        if(head==NULL){
            newnode->next=newnode;
            head=newnode;
        }else{
            temp=head;
            while(temp->next!=head){
                temp=temp->next;
            }
            newnode->next=head;
            temp->next=newnode;
            head=newnode;
        }
        curr=curr+1;
    }
    void insertatend(int value){
        struct node* newnode=(struct node*)malloc(sizeof(struct node));
        newnode->data=value;
        if(head==NULL){
            newnode->next=newnode;
            head=newnode;
        }else{
            temp=head;
            newnode->next=head;
            while(temp->next!=head){
                temp=temp->next;
            }
            temp->next=newnode;
        }
        curr=curr+1;
    }
    void insertatpos(int value,int pos){
        struct node* newnode=(struct node*)malloc(sizeof(struct node));
        newnode->data=value;
        if(head==NULL){
            newnode->next=newnode;
            head=newnode;
        }else{
            temp=head;
            int i=1;
            while(i<pos){
                temp=temp->next;
                i++;
            }
            newnode->next=temp->next;
            temp->next=newnode;
        }
        curr=curr+1;
    }
    void delatbeg(){
        struct node* headvalue;
        if(head==NULL){
            printf("List is Empty \n");
        }
        else{
            temp=head;
            headvalue=temp->next;
            while(temp->next!=head){
                temp=temp->next;
            }
            temp->next=headvalue;
            head=headvalue;
            
        }
        curr=curr-1;
    }
    void delatend(){
        struct node* prev;
        if(head==NULL){
            printf("List is Empty \n");
        }
        else{
            temp=head;
            while(temp->next!=head){
                prev=temp;
                temp=temp->next;
            }
            prev->next=head;
            
        }
        curr=curr-1;
    }
    void delatpos(int pos){
        struct node* prev;
        if(head==NULL){
            printf("List is Empty \n");
        }
        else if(pos==1){
            delatbeg();
            return ;
        }
        else if(pos==curr){
            delatend();
            return;
        }
        else{
            temp=head;
            int i=1;
            while(i<pos){
                prev=temp;
                temp=temp->next;
                i++;
            }
            prev->next=temp->next;
        }
    }
    void display(){
        temp=head;
        while(temp->next!=head){
            printf("%d ",temp->data);
            temp=temp->next;
        }
        printf("%d ",temp->data);
        printf("\n");
    }
    void search(int target){
        temp=head;
        while(temp->next!=head){
            if(target==temp->data){
                printf("Yes");
                break;
            }
            else{
                temp=temp->next;
            }
        }
        if(temp->data==target){
            printf("Yes");
        }else{
            printf("No");
        }

    }
};
int main(){
    cll list;
    list.insertatpos(56,2);
    list.insertatend(9);
    list.insertatbeg(89);
    list.display();
    list.insertatbeg(100);
    list.display();
    list.insertatbeg(1000);
    list.insertatbeg(3787);
    list.display();
    list.insertatend(224);
    list.display();
    list.insertatpos(56,2);
    list.display();
    list.delatbeg();
    list.display();
    list.delatend();
    list.display();
    list.delatpos(3);
    list.display();
    list.search(56);
    list.delatpos(1);
    list.delatpos(4);
    list.display();


}