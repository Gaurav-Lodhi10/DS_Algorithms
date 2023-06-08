#include<iostream>
using namespace std;
#include"linkedlist.h"
doubleNode*takeinput(){
    int data;
    cin>>data;
    doubleNode*head=NULL;
    doubleNode*tail=NULL;
    while(data!=-1){
         doubleNode*newnode=new doubleNode(data);
        if(head==NULL){
            head=newnode;
            tail=newnode;
        }
        else{

        }
        cin>>data;
    }
    return head;
}