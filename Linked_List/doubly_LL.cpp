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
};

int main()
{
    node* new_node=new node(3);
    doublyLL dll;
    dll.head=new_node;
    dll.tail=new_node;
    cout<<dll.head->value<<endl;
    return 0;
}