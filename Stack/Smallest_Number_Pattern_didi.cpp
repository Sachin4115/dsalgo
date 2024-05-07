#include <iostream>
#include <stack>
using namespace std;

int main()
{
    string str = "diddiidi";
    stack <int> st;
    int n=1;
    for(int i=0;i<str.length();i++){
        if(str[i]=='d'){
            st.push(n);
            n++;
        }else{
            st.push(n);
            n++;
            while(!st.empty()){
                cout<<st.top();
                st.pop();
            }
        }
    }
    st.push(n);
    while(st.size()>=0){
        cout<<st.top();
        st.pop();
    }
    return 0;
}