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

    void insertAtStart(int val){
        node* new_node=new node(val);
        if(head==NULL){
            head=new_node;
            tail=new_node;
            return;
        }
        new_node->next=head;
        head->prev=new_node;
        head=new_node;
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

    void insertAtKth(int val,int k){
        node* new_node=new node(val);
        if(k==1){
            insertAtStart(val);
            return;
        }
        node* temp=head;
        while(k-1!=1){
            temp=temp->next;
            k--;
        }
        new_node->next=temp->next;
        new_node->prev=temp;
        temp->next->prev=new_node;
        temp->next=new_node;
        return;
    }

    void display(){
        node* temp=head;
        while(temp){
            cout<<temp->value<<" ";
            temp=temp->next;
        }
    }
};

int main()
{
    doublyLL dll;
    dll.insertAtStart(3);
    dll.insertAtStart(2);
    dll.insertAtStart(1);
    dll.insertAtTail(5);
    dll.insertAtTail(6);
    dll.insertAtTail(8);
    dll.insertAtKth(4,4);
    dll.insertAtKth(7,7);
    dll.display();
    return 0;
}