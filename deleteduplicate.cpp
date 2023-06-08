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
Node* duplicates(Node*head){
    if(head==NULL || head->next==NULL){
        return head;
    }
    Node*current=head;
    while(current->next!=NULL){
        if(current->data==current->next->data){
            Node*temp=current->next->next;
            delete current->next;
            current->next=temp;
        }
        else{
            current=current->next;
        }
    }
    return  head;
}
int main(){
    Node*head=takeinput();
    Node*head2=duplicates(head);
    print(head2);
    return 0;
}