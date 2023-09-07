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

void createcycle(node* head,int k){
    node* temp=head;
    node* temp2;
    int curr=0;
    while(temp->next!=NULL){
        temp=temp->next;
        curr++;
        if(curr==k)
            temp2=temp;
    }
    temp->next=temp2;
}

bool detectcycle(node* head){
    node* slow=head;
    node* fast=head;
    while(fast->next!=NULL){
        fast=fast->next->next;
        slow=slow->next;
        if(fast->next==slow->next)
            return 1;
    }
    return 0;
}

void deletecycle(node* head){
    node* fast=head;
    node* slow=head;

    do{
        slow=slow->next;
        fast=fast->next->next;
    }while(fast!=slow);

    slow=head;

    while(fast->next!=slow->next){
        fast=fast->next;
        slow=slow->next;
    }
    fast->next=NULL;
}

int main()
{
    node*head=NULL;
    for(int i=1;i<10;i++)
        insertAtTail(head,i);
    cout<<detectcycle(head)<<endl;
    display(head);
    createcycle(head,3);
    cout<<detectcycle(head)<<endl;
    deletecycle(head);
    display(head);
    return 0;
}