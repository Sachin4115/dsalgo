#include <iostream>
using namespace std;

class CustomQueue{


    int n=5;
    int front;
    int size;
    int *arr = new int[n];

    public:
    CustomQueue(){
        front=0;
        size=0;
    }

    int Size(){
        return size-front;
    }

    void display(){
        if(size==front){
            cout<<"[]";
        }
        for(int i=front;i<size;i++){
            cout<<arr[i%n]<<" ";
        }
        cout<<endl;
    }

    void add(int q){
        if(size-front==n){
            cout<<"overflow"<<endl;
            return;
        }
        arr[size%n]=q;
        size++;
    }

    int remove(){
        if(size==front){
            cout<<"underflow"<<endl;
            return -1;
        }
        front++;
        return arr[(front-1)%n];
    }

    int peek(){
        if(front==size){
            cout<<"underflow"<<endl;
            return -1;
        }
        return arr[front%n];
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