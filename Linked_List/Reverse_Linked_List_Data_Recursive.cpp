#include <iostream>
using namespace std;

class node{

    public:
    int data;
    node* next;
    node*left;

    node(){
    }
    
    node(int val){
        data=val;
        next=NULL;
    }

    void insertAtHead(node* &head, int val){
        node* newHead = new node(val);
        newHead->next=head;
        head=newHead;
    }

    void insertAtTail(node* &head, int val){
        node* newNode = new node(val);
        if(head==NULL){
            head=newNode;
            return;
        }
        node* temp=head;
        while(temp->next!=NULL){
            temp=temp->next;
        }
        temp->next=newNode;
    }

    int size(node * head){
        int s=0;
        node*temp=head;
        while(temp!=NULL){
            temp=temp->next;
            s++;
        }
        return s;
    }

    void reverseLLHelper(node* &right,int floor,int size){
        if(right==NULL){
            return;
        }
        reverseLLHelper(right->next,floor+1,size);
        if(floor>=size/2){
            int t=right->data;
            right->data=left->data;
            left->data=t;
            left=left->next;
        }
    }

    void reverseLL(node* &head){
        reverseLLHelper(head,0,size(head));
    }
};
int main()
{
    node n = node();
    node* head = NULL;
    n.insertAtHead(head,10);
    n.insertAtTail(head,20);
    n.insertAtTail(head,30);
    n.insertAtTail(head,40);
    n.insertAtTail(head,50);
    n.insertAtTail(head,60);
    n.insertAtTail(head,70);

    node* temp = head;
    while(temp!=NULL){
        cout<<temp->data<<" ";
        temp=temp->next;
    }
    cout<<endl;
    n.left=head;
    n.reverseLL(head);
    temp=head;
    while(temp!=NULL){
        cout<<temp->data<<" ";
        temp=temp->next;
    }
    cout<<endl;

    return 0;
}