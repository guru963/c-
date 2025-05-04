#include<stdio.h>
#include<stdlib.h>
class merge{
    struct node{
        int data;
        struct node* next;
    }*head1,*head2,*head;
    public:
    merge(){
        head1=NULL;
        head2=NULL;
        head=NULL;
    }
    //To create list1
    void  createlist1(int value){
        struct node* newnode=(struct node*)malloc(sizeof(struct node));
        struct node* temp;
        newnode->data=value;
        if(head1==NULL){
            head1=newnode;
            newnode->next=0;
        }
        else{
            temp=head1;
            if(temp->data>value){
                newnode->next=head1;
                head1=newnode;
            }
           else{
            while(temp->next!=0 && temp->next->data <=value){
                temp=temp->next;
            }
                newnode->next=temp->next;
                temp->next=newnode;
            
        }
           }
     }
     //To create list2
     void createlist2(int value){
        struct node* newnode=(struct node*)malloc(sizeof(struct node));
        struct node* temp;
        newnode->data=value;
        if(head2==NULL){
            head2=newnode;
            newnode->next=0;
        }else{
            temp=head2;
            if(temp->data>value){
                newnode->next=head2;
                head2=newnode;
            }
           else{
            while(temp->next!=0 && temp->next->data <=value){
                temp=temp->next;
            }
                newnode->next=temp->next;
                temp->next=newnode;
            
        }
           }
     
     }
     //Display list1
     void display1(){
        struct node* temp;
        temp=head1;
        while(temp!=0){
            printf("%d ",temp->data);
            temp=temp->next;
        }
        printf("\n");
     }
     //Display List2
     void display2(){
        struct node* temp;
        temp=head2;
        while(temp!=0){
            printf("%d ",temp->data);
            temp=temp->next;
        }
        printf("\n");
     }
     //Merge two linked lists and sort them in ascending order
     void mergelist(){
        struct node* temp;
        struct node* temp1;
        struct node* temp2;
        temp1=head1;
        temp2=head2;
        while(temp1!=0 && temp2!=0){
            struct node* newnode=(struct node*)malloc(sizeof(struct node));
            newnode->next=0;
            if(temp1->data >= temp2->data){
                newnode->data=temp2->data;
               
                temp2=temp2->next;
                if(head==NULL){
                    head=newnode;
                }else{
                    temp=head;
                    while(temp->next!=0){
                        temp=temp->next;
                    }
                    temp->next=newnode;
                }
           }
           else if(temp2->data >temp1->data){
                newnode->data=temp1->data;
                temp1=temp1->next;
                if(head==NULL){
                    head=newnode;
                }else{
                    temp=head;
                    while(temp->next!=0){
                        temp=temp->next;
                    }
                    temp->next=newnode;
                }
                
    
           }
        }
        while(temp1!=0){
            struct node* newnode=(struct node*)malloc(sizeof(struct node));
            newnode->next=0;
            newnode->data=temp1->data;
            if(head==NULL){
                head=newnode;
            }else{
                temp=head;
                while(temp->next!=0){
                    temp=temp->next;
                }
                temp->next=newnode;
            }
            temp1=temp1->next;
    
    
        }
        while(temp2!=0){
            struct node* newnode=(struct node*)malloc(sizeof(struct node));
            newnode->next=0;
            newnode->data=temp2->data;
            if(head==NULL){
                head=newnode;
            }else{
                temp=head;
                while(temp->next!=0){
                    temp=temp->next;
                }
                temp->next=newnode;
            }
            temp2=temp2->next;
    
    
        }
     }
     //Display the merged list 
     void displaymerged(){
        struct node* temp;
        temp=head;
        while(temp!=0){
            printf("%d ",temp->data);
            temp=temp->next;
        }
        printf("\n");
     }
    
    

};
