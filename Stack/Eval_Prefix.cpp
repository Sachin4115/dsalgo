#include <iostream>
#include <stack>
#include <string>
#include <cmath>
using namespace std;

int cal(int a,int b, char op){
    if(op=='+')
        return a+b;
    else if(op=='-')
        return a-b;
    else if(op=='*')
        return a*b;
    else if(op=='/')
        return a/b;
    else
        return pow(a,b);
}

int eval(string s){
    stack <int> st;
    for(int i=s.length()-1;i>=0;i--){
        if(isdigit(s[i])){
            st.push(s[i]-'0');
        }
        else{
            int a=st.top();
            st.pop();
            int b=st.top();
            st.pop();
            st.push(cal(b,a,s[i]));
        }
    }
    return st.top();
}
int main()
{
    cout<<eval("-9+*531");
    return 0;
}