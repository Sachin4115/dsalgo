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

node* middle(node* head){
    node* s=head;
    node* f=head;
    while(f && f->next){
        f=f->next->next;
        s=s->next;
    }
    return s;
}

bool isP(node* head){
    node* slow=middle(head);
    node* prev = slow;
    node* curr=slow->next;
    slow->next=NULL;
    while(curr){
        node* n=curr->next;
        curr->next=prev;
        prev=curr;
        curr=n;
    }

    node* p1=head;
    node* p2=prev;
    while(p2){
        if(p1->data != p2->data){
            return 0;
        }
        p2=p2->next;
        p1=p1->next;
    }
    return 1;
}

int main()
{
    node*head=NULL;
    insertAtTail(head,1);
    insertAtTail(head,2);
    insertAtTail(head,3);
    insertAtTail(head,2);
    insertAtTail(head,1);
    display(head);
    cout<<isP(head)<<endl;
    return 0;
}