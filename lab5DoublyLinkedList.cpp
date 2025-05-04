#include<stdio.h>
#include<stdlib.h>
class dll{
    struct node{
        int data;
        struct node* prev;
        struct node* next;
    }*head,*temp,*tail;
    public:
    dll(){
        head=NULL;
        temp=head;
    }
    void insertatbeg(int value){
        struct node* newnode=(struct node*)malloc(sizeof(struct node));
        newnode->data=value;
        newnode->prev=NULL;
        if(head==NULL){
            newnode->next=0;
            head=newnode;
            tail=newnode;
        }else{
            temp=head;
            temp->prev=newnode;
            newnode->next=head;
            head=newnode;

        }
        

    }
    void insertatend(int value){
        struct node* newnode=(struct node*)malloc(sizeof(struct node));
        newnode->data=value;
        if(head==NULL){
            newnode->prev=0;
            newnode->next=0;
            head=newnode;
            tail=newnode;
        }else{
            temp=tail;
            newnode->next=0;
            newnode->prev=tail;
            temp->next=newnode;
            tail=newnode;
        }
        
    }
    void insertatpos(int value,int pos){
        struct node* newnode=(struct node*)malloc(sizeof(struct node));
        newnode->data=value;
        int i=1;
        temp=head;
        if(head==NULL){
            newnode->prev=0;
            newnode->next=0;
            head=newnode;
            tail=newnode;
        }
        else{
            while(i<pos){
                temp=temp->next;
                i++;
            }
            newnode->next=temp->next;
            newnode->prev=temp;
            struct node*nexttemp=temp->next;
            nexttemp->prev=newnode;
            temp->next=newnode;

    
        }

    }
    void deleteatbeg(){
        if(head==NULL){
            printf("The list is empty");
        }else{
            temp=head;
            temp=temp->next;
            temp->prev=NULL;
            head=temp;
        }
    }
    void delatend(){
        if(head==NULL){
            printf("The list is empty");
        }else{
            temp=tail;
            temp=temp->prev;
            temp->next=NULL;
            tail=temp;
        }
    }
    void delatpos(int position){
        if(head==NULL){
            printf("The list is empty");
        }else{
            int i=1;
            while(i<position){
                temp=temp->next;
                i++;
            }
            temp->next=
        }

    }
    void displayfront(){
        temp=head;
        while(temp!=0){
            printf("%d ",temp->data);
            temp=temp->next;
        }
        printf("\n");
    }

    void displayback(){
        temp=tail;
        while(temp!=0){
            printf("%d ",temp->data);
            temp=temp->prev;
        }
        printf("\n");
    }
};
int main(){
    dll list;
    list.insertatend(90);
    list.insertatbeg(5);
    list.displayfront();
    list.displayback();
    list.insertatbeg(100);
    list.insertatbeg(55);
    list.displayfront();
    list.displayback();
    list.insertatend(66);
    list.insertatend(766);
    list.displayfront();
    list.displayback();
    list.insertatpos(999,2);
    list.displayfront();
    list.displayback();
    list.deleteatbeg();
    list.displayfront();
    list.displayback();
    list.delatend();
    list.displayfront();
    list.displayback();

    

    

}