#include <iostream>
#include <stack>
using namespace std;

void deleteAtB(stack<int> &st){
    if(st.size()==1){
        st.pop();
        return;
    }
    int t=st.top();
    st.pop();
    deleteAtB(st);
    st.push(t);
}
void deleteAtN(stack<int> &st,int n){
    if(n==st.size()){
        st.pop();
        return;
    }
    else{
        int t=st.top();
        st.pop();
        deleteAtN(st,n);
        st.push(t);
    }
}

int main()
{
    stack <int> st;
    st.push(1);
    st.push(6);
    st.push(2);
    st.push(3);
    st.push(4);
    st.push(5);
    // while(!st.empty()){
    //     cout<<st.top()<<endl;
    //     st.pop();
    // }
    // deleteAtB(st);
    // while(!st.empty()){
    //     cout<<st.top()<<endl;
    //     st.pop();
    // }
    deleteAtN(st,2);
    while(!st.empty()){
        cout<<st.top()<<endl;
        st.pop();
    }
    return 0;
}