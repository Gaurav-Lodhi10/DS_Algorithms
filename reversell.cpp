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
void  print(Node*head){
    Node*temp=head;
    while(temp!=NULL){
        cout<<temp->data<<" ";
        temp=temp->next;
    }
}
Node*reverselist(Node*head){
	Node*current=head;
	Node*previous=NULL;
	while(current!=NULL){
		Node*temp=current->next;
		current->next=previous;
		previous=current;
		current=temp;
	}
	return previous;
}
Node*reverser(Node*head){
    if(head==NULL || head->next==NULL){
        return head;
    }
    Node*smallhead=reverser(head->next);
    Node*tail=head->next;
    tail->next=head;
    head->next=NULL;
    return smallhead;
}
int main(){
    Node*head=takeinput();
    Node*head2=reverser(head);
    print(head2);

    return 0;
}