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

bool compare(node* head1,node* head2){
    while(head1!=NULL && head2!=NULL){
        if(head1->data!=head2->data)
            return 0;
        head1=head1->next;
        head2=head2->next;
    }
    return (head1==NULL && head2==NULL);
}

int main()
{
    node*head1=NULL;
    for(int i=1;i<11;i++){
        insertAtTail(head1,i);
    }
    node*head2=NULL;
    for(int i=1;i<11;i++){
        insertAtTail(head2,i);
    }
    cout<<compare(head1,head2);
    return 0;
}