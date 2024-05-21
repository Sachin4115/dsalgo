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

    void foldLLHelper(node* right,int floor,int size){
        if(right==NULL){
            return;
        }
        foldLLHelper(right->next,floor+1,size);
        if(floor>size/2){
            node*temp1=left->next;
            left->next=right;
            right->next=temp1;
            left=temp1;
        }else if(floor==(size/2)){
            right->next=NULL;
        }
    }

    void foldLL(node* &head){
        foldLLHelper(head,0,size(head));
    }
};
int main()
{
    node n = node();
    node* head = NULL;
    n.insertAtHead(head,0);
    n.insertAtTail(head,1);
    n.insertAtTail(head,2);
    n.insertAtTail(head,3);
    n.insertAtTail(head,4);
    n.insertAtTail(head,5);
    n.insertAtTail(head,6);

    node* temp = head;
    while(temp!=NULL){
        cout<<temp->data<<" ";
        temp=temp->next;
    }
    cout<<endl;
    n.left=head;
    n.foldLL(head);
    temp=head;
    while(temp!=NULL){
        cout<<temp->data<<" ";
        temp=temp->next;
    }
    cout<<endl;

    return 0;
}