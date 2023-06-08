#include<iostream>
using namespace std;
#include "linkedlist.h"

 int length(Node*head){
        Node*temp=head;
        if(temp!=NULL){
            return 1+length(temp->next);
        }
}

Node*insert(Node*head,int pos){
    
}
int main(){
    Node*head;
    
}