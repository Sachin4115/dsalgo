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

int length(node* head,int i){
    if(head==NULL)
        return i;
    return length(head->next,i+1);
}

node* rotateK(node* head,int k){
    if(k==0)
        return head;
        node* temp=head;
    while(temp->next)
        temp=temp->next;
    temp->next=head;
    node* temp2=head->next;
    head->next=NULL;
    rotateK(temp2,k-1);
}

int main()
{
    node*head=NULL;
    for(int i=1;i<11;i++)
        insertAtTail(head,i);
    display(head);
    int k=3;
    int n=length(head,0);
    display(rotateK(head,k%n));
    return 0;
}