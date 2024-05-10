#include <iostream>
#include <vector>
using namespace std;

class CustomStack{
    int n=5;
    int top;
    int *arr = new int[n];

    public:
    CustomStack(){
        top=-1;
    }

    int Size(){
        return top+1;
    }

    void display(){
        if(top==-1){
            cout<<"[]";
        }
        for(int i=0;i<=top;i++){
            cout<<arr[i]<<" ";
        }
        cout<<endl;
    }

    void add(int s){
        if(top==n-1){
            cout<<"overflow"<<endl;
            return;
        }
        arr[++top]=s;
    }

    int remove(){
        if(top==-1){
            cout<<"underflow"<<endl;
            return -1;
        }
        top--;
        return arr[top+1];
    }

    int Top(){
        if(top==-1){
            cout<<"underflow"<<endl;
            return -1;
        }
        return arr[top];
    }

};

int main()
{
    vector<CustomStack> v;
    for(int i=0;i<10;i++){
        v.push_back(CustomStack());
    }
    v[0].display();
    cout<<v[0].Top()<<endl;
    cout<<v[0].Size()<<endl;
    v[0].add(10);
    v[0].add(20);
    v[0].add(30);
    v[0].add(40);
    v[0].add(50);
    cout<<v[0].remove()<<endl;
    cout<<v[0].remove()<<endl;
    v[0].add(60);
    v[0].add(70);
    v[0].display();
    cout<<v[0].Size()<<endl;
    cout<<v[0].remove()<<endl;
    cout<<v[0].Size()<<endl;
    // cout<<v[0].remove()<<endl;
    // cout<<v[0].remove()<<endl;
    // cout<<v[0].remove()<<endl;
    // cout<<v[0].remove()<<endl;
    // cout<<v[0].remove()<<endl;

    cout<<"----------------------------"<<endl;

    v[1].display();
    cout<<v[1].Top()<<endl;
    cout<<v[1].Size()<<endl;
    v[1].add(1);
    v[1].add(2);
    v[1].add(3);
    v[1].add(4);
    v[1].add(5);
    cout<<v[1].remove()<<endl;
    cout<<v[1].remove()<<endl;
    v[1].add(6);
    v[1].add(7);
    v[1].display();
    cout<<v[1].Size()<<endl;
    cout<<v[1].remove()<<endl;
    cout<<v[1].Size()<<endl;
    // cout<<v[1].remove()<<endl;
    // cout<<v[1].remove()<<endl;
    // cout<<v[1].remove()<<endl;
    // cout<<v[1].remove()<<endl;
    // cout<<v[1].remove()<<endl;

    cout<<"----------------------------"<<endl;

    v[0].display();
    v[1].display();

    return 0;
}