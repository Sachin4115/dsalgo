// Delete  the nodes whose neighbors have the same vale.
// Traverse the list from right to left.

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
};

void deleteSN(node* tail){//Same Neighbors
    node* temp=tail->prev;
    while(temp->prev){
        if(temp->next->value==temp->prev->value){
            node* temp2=temp;
            temp=temp->prev;
            temp2->prev->next=temp2->next;
            temp2->next->prev=temp2->prev;
            free(temp2);
        }
        else
            temp=temp->prev;
    }
}

int main()
{
    doublyLL dll;
    dll.insertAtTail(2);
    dll.insertAtTail(1);
    dll.insertAtTail(1);
    dll.insertAtTail(2);
    dll.insertAtTail(1);
    dll.display();
    deleteSN(dll.tail);
    dll.display();
    return 0;
}