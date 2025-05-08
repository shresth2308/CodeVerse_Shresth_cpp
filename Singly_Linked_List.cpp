#include<iostream>
#include<bits/stdc++.h>
using namespace std;
class Node{
    public:
    int data;
    Node* next;
    
    Node(int d){
        data=d;
        next=NULL;
    }

    ~Node(){
        int value=this->data;
        if(next!=NULL){
            delete next;
            next=NULL;
        }
        cout<<"Memory freed for node with data: "<<value<<endl;
    }
};

void InsertAtHead(Node* &head, Node* &tail, int d){
    if(head==NULL){
        Node* temp=new Node(d);
        head=temp;
        tail=temp;
        return;
    }
    else{
        Node* temp=new Node(d);
        temp->next=head;
        head=temp;
    }
}

void InsertAtTail(Node* &head, Node* &tail,int d){
    if(tail==NULL){
        Node* temp=new Node(d);
        head=temp;
        tail=temp;
    }
    else{
        Node* temp=new Node(d);
        temp->next=NULL;
        tail->next=temp;
        tail=temp;
    }
}

void InsertAtMiddle(Node* &head, Node* &tail, int position,int d){
    Node* temp=head;
    int i=1;
    if(position==1){
        InsertAtHead(head,tail,d);
        return;
    }
    while(i<position-1){
        temp=temp->next;
        i++;
    }
    if(temp->next==NULL){
        InsertAtTail(head,tail,d);
        return;
    }
    Node* NodeToInsert= new Node (d);
    NodeToInsert->next=temp->next;
    temp->next=NodeToInsert;
}

void printLL(Node* &head){
    Node* temp=head;
    while(temp!=NULL){
        cout<<temp->data<<" ";
        temp=temp->next;
    }
    cout<<endl;
}

void DeleteNode(Node* &head, Node* &tail, int position){
    if(position==1){
        Node* temp=head;
        head=head->next;
        temp->next=NULL;
        delete temp;
        return;
    }
    else{
        Node* temp=NULL;
        Node* curr=head;
        int i=1;
        while(i<position){
        temp=curr;
        curr=curr->next;
        i++;
        }
        if(curr->next==NULL){
            tail=temp;
        }
        temp->next=curr->next;
        curr->next=NULL;
        delete curr;
    }
}

int main(){
    Node* head=NULL;
    Node* tail=NULL;
    InsertAtHead(head,tail,12);
    InsertAtTail(head,tail,15);
    InsertAtMiddle(head,tail,3,14);
    InsertAtMiddle(head,tail,2,19);
    InsertAtMiddle(head,tail,1,5);
    printLL(head);
    cout<<"Head: "<<head->data<<endl;
    cout<<"Tail: "<<tail->data<<endl;
    DeleteNode(head,tail,5);
    printLL(head);
    cout<<"Head: "<<head->data<<endl;
    cout<<"Tail: "<<tail->data<<endl;
    DeleteNode(head,tail,2);
    printLL(head);
    cout<<"Head: "<<head->data<<endl;
    cout<<"Tail: "<<tail->data<<endl;
    DeleteNode(head,tail,1);
    printLL(head);
    cout<<"Head: "<<head->data<<endl;
    cout<<"Tail: "<<tail->data<<endl;
}