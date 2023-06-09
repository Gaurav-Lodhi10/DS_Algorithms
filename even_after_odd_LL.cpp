#include<iostream>
using namespace std;
#include "linkedlist.h"
Node* takeInput(){
    int data;
    cin>>data;
    Node*head=NULL;
    Node*tail=NULL;
    while(data!=-1){
        Node*newNode=new Node(data);
        if(head==NULL){
            head=newNode;
            tail=newNode;
        }
        else{
            tail->next=newNode;
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
Node* evenAfterOdd(Node*head){
    Node*oddH=NULL;
    Node*oddT=NULL;
    Node*evenH=NULL;
    Node*evenT=NULL;
    Node*temp=head;
    while(temp!=NULL){
        if(temp->data%2!=0){
            if(oddH==NULL){
                oddH=temp;
                oddT=temp;
            }
            else{
                oddT->next=temp;
                oddT=oddT->next;
            }
        }
        else{
            if(evenH==NULL){
                evenH=temp;
                evenT=temp;
            }
            else{
                evenT->next=temp;
                evenT=evenT->next;
            }
        }
        temp=temp->next;
    }
    if(oddH==NULL){
        return evenH;
    }
    else{
        oddT->next=evenH;
        if(evenH!=NULL){
            evenT->next=NULL;
        }
        return oddH;
    }
}
int main(){
    Node*head=takeInput();
    head=evenAfterOdd(head);
    print(head);
    return 0;
}