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

node* merge(node* head1, node* head2){
    node* dhead=NULL;
    insertAtTail(dhead,0);
    node* p1=head1;
    node* p2=head2;
    node* p3=dhead;
    while(p1 && p2){
        if(p1->data>p2->data){
            p3->next=p2;
            p2=p2->next;
        }
        else{
            p3->next=p1;
            p1=p1->next;
        }
        p3=p3->next;
    }
    while(p1){
        p3->next=p1;
        p1=p1->next;
        p3=p3->next;
    }
    while(p2){
        p3->next=p2;
        p2=p2->next;
        p3=p3->next;
    }
    p3=dhead->next;
    free(dhead);
    return p3;
}

int main()
{
    node*head1=NULL;
    insertAtTail(head1,1);
    insertAtTail(head1,3);
    insertAtTail(head1,5);
    display(head1);
    node*head2=NULL;
    insertAtTail(head2,2);
    insertAtTail(head2,4);
    display(head2);
    display(merge(head1,head2));
    return 0;
}