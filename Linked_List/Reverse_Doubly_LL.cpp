#include <iostream>
using namespace std;

class node{
    public:
    int value;
    node* prev;
    node* next;
    node(int data){
        value=data;
        prev=NULL;
        next=NULL;
    }
};

class doublyLL{
    public:
    node* head;
    node* tail;
    doublyLL(){
        head=NULL;
        tail=NULL;
    }

    void insertAtTail(int val){
        node* new_node=new node(val);
        if(tail==NULL){
            head=new_node;
            tail=new_node;
            return;
        }
        tail->next=new_node;
        new_node->prev=tail;
        tail=new_node;
    }

    void display(){
        node* temp=head;
        while(temp){
            cout<<temp->value<<" ";
            temp=temp->next;
        }cout<<endl;
    }

    void reverse(){
        node* curr=head;
        node* curr_next;
        while(curr){
            curr_next=curr->next;
            curr->next=curr->prev;
            curr->prev=curr_next;
            curr=curr_next;
        }
        swap(head,tail);
    }
};

void Reverse(node* &head,node* &tail){
    node* curr=head;
    node* curr_next;
    while(curr){
        curr_next=curr->next;
        curr->next=curr->prev;
        curr->prev=curr_next;
        curr=curr_next;
    }
    swap(head,tail);
}

int main()
{
    doublyLL dll;
    for(int i=1;i<=10;i++)
        dll.insertAtTail(i);
    dll.display();
    dll.reverse();
    dll.display();
    Reverse(dll.head,dll.tail);
    dll.display();
    return 0;
}