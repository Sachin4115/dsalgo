#include <iostream>
#include <stack>
using namespace std;

class CustomQueue{

    stack<int> mainStack;
    stack<int> helperStack;

    public:

    void push(int val){
        mainStack.push(val);
    }

    int pop(){
        while(mainStack.size()>1){
            helperStack.push(mainStack.top());
            mainStack.pop();
        }
        int t=mainStack.top();
        mainStack.pop();
        while(helperStack.size()>0){
            mainStack.push(helperStack.top());
            helperStack.pop();
        }
        return t;
    }

    int top(){
        while(mainStack.size()>1){
            helperStack.push(mainStack.top());
            mainStack.pop();
        }
        int t=mainStack.top();
        while(helperStack.size()>0){
            mainStack.push(helperStack.top());
            helperStack.pop();
        }
        return t;
    }

    int size(){
        return mainStack.size();
    }

};

int main()
{
    CustomQueue q = CustomQueue();
    q.push(10);
    q.push(20);
    q.push(30);
    q.push(40);
    cout<<q.size()<<endl;
    cout<<q.top()<<endl;
    cout<<q.pop()<<endl;
    cout<<q.size()<<endl;
    cout<<q.pop()<<endl;
    cout<<q.pop()<<endl;
    cout<<q.pop()<<endl;
    return 0;
}