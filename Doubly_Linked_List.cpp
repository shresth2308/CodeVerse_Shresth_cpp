#include <iostream>
using namespace std;
class Node{
    public:
    int data;
    Node* prev;
    Node* next;
   
    Node(int d){
        data=d;
        prev=NULL;
        next=NULL;
    }
   
    ~Node(){
        int val=this->data;
        if(next==NULL){
            delete next;
            next=NULL;
        }
        cout<<"Memory free: "<<val<<endl;
    }
   
};

void printLL(Node* &head){
    Node* temp=head;
    while(temp!=NULL){
        cout<<temp->data<<" ";
        temp=temp->next;
    }
    cout<<endl;
}

void insertAtHead(Node* &head, Node* &tail, int d){
    if(head==NULL){
        Node* temp=new Node (d);
        head=temp;
        tail=temp;
    }
    else{
        Node* temp=new Node(d);
        temp->next=head;
        head->prev=temp;
        head=temp;
    }
}

void insertAtTail(Node* &head, Node* &tail, int d){
    if(head==NULL){
        Node* temp=new Node (d);
        head=temp;
        tail=temp;
    }
    else{
        Node* temp= new Node(d);
        tail->next=temp;
        temp->prev=tail;
        tail=temp;
    }
}

void insertAtPosition(Node* &head, Node* &tail,int position, int d){
    if(position==1){
        insertAtHead(head,tail,d);
        return;
    }
    Node* temp=head;
    int cnt=1;
    while(cnt<position-1){
        temp=temp->next;
        cnt++;
    }
    if(temp->next==NULL){
        insertAtTail(head,tail,d);
        return;
    }
    Node* nodetoinsert=new Node(d);
    nodetoinsert->next=temp->next;
    temp->next->prev=nodetoinsert;
    temp->next=nodetoinsert;
    nodetoinsert->prev=temp;
}

void deleteNode(Node* &head, Node* &tail,int position){
    if(position==1){
        Node* temp=head;
        head=temp->next;
        temp->next->prev=NULL;
        temp->next=NULL;
        delete temp;
    }
    else{
        Node* curr=head;
        Node* temp=NULL;
        int cnt=1;
        while(cnt<position){
            temp=curr;
            curr=curr->next;
            cnt++;
        }
        if(curr->next==NULL){
            curr->prev=NULL;
            temp->next=NULL;
            tail=temp;
            delete curr;
           
        }
        else{
            temp->next=curr->next;
            curr->next->prev=temp;
            curr->next=NULL;
            delete curr;
        }
    }
}

int main() {
    Node* head=NULL;
    Node* tail=NULL;
    insertAtHead(head,tail,10);
    printLL(head);
    insertAtTail(head,tail,20);
    printLL(head);
    insertAtPosition(head,tail,1,5);
    printLL(head);
    insertAtPosition(head,tail,3,15);
    printLL(head);
    insertAtPosition(head,tail,5,25);
    printLL(head);
    deleteNode(head,tail,1);
    deleteNode(head,tail,4);
    deleteNode(head,tail,2);
    printLL(head);
    cout<<"Head: "<<head->data<<endl;
    cout<<"Tail: "<<tail->data<<endl;
    return 0;
}