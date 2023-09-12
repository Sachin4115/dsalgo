#include <iostream>
using namespace std;
#define N 6
class node{
    public:
    int data;
    node* next;
    node(int val){
        data=val;
        next=NULL;
    }
};

class stack{
    node* head;
    int count;
    int max_cap;
    public:
    stack(){
        count=-1;
        max_cap=N;
        head=NULL;
    }
    void push(int val){
        if(count==N-1){
            cout<<"stack_overflow"<<endl;
            return;
        }
        node* new_node = new node(val);
        new_node->next=head;
        head=new_node;
        count++;
    }

    void pop(){
        if(head==NULL){
            cout<<"Stack_Underflow"<<endl;
            return;
        }
        node* new_node=head->next;
        delete head;
        head=new_node;
        count--;
    }

    int size(){
        return count+1;
    }

    bool is_empty(){
        if(head)
            return 0;
        return 1;
    }

    int Top(){
        if(head==NULL){
            cout<<"Stack_Underflow"<<endl;
            return INT_MIN;
        }
        return head->data;
    }
    bool is_full(){
        if(count==N-1)
            return 1;
        return 0;
    }
};

int main()
{
    stack s1;
    s1.push(1);
    s1.push(2);
    s1.push(3);
    s1.pop();
    cout<<s1.is_empty()<<endl;
    cout<<s1.size()<<endl;
    cout<<s1.Top()<<endl;
    s1.push(3);
    s1.push(4);
    s1.push(5);
    s1.push(6);
    cout<<s1.is_full()<<endl;
    s1.push(7);
    s1.pop();
    s1.pop();
    s1.pop();
    s1.pop();
    s1.pop();
    s1.pop();
    s1.pop();
    cout<<s1.size()<<endl;
    return 0;
}