#include <iostream>
#include <stack>
using namespace std;

int sol(string s){
    stack<char>st;
    int i=0,ans=0;
    while(i<s.length()){
        while(i<s.length()&&s[i]!='k')
            st.push(s[i++]);
        if(i>=s.length())
            return -1;
        if(st.empty()||st.top()!='e')
            return -1;
        st.pop();
        if(st.empty()||st.top()!='e')
            return -1;
        st.pop();
        if(st.empty()||st.top()!='g')
            return -1;
        st.pop();
        ans++;
        i++;
    }
    if(!st.empty())
        return -1;
    return ans;
}

int main()
{
    string s="gegeekek";
    int a=sol(s);
    cout<<a;
    return 0;
}