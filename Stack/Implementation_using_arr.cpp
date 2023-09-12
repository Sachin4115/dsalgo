#include <iostream>
using namespace std;

#define N 5

class stack{

    int* arr;
    int top;

    public:

    stack(){
        arr=new int[N];
        top=-1;
    }

    void push(int val){
        if(top==N-1){
            cout<<"Stack_Overflow"<<endl;
            return;
        }
        arr[++top]=val;
    }

    void pop(){
        if(top==-1){
            cout<<"Stack_Underflow"<<endl;
            return;
        }
        top--;
    }

    int Top(){
        if(top==-1){
            cout<<"Stack_Underflow"<<endl;
            return INT_MIN;
        }
        return arr[top];
    }

    bool is_empty(){
        return top==-1;
    }

    int size(){
        return top+1;
    }

    bool is_full(){
        return top+1==N? 1 : 0;
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
    cout<<s1.is_full()<<endl;
    s1.push(6);
    s1.pop();
    s1.pop();
    s1.pop();
    s1.pop();
    s1.pop();
    s1.pop();
    return 0;
}