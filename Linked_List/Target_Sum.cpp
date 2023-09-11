#include <iostream>
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

vector <int> pairs(node* head,int tsum){
    if(head==NULL){
        vector<int> ans(2,-1);
        return ans;
    }
    node* temp=head;
    int sum = tsum-head->value;
    vector<int> ans(2,-1);
    while(temp->next){
        if(temp->next->value == sum){
            ans[0]=head->value;
            ans[1]=temp->next->value;
            return ans;
        }
        temp=temp->next;
    }
    return pairs(head->next,tsum);
}

vector <int> Tpairs(node* head, int sum,node* tail){
    node* left=head;
    node* right=tail;
    vector<int>ans(2,-1);
    while(left!=right){
        if(left->value+right->value==sum){
            ans[0]=left->value;
            ans[1]=right->value;
            return ans;
        }
        while(left->value+right->value>sum)
            right=right->prev;
        while(left->value+right->value<sum)
            left=left->next;
    }
    return ans;
}

int main()
{
    doublyLL dll;
    for(int i=1;i<=10;i++)
        dll.insertAtTail(i);
    dll.display();
    vector <int> arr = pairs(dll.head,15);
    cout<<"["<<arr[0]<<","<<arr[1]<<"]"<<endl;
    vector <int> ans = Tpairs(dll.head,15,dll.tail);
    cout<<"["<<ans[0]<<","<<ans[1]<<"]"<<endl;
    return 0;
}