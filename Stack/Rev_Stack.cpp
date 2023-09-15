#include <iostream>
#include <stack>
using namespace std;
void insertAtB(stack<int> &st,int ele){
    if(st.empty()){
        st.push(ele);
        return;
    }
    int t=st.top();
    st.pop();
    insertAtB(st,ele);
    st.push(t);
}
void rev(stack<int> &st){
    if(st.empty())
        return;
    int t=st.top();
    st.pop();
    rev(st);
    insertAtB(st,t);
}

int main()
{
    stack<int> st;
    st.push(1);
    st.push(2);
    st.push(3);
    st.push(4);
    rev(st);
    while(!st.empty()){
        cout<<st.top()<<endl;
        st.pop();
    }
    return 0;
}