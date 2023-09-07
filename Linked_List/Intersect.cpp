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

node* intersect(node* head1,node* head2,int l1,int l2){
    int l;
    if(l1<l2){
        l=l2-l1;
        while(l--){
            head2=head2->next;
        }
        l=l2-l1;
    }
    else{
        l=l1-l2;
        while(l--){
            head1=head1->next;
        }
        l=l1-l2;
    }
    while(head1 && head2){
        if(head1==head2){
            return head1;
        }
        head1=head1->next;
        head2=head2->next;
    }
    return NULL;
}

int main()
{
    node*head1=NULL;
    insertAtTail(head1,1);
    insertAtTail(head1,2);
    insertAtTail(head1,3);
    insertAtTail(head1,4);
    insertAtTail(head1,5);
    node*head2=NULL;
    insertAtTail(head2,6);
    insertAtTail(head2,7);

    head2->next->next=head1->next->next->next;
    cout<<intersect(head1,head2,length(head1,0),length(head2,0))->data<<endl;
    // display(head1);
    // cout<<length(head1,0)<<endl;
    // display(head2);
    // cout<<length(head2,0)<<endl;
    return 0;
}