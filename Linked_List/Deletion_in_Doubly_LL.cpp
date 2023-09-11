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
        }
    }

    void deleteAtKth(int k){
        node* temp=head;
        while(k-1!=1){
            temp=temp->next;
            k--;
        }
        node* temp2=temp->next;
        temp->next=temp->next->next;
        temp->next->prev=temp;
        free(temp2);
    }
};

int main()
{
    doublyLL dll;
    for(int i=1;i<=5;i++)
        dll.insertAtTail(i);
    dll.display();
    cout<<endl;
    dll.insertAtTail(15);
    for(int i=6;i<=10;i++)
        dll.insertAtTail(i);
    dll.display();
    cout<<endl;
    dll.deleteAtKth(6);
    dll.display();
    return 0;
}