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
    cout<<endl;
}
Node*appendLastNToFirst(Node*head,int n){
    if(head==NULL || n==0){
        return head;
    }
    Node*fast=head;
    Node*slow=head;
    Node*initial=head;
    for(int i=0;i<n;i++){
        fast=fast->next;
    }
    while(fast->next!=NULL){
        fast=fast->next;
        slow=slow->next;
    }
    Node*temp=slow->next;
    slow->next=NULL;
    
    fast->next=initial;
    head=temp;
    return head;

}
int main(){
    Node*head=takeinput();
    Node*head2=appendLastNToFirst(head,4);
    print(head2);
    return 0;
}