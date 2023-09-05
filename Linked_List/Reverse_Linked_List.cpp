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

node* reverse(node* &head){
    node* pre=NULL;
    node* curr=head;
    while(curr!=NULL){
        node* temp=curr->next;
        curr->next=pre;
        pre=curr;
        curr=temp;
    }
    return pre;
}

node* Reverse(node* &head){
    if(head==NULL||head->next==NULL)
        return head;
    node* newhead = reverse(head->next);
    head->next->next=head;
    head->next=NULL;
    return newhead;
}

node* Kreverse(node* &head,int k){
    int i=0;
    node* pre=NULL;
    node* curr=head;
    while(curr!=NULL && i!=k){
        node* temp=curr->next;
        curr->next=pre;
        pre=curr;
        curr=temp;
        i++;
    }
    if(curr!=NULL)
        head->next=Kreverse(curr,k);
    return pre;
}

int main()
{
    node*head=NULL;
    for(int i=1;i<11;i++){
        insertAtTail(head,i);
    }
    display(head);
    head=reverse(head);
    display(head);
    head=Reverse(head);
    display(head);
    head=Kreverse(head,2);
    display(head);
    return 0;
}