#include <iostream>
#include <algorithm>
#include <stack>
using namespace std;

int precedence(char op){
    if(op=='^') return 3;
    else if(op=='*' || op=='/') return 2;
    else if(op=='+' || op=='-') return 1;
    else return -1;
}

string convert(string s){
    stack <char> st;
    reverse(s.begin(),s.end());
    string ans="";
    for(int i=0;i<s.length();i++){
        if((s[i]>='a' && s[i]<='z') || (s[i]>='A' && s[i]<='Z')){
            ans+=s[i];
        }
        else if(s[i]==')'){
            st.push(')');
        }
        else if(s[i]=='('){
            while(!st.empty() && st.top()!=')'){
                ans+=st.top();
                st.pop();
            }
            if(!st.empty())
            st.pop();
        }
        else{
            while(!st.empty() && precedence(st.top())>=precedence(s[i])){
                ans+=st.top();
                st.pop();
            }
            st.push(s[i]);
        }
    }
    while(!st.empty()){
        ans+=st.top();
        st.pop();
    }
    reverse(ans.begin(),ans.end());
    return ans;
}

int main()
{
    cout<<convert("a*(b-c)/d+e");
    return 0;
}