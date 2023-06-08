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
void print(Node*head){
  Node*temp=head;
  while(temp!=NULL){
      cout<<temp->data<<" ";
      temp=temp->next;
  }
  cout<<endl;
}
Node*merge(Node*head1,Node*head2){
    Node*newhead=NULL;
    Node*tail=NULL;
    if(head1==NULL && head2==NULL){
        return newhead;
    }
    if(head1==NULL){
        return head2;
    }
    if(head2==NULL){
        return head1;
    }
    if(head1->data<=head2->data){
        newhead=head1;
        tail=head1;
        head1=head1->next;
    }
    else if(head2->data<head1->data){
        newhead=head2;
        tail=head2;
        head2=head2->next;
    }
    while(head1!=NULL && head2!=NULL){
        if(head1->data<=head2->data){
        tail->next=head1;
        tail=tail->next;
        head1=head1->next;
        }
        else if(head2->data<head1->data){
        tail->next=head2;
        tail=tail->next;
        head2=head2->next;
        }
    }
    if(head1!=NULL && head2==NULL){
            while(head1!=NULL){
                tail->next=head1;
                tail=tail->next;
                head1=head1->next;
            }
    }
    if(head2!=NULL && head1==NULL){
            while(head2!=NULL){
                tail->next=head2;
                tail=tail->next;
                head2=head2->next;
            }
    }
    tail->next=NULL;
    return newhead;
}
Node*mergeSort(Node*head){
    if(head==NULL || head->next==NULL){
        return head;
    }
    Node*mid=midpoint(head);
    Node*head1=mid->next;
    mid->next=NULL;
    head=mergeSort(head);
    head1=mergeSort(head1);
    return merge(head,head1);
}
int main(){
    Node*head=takeinput();
    Node*head1=mergeSort(head);
    print(head1);
}