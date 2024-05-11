#include <iostream>
#include <queue>
using namespace std;

class CustomStack{

    queue <int> mainQueue;
    queue <int> helperQueue;

    public:
    void push(int val){

        while(mainQueue.size()>0){
            helperQueue.push(mainQueue.front());
            mainQueue.pop();
        }
        mainQueue.push(val);
        while(helperQueue.size()>0){
            mainQueue.push(helperQueue.front());
            helperQueue.pop();
        }

    }

    int top(){
        return mainQueue.front();
    }

    int pop(){
        int p = mainQueue.front();
        mainQueue.pop();
        return p;
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