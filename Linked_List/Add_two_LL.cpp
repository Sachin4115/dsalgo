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

    int addHelper(node* head1,int p1,node*head2,int p2,node* &head3){
        if(head1==NULL && head2==NULL){
            return 0;
        }
        int d=0;
        if(p1>p2){
            int c = addHelper(head1->next,p1-1,head2,p2,head3);
            data = c + head1->data;
        }
        else if(p2>p1){
            int c = addHelper(head1,p1,head2->next,p2-1,head3);
            data = c + head2->data;
        }
        else{
            int c = addHelper(head1->next,p1-1,head2->next,p2-1,head3);
            data = c + head1->data + head2->data;
        }
        insertAtHead(head3,data%10);
        return data/10;
    }

    node* addLL(node* head1,node* head2){
        node* head3=NULL;
        int c = addHelper(head1,size(head1),head2,size(head2),head3);
        if(c>0){
            insertAtHead(head3,c);
        }
        return head3;
    }

};
int main()
{
    node n = node();
    node* head1 = NULL;
    node* head2 = NULL;
    n.insertAtTail(head1,9);
    n.insertAtTail(head1,9);
    n.insertAtTail(head1,9);

    n.insertAtHead(head2,1);
    n.insertAtHead(head2,1);
    n.insertAtHead(head2,1);
    n.insertAtHead(head2,1);

    node* head3 = n.addLL(head1,head2);

    node*temp=head3;
    while(temp){
        cout<<temp->data<<" ";
        temp=temp->next;
    }

    return 0;
}