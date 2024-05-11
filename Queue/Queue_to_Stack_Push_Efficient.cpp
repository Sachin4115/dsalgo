#include <iostream>
#include <queue>
using namespace std;

class CustomStack{

    queue <int> mainQueue;
    queue <int> helperQueue;

    public:
    void push(int val){
        mainQueue.push(val);
    }

    int top(){
        while(mainQueue.size()>1){
            helperQueue.push(mainQueue.front());
            mainQueue.pop();
        }
        int t = mainQueue.front();
        mainQueue.pop();
        while(helperQueue.size()>0){
            mainQueue.push(helperQueue.front());
            helperQueue.pop();
        }
        mainQueue.push(t);
        return t;

    }

    int pop(){
        while(mainQueue.size()>1){
            helperQueue.push(mainQueue.front());
            mainQueue.pop();
        }
        int t = mainQueue.front();
        mainQueue.pop();
        while(helperQueue.size()>0){
            mainQueue.push(helperQueue.front());
            helperQueue.pop();
        }
        return t;
    }

    int size(){
        return mainQueue.size();
    }

};

int main()
{
    CustomStack st = CustomStack();
    st.push(10);
    st.push(20);
    st.push(30);
    st.push(40);
    cout<<st.size()<<endl;
    cout<<st.top()<<endl;
    cout<<st.pop()<<endl;
    cout<<st.size()<<endl;
    cout<<st.pop()<<endl;
    cout<<st.pop()<<endl;
    cout<<st.pop()<<endl;

    return 0;
}