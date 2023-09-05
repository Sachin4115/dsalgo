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

void display(node* head){
    node* temp=head;
    while(temp!=NULL){
        cout<<temp->value<<"->";
        temp=temp->next;
    }
    cout<<"NULL"<<endl;
}

void deleteAtStart(node* &head){
    node* temp=head;
    head=head->next;
    free(temp);
}

void deleteAtEnd(node* &head){
    node* temp1=head;
    node* temp2=head;
    while(temp2->next->next!=NULL){
        temp2=temp2->next;
    }
    temp1=temp2->next;
    free(temp1);
    temp2->next=NULL;
}

void deleteAtPosition(node* &head,int pos){
    if(pos==0){
        deleteAtStart(head);
        return;
    }
    node* temp=head;
    int curr_pos=0;
    while(curr_pos!=pos-1){
        temp=temp->next;
        curr_pos++;
    }
    node* temp2=temp->next;
    temp->next=temp->next->next;
    free(temp2);
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
    deleteAtStart(head);
    display(head);
    deleteAtEnd(head);
    display(head);
    deleteAtPosition(head,1);
    display(head);
    return 0;
}