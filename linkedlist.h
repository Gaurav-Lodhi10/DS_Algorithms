class Node{
    public:
    int data;
    Node*next;
    public:
    Node(int data){
        this->data=data;
        next=NULL;
    }
    
   
};
class doubleNode{
    public:
    int data;
    Node*head;
    Node*tail;
    public:
    doubleNode(int data){
        head=NULL;
        tail=NULL;
    }
};