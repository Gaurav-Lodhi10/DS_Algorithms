#include<iostream>
using namespace std;
#include "linkedlist.h"
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
Node *mergeTwoSortedLinkedLists(Node *head1, Node *head2)
{
	if(head1==NULL && head2==NULL){
		return NULL;
	}
	if(head1 ==NULL && head2!=NULL){
		return head2;
	}
	if(head2==NULL && head1!=NULL){
		return head1;
	}
	Node*newhead=NULL;
	Node*tail=NULL;
	if(head1->data<=head2->data){
		newhead=head1;
		tail=head1;
		head1=head1->next;
	}
	else{
		newhead=head2;
		tail=head2;
		head2=head2->next;
	}
	while(head1!=NULL && head2!=NULL){
		if(head1->data<=head2->data){
		tail->next=head1;
		head1=head1->next;
		tail=tail->next;
		}
		else{
		tail->next=head2;
		head2=head2->next;
		tail=tail->next;
		}
	}
	if(head1!=NULL){
		tail->next=head1;
	}
	if(head2!=NULL){
		tail->next=head2;;
	}
	return newhead;
    
}
  void print(Node*head){
        Node*temp=head;
        while(temp!=NULL){
            cout<<temp->data<<" ";
            temp=temp->next;
        }
        cout<<endl;
    }
int main(){
    Node*head1=takeinput();
    Node*head2=takeinput();
    Node*head3=mergeTwoSortedLinkedLists(head1,head2);
    print(head3);

}