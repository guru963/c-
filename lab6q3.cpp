#include<iostream>
#include<string>
#include<algorithm>
#include<stdlib.h>
using namespace std;

class stack{
    struct node{
        string data;
        struct node* next;
    }*head;
    
    public:
    stack(){
        head=NULL;
    }
    
    void push(string num){
        struct node* newnode=(struct node*)malloc(sizeof(struct node));
        new (&(newnode->data)) string(num);  // Explicitly construct the string
        newnode->next = NULL;
        if(head==NULL){
            head=newnode;
        }else{
            newnode->next=head;
            head=newnode;
        }
    }
    
    string pop(){
        string value="";
        if(head==NULL){
            return value;
        }else{
            value=head->data;
            node* temp = head;
            head=head->next;
            delete temp; // Proper memory cleanup
        }
        return value;
    }
    
    string peek(){
        string value="";
        if(head==NULL){
            return value;
        }else{
            value=head->data;
        }
        return value;
    }
    
    int priority(string c){
        if(c=="^"){
            return 3;
        }else if(c=="*" || c=="/"){
            return 2;
        }else if(c=="+"||c=="-"){
            return 1;
        }else{
            return -1;
        }
    }
    
    void infitopost(string a, string ans){
        for(int i=0; i<a.length(); i++){
            string current(1, a[i]); // Convert char to string
            
            if((a[i]>='A' && a[i]<='Z') || (a[i]>='a' && a[i]<='z') || (a[i]>='0' && a[i]<='9')){
                ans = ans + current;
            }else{
                if(head==NULL){
                    push(current);
                }else{
                   while(head != NULL && peek()!=""){
                        string c = peek();
                        int z = priority(c);
                        int y = priority(current);
                        if(y>z){
                            push(current);
                            break;
                        }else{
                            ans = ans + pop();
                        }
                   }
                   if(head==NULL){
                    push(current);
                   }
                }
            }
        }
        
        while(head!=NULL){
            ans = ans + pop();
        }
        cout << ans;
    }
    
    void infitopre(string a, string ans){
        reverse(a.begin(), a.end());
        cout << "a:" << a << '\n';
        
        for(int i=0; i<a.length(); i++){
            string current(1, a[i]); // Convert char to string
            
            if((a[i]>='A' && a[i]<='Z') || (a[i]>='a' && a[i]<='z') || (a[i]>='0' && a[i]<='9')){
                ans = ans + current;
            }else{
                if(head==NULL){
                    push(current);
                }else{
                    while(head != NULL && peek()!=""){
                        string c = peek();
                        int z = priority(c);
                        int y = priority(current);
                        if(y>=z){
                            push(current);
                            break;
                        }else{
                            ans = ans + pop();
                        }
                    }
                    if(head==NULL){
                        push(current);
                    }
                }
            }
        }
        
        while(head!=NULL){
            ans = ans + pop();
        }
        cout << ans << '\n';
        reverse(ans.begin(), ans.end());
        cout << ans << '\n';
    }
    
    void posttoinfi(string a){
        for(int i=0; i<a.length(); i++){
            string current(1, a[i]); // Convert char to string
            
            if((a[i]>='A' && a[i]<='Z') || (a[i]>='a' && a[i]<='z') || (a[i]>='0' && a[i]<='9')){
               push(current);
            }else{
                string operand2 = pop();
                string operand1 = pop();
                string expression = "(" + operand1 + current + operand2 + ")";
                push(expression);
            }
        }
        
        if(head != NULL) {
            cout << peek();
        }
    }
};

int main(){
    stack st;
    string a = "a+b*c-d+f";
    
    cout << "Infix to Postfix: ";
    st.infitopost(a, "");   
    cout << '\n';
    
    cout << "Infix to Prefix: ";
    st.infitopre(a, ""); 
    cout << '\n';
    
    cout << "Postfix to Infix: ";
    st.posttoinfi("abc*+d-f+");
    cout << '\n';
    
    return 0;
}