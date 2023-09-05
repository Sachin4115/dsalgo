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

void deleteAlternative(node* head){
    if(head==NULL||head->next==NULL)
        return;
    node* temp1=head;
    node* temp2=head->next;
    temp1->next=temp2->next;
    free(temp2);
    deleteAlternative(temp1->next);
}

int main()
{
    node*head=NULL;
    for(int i=1;i<11;i++){
        insertAtTail(head,i);
    }
    display(head);
    deleteAlternative(head);
    display(head);
    return 0;
}