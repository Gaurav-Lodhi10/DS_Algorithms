#include<iostream>
using namespace std;
#include"linkedlist.h"
Node*takeinput(){
    int data;
    cin>>data;
    Node*head=NULL;
    Node*tail=NULL;
    while(data!=-1){
        Node *newnode=new Node(data);
        if(head==NULL){
            head=newnode;
            tail=newnode;
        }
        else{
            tail->next=newnode;
            tail=tail->next;
        }
        cin>>data;
    }
    return head;
}
void print(Node*head){
    Node*temp=head;
    while(temp!=NULL){
        cout<<temp->data<<" ";
        temp=temp->next;
    }
}
Node* midpoint(Node*head){
    if(head==NULL || head->next==NULL){
        return head;
    }
    Node*slow=head;
    Node*fast=head->next;
    while(fast!=NULL && fast->next!=NULL){
        fast=fast->next->next;
        slow=slow->next;
    }
    return slow;
}
Node*reverse(Node*head){
    if(head==NULL || head->next==NULL){
        return head;
    }
    Node*newhead=reverse(midpoint(head));
    Node*headnext=head->next;
    head->next->next=head;
    head->next=NULL;
    return newhead;
}
bool istrue(Node*head){
    if(head==NULL || head->next==NULL){
        return head;
    }
    Node*newhead=reverse(head);
    while(head!=NULL && newhead!=NULL){
        if(head->data !=newhead->data){
            return false;
        }
        else{
            head=head->next;
            newhead=newhead->next;
        }
    }
    return true;
}
int main(){
    Node*head=takeinput();
    bool ans=istrue(head);
    if(ans==true){
        cout<<"true";
    }
    else{
        cout<<"false";
    }
    return 0;
}