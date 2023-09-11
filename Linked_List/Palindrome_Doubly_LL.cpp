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

bool palindrome(node* head,node* tail){
    if(head==tail || head->prev==tail){
        return 1;
    }
    if(head->value==tail->value)
        return palindrome(head->next,tail->prev);
    else
        return 0;
}

int main()
{
    doublyLL dll;
    for(int i=1;i<=5;i++)
        dll.insertAtTail(i);
    for(int i=6;i>=1;i--)
        dll.insertAtTail(i);
    dll.display();
    cout<<palindrome(dll.head,dll.tail);
    return 0;
}