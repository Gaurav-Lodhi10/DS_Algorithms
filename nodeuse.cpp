#include<iostream>
using namespace std;
#include "linkedlist.h"  
Node* insertNode(Node *head, int i, int data) {
if(head ==NULL){
        return head;
    }
    if(i==0){
        Node *newnode=new Node(data);
        newnode->next=head;
        head=newnode;
        // return head;
    }
    else if(i==1){
        Node *newnode=new Node(data);
        Node*temp=head->next;
        head->next=newnode;
        newnode->next=temp;
        return head;
    }
    else{
        insertNode(head->next,i-1,data);
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
    // Node*insert(Node*head,int data,int position){

        //!add node by itrative method
        // Node*newnode=new Node(data);
        // Node*temp=head;
        // if(position==0){
        //     newnode->next=head;
        //     head=newnode;
        //     return head;
        // }
        // int count=0;
        // while(temp->next!=NULL && count<position-1){
        //     temp=temp->next;
        //    count++;
        // }
        // if(temp!=NULL){
        //      Node*a=temp->next;
        //     temp->next=newnode;
        //     newnode->next=a;
        // }

        // return head;
        
        //!Add node by recursive method
        // if(head==NULL){
        //     return head;
        // }
        // if(position==0){
        //     Node*newnode=new Node(data);
        //     newnode->next=head;
        //     head=newnode;
        //     // return head;
        // }
        // if(position ==1){
        //     Node*newnode=new  Node(data);
        //     Node*temp =head->next;
        //     head->next=newnode;
        //     newnode=temp;
        //     return head;
        // }
        // else{
        // insert(head->next,data,position-1);
        // }
        // return  head;

    // }
    Node * deletenode(Node*head,int position){
        //! Delete node by itreative
        // Node*temp=head;
        // if(head==NULL){
        //     return head;
        // }
        // if(position==0){
        //     head=head->next;
        //     delete temp;
        //     return head;
        // }
        // int count=0;
        // while(temp->next!=NULL && count<position-1 ){
        //     temp=temp->next;
        //     count++;
        // }
        // if(temp->next!=NULL){
        //     Node*current=temp->next->next;
        //     delete temp->next;
        //     temp->next=current;
        // }
        // return head;
        //! Delete node recursive
        if(head==NULL || head->next==NULL){
            return head;
        }
        else if(position ==0){
            Node*temp=head;
            head=temp->next;
            delete temp;
        }
        else if(position ==1){
            Node*temp=head->next->next;
            delete  head->next;
            head->next=temp;
            return head;
        }
        else{
            deletenode(head->next,position-1);
        }
        return head;
    }
    int value(Node*head,int position){
        Node*temp=head;
        int counter=0;
        while(temp->next!=NULL&& counter<position ){
            temp=temp->next;
            counter++;
        }
        return temp->data;            
    }
    int length(Node*head){
        Node*temp=head;
        if(temp!=NULL){
            return 1+length(temp->next);
        }
    }
int main(){
    Node*head=takeinput();
    print(head);
    // Node*head2=head->deletenode(head,4);
    // head2->print(head2);
    // Node*head3=head3->insert(head,99,3);
    // head3->print(head3);
    Node*head2=insertNode(head,2,99);
    print(head2);
    // length(head);
    // cout<<head->value(head,3);
}
