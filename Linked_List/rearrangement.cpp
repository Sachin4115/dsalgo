#include <iostream>
using namespace std;

class node{
    public:
    int data;
    node* next;

    node(int value){
        data=value;
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

void display(node* head){
    node* temp=head;
    while(temp!=NULL){
        cout<<temp->data<<"->";
        temp=temp->next;
    }
    cout<<"NULL"<<endl;
}

void rer(node* head){
    if(head==NULL || head->next==NULL || head->next->next==NULL)
        return;
    node* temp1=head;
    while(temp1->next->next){
        temp1=temp1->next;
    }
    node*temp2=head->next;
    head->next=temp1->next;
    temp1->next->next=temp2;
    temp1->next=NULL;
    rer(temp2);
}

int main()
{
    node*head=NULL;
    insertAtTail(head,1);
    insertAtTail(head,2);
    insertAtTail(head,3);
    insertAtTail(head,4);
    insertAtTail(head,5);
    insertAtTail(head,6);
    display(head);
    rer(head);
    display(head);
    return 0;
}