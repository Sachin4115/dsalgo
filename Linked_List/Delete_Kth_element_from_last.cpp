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

node* deleteK(node* head,int k){
    node* p1=head;
    node* p2=head;
    while(k--){
        p2=p2->next;
    }
    if(p2==NULL){
        node* temp=head;
        head=head->next;
        free(temp);
        return head;
    }
    while(p2->next){
        p1=p1->next;
        p2=p2->next;
    }
    node* temp=p1->next;
    p1->next=p1->next->next;
    free(temp);
    return head;
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
    head=deleteK(head,6);
    display(head);
    return 0;
}