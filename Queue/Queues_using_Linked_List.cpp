#include <iostream>
using namespace std;

class node{
    public:
    int data;
    node* next;
    node(int val){
        data=val;
        next=NULL;
    }
};

class CustomQueue{
    node* head;
    int maxSize;
    int front;
    int size;

    public:
    CustomQueue(){
        maxSize=5;
        front=0;
        size=0;
        head=NULL;
    }

    int Size(){
        return size-front;
    }

    void display(){
        if(size==front){
            cout<<"[]"<<endl;
            return;
        }
        node* t = head;
        while(t){
            cout<<t->data<<" ";
            t=t->next;
        }
        cout<<endl;
    }

    void add(int val){
        if(size-front==maxSize){
            cout<<"Overflow"<<endl;
            return;
        }
        node* newNode = new node(val);
        if(head==NULL){
            head=newNode;
            size++;
            return;
        }
        node* t = head;
        while(t->next!=NULL){
            t=t->next;
        }
        t->next=newNode;
        size++;
    }

    int remove(){
        if(size==front){
            cout<<"Underflow"<<endl;
            return -1;
        }
        node* t = head;
        head=head->next;
        int r = t->data;
        front++;
        free(t);
        return r;
    }

    int peek(){
        if(front==size){
            cout<<"Underflow"<<endl;
            return -1;
        }
        return head->data;
    }

};

int main()
{
    CustomQueue q = CustomQueue();
    q.display();
    cout<<q.peek()<<endl;
    cout<<q.Size()<<endl;
    q.add(10);
    q.add(20);
    q.add(30);
    q.add(40);
    q.add(50);
    cout<<q.remove()<<endl;
    cout<<q.remove()<<endl;
    q.add(60);
    q.add(70);
    q.display();
    cout<<q.Size()<<endl;
    cout<<q.remove()<<endl;
    cout<<q.Size()<<endl;
    cout<<q.remove()<<endl;
    cout<<q.remove()<<endl;
    cout<<q.remove()<<endl;
    cout<<q.remove()<<endl;
    cout<<q.remove()<<endl;
    return 0;
}