#include <iostream>
#include <stack>
using namespace std;

class MinStack{
    public:
    stack<long long int> st;
    long long int mn;
    MinStack(){
        mn=INT_MAX;
    }
    void push(long long int val){
        if(st.empty()){
            st.push(val);
            mn=val;
        }
        else{
            st.push(val-mn);
            mn=min(val,mn);
        }
    }
    void pop(){
        if(st.empty())
            return;
        if(st.top()>=0){
            st.pop();
        }
        else{
            mn=mn-st.top();
            st.pop();
        }
    }
    long long int top(){
        if(!st.empty()){
            if(st.size()==1){
                return st.top();
            }
            else if(st.top()>=0){
                return mn+st.top();
            }
            else{
                return mn;
            }
        }
    }
    long long int getMin(){
        return mn;
    }
};

int main()
{
    MinStack m;
    m.push(1);
    m.push(2);
    m.push(-8);
    m.push(3);
    cout<<m.getMin()<<endl;
    cout<<m.top()<<endl;
    m.pop();
    cout<<m.getMin()<<endl;
    cout<<m.top()<<endl;
    m.pop();
    cout<<m.getMin()<<endl;
    cout<<m.top()<<endl;
    m.pop();
    cout<<m.getMin()<<endl;
    cout<<m.top()<<endl;
    return 0;
}