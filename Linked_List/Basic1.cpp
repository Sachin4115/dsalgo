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

void insertAtHead(node* &head,int val){
    node* new_node=new node(val);
    new_node->next=head;
    head=new_node;
}

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

void insertAtPosition(node* &head,int val,int pos){
    if(pos==0){
        insertAtHead(head,val);
        return;
    }
    node* new_node= new node(val);
    node* temp = head;
    int cur_pos=0;
    while(cur_pos!=pos-1){
        temp=temp->next;
        cur_pos++;
    }
    new_node->next=temp->next;
    temp->next=new_node;

}

bool search(node* head, int key){
    node* temp=head;
    while(temp!=NULL){
        if(temp->data==key)
            return true;
        temp=temp->next;
    }
    return false;
}

void display(node* head){
    node* temp=head;
    while(temp!=NULL){
        cout<<temp->data<<"->";
        temp=temp->next;
    }
    cout<<"NULL"<<endl;
}

int main()
{
    node*head=NULL;
    cout<<search(head,2)<<endl;
    insertAtTail(head,1);
    insertAtTail(head,2);
    insertAtTail(head,3);
    display(head);
    insertAtHead(head,4);
    display(head);
    cout<<search(head,2)<<endl;
    insertAtPosition(head,5,2);
    display(head);
    return 0;
}