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
    doubleNode*next;
    doubleNode*prev;
    public:
    doubleNode(int data){
        this->data=data;
        this->next=NULL;
        this->prev=NULL;
    }
};