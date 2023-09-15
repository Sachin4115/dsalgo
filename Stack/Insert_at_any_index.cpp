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
void insert(stack<int> &st,int n,int ele){
    if(n==st.size()){
        st.push(ele);
        return;
    }
    else{
        int t=st.top();
        st.pop();
        insert(st,n,ele);
        st.push(t);
    }
}

int main()
{
    stack <int> st;
    st.push(1);
    st.push(2);
    st.push(4);
    st.push(5);
    // while(!st.empty()){
    //     cout<<st.top()<<endl;
    //     st.pop();
    // }
    insertAtB(st,3);
    while(!st.empty()){
        cout<<st.top()<<endl;
        st.pop();
    }
    // insert(st,2,3);
    // while(!st.empty()){
    //     cout<<st.top()<<endl;
    //     st.pop();
    // }
    return 0;
}