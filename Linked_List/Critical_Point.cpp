// Return an array of length 2 containing [min distance, max distance]
// between any two distinct critical points.
// If less than 2 critical points exists return [-1,-1]
// Exclude first and the last node

#include <iostream>
#include <limits>
#include <vector>
using namespace std;

class node{
    public:
    int value;
    node* prev;
    node* next;
    node(int data){
        value=data;
        prev=NULL;
        next=NULL;
    }
};

class doublyLL{
    public:
    node* head;
    node* tail;
    doublyLL(){
        head=NULL;
        tail=NULL;
    }

    void insertAtTail(int val){
        node* new_node=new node(val);
        if(tail==NULL){
            head=new_node;
            tail=new_node;
            return;
        }
        tail->next=new_node;
        new_node->prev=tail;
        tail=new_node;
    }

    void display(){
        node* temp=head;
        while(temp){
            cout<<temp->value<<" ";
            temp=temp->next;
        }cout<<endl;
    }
};

void criticalPoint(node* tail){
    int arr[2]={INT_MAX,INT_MIN};
    int mcount=0;
    int Mcount=0;
    node* temp=tail->prev;
    while(temp->prev){
        if((temp->prev->value>temp->value && temp->next->value>temp->value) || (temp->prev->value<temp->value && temp->next->value<temp->value)){
            if(mcount!=0){
                arr[0]=min(arr[0],mcount);
                mcount=0;
            }
            mcount++;
            if(Mcount!=0){
                arr[1]=max(arr[1],Mcount);
            }
            Mcount++;
        }
        else{
            if(mcount!=0)
                mcount++;
            if(Mcount!=0)
                Mcount++;
        }
        temp=temp->prev;
    }
    if(arr[0]==INT_MAX){
        arr[0]=-1;
        arr[1]=-1;
    }
    cout<<"["<<arr[0]<<","<<arr[1]<<"]"<<endl;
}

vector<int> distance(node* tail){
    vector<int> ans(2,INT_MAX);
    int firstCP=-1, lastCP=-1;

    node* curr=tail->prev;
    if(curr==NULL){
        ans[0]=ans[1]=-1;
        return ans;
    }
    int cur_pos=0;
    while(curr->prev){
        if((curr->prev->value>curr->value && curr->next->value>curr->value) || (curr->prev->value<curr->value && curr->next->value<curr->value)){
            if(firstCP==-1){
                firstCP=lastCP=cur_pos;
            }
            else{
                ans[0]=min(ans[0],cur_pos-lastCP);
                ans[1]=cur_pos-firstCP;
                lastCP=cur_pos;
            }
            cur_pos++;
            curr=curr->prev;
        }
    }
    if(ans[0]==INT_MAX){
        ans[0]=ans[1]=-1;
    }
    return ans;
}

int main()
{
    doublyLL dll;
    dll.insertAtTail(1);
    dll.insertAtTail(5);
    dll.insertAtTail(4);
    dll.insertAtTail(2);
    dll.insertAtTail(6);
    dll.insertAtTail(3);
    dll.display();
    criticalPoint(dll.tail);
    vector <int> ans=distance(dll.tail);
    cout<<"["<<ans[0]<<","<<ans[1]<<"]"<<endl;
    return 0;
}