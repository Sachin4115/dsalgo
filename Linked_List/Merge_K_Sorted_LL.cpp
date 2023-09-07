#include <iostream>
#include <vector>
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

node* mergeK(vector< node* > &list){
    while(list.size()>1){
        node* m=merge(list[0],list[1]);
        list.push_back(m);
        list.erase(list.begin());
        list.erase(list.begin());
    }
    return list[0];
}

int main()
{
    node*head1=NULL;
    insertAtTail(head1,1);
    insertAtTail(head1,3);
    insertAtTail(head1,8);
    display(head1);
    node*head2=NULL;
    insertAtTail(head2,2);
    insertAtTail(head2,6);
    display(head2);
    node*head3=NULL;
    insertAtTail(head3,4);
    insertAtTail(head3,5);
    insertAtTail(head3,7);
    insertAtTail(head3,11);
    display(head3);
    node*head4=NULL;
    insertAtTail(head4,9);
    insertAtTail(head4,10);
    insertAtTail(head4,12);
    insertAtTail(head4,14);
    display(head4);
    node*head5=NULL;
    insertAtTail(head5,13);
    display(head5);
    vector <node*> arr = {head1,head2,head3,head4,head5};
    display(mergeK(arr));
    return 0;
}