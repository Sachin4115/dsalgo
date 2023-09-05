// Replace the value at a given position

#include <iostream>
using namespace std;

class node{
    public:
    int value;
    node* next;

    node(int val){
        value=val;
        next=NULL;
    }
};

void insertAtTail(node* &head,int val){
    node* new_node=new node(val);
    if(head==NULL){
        head=new_node;
        return;
    }
    node* temp=head;
    while(temp->next!=NULL){
        temp=temp->next;
    }
    temp->next=new_node;
}

void replace(node* head, int val, int pos){
    node* temp=head;
    int curr_pos=0;
    while(curr_pos!=pos){
        temp=temp->next;
        curr_pos++;
    }
    temp->value=val;
}

void display(node* head){
    node* temp=head;
    while(temp!=NULL){
        cout<<temp->value<<"->";
        temp=temp->next;
    }
    cout<<"NULL"<<endl;
}

int main()
{
    node* head=NULL;
    insertAtTail(head,1);
    insertAtTail(head,2);
    insertAtTail(head,3);
    insertAtTail(head,4);
    insertAtTail(head,5);
    display(head);
    replace(head,10,2);
    display(head);
    return 0;
}