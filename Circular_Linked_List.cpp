#include<iostream>
using namespace std;

class Node{
    public:
    int data;
    Node* next=NULL;
   
    Node(int d){
        data=d;
        next=NULL;
    }
   
    ~Node(){
        int val=this->data;
        if(next!=NULL){
            delete next;
            next-NULL;
        }
        cout<<"Deleted: "<<val<<endl;
    }
   
};

void printLL(Node* &tail){
    Node* temp=tail;
    if(tail==NULL){
        cout<<"List is empty"<<endl;
    }
    else{
        do{
            cout<<temp->data<<" ";
            temp=temp->next;
        }while(temp!=tail);
        cout<<endl;
    }
}

void insertNode(Node* &tail, int element, int d){
    if(tail==NULL){
        Node* temp=new Node(d);
        tail=temp;
        tail->next=temp;
    }
    else{
        Node* curr=tail;
        while(curr->data!=element){
            curr=curr->next;
        }
        Node* temp=new Node(d);
        temp->next=curr->next;
        curr->next=temp;
    }
}

void deleteNode(Node* &tail, int value){
    if(tail==NULL){
        cout<<"Empty List!";
    }
    else{
        Node* curr=tail->next;
        Node* prev=tail;
        while(curr->data!=value){
            prev=prev->next;
            curr=prev->next;
        }
        if(curr==prev){
            tail=NULL;
        }
        if(curr==tail){
            tail=prev;
        }
        prev->next=curr->next;
        curr->next=NULL;
        delete curr;
    }
}

int main(){
    Node* tail=NULL;
    insertNode(tail,5,3);
    insertNode(tail,3,6);
    insertNode(tail,6,9);
    insertNode(tail,9,12);
    insertNode(tail,12,15);
    printLL(tail);
    deleteNode(tail,3);
    printLL(tail);
    deleteNode(tail,15);
    printLL(tail);
    deleteNode(tail,9);
    printLL(tail);
}