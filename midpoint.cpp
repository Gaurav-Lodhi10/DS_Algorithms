#include<iostream>
using namespace std;
#include "linkedlist.h" 

int length(Node*head){
    Node*temp=head;
    int counter=0;
    while(temp!=NULL){
        temp=temp->next;
        counter++;
    }
    return counter-1;
}
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
Node* mid1(Node*head){
    Node*slow=head;
    Node*fast=head->next;
    while(fast!=NULL && fast->next!=NULL){
        fast=fast->next->next;
        slow=slow->next;
    }
    return slow;
}
int main(){
    Node*head=takeinput();
    Node*mid=mid1(head);
    cout<<mid->data<<endl;
}