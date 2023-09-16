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

int precedence(char op){
    if(op=='^') return 3;
    else if(op=='*' || op=='/') return 2;
    else if(op=='+' || op=='-') return 1;
    else return -1;
}

int eval(string s){
    stack <int> st1;
    stack <char> st2;
    for(int i=0;i<s.length();i++){
        if(isdigit(s[i])){
            st1.push(s[i]-'0');
        }
        else if(s[i]==')'){
            while(!st2.empty() && st2.top()!='('){
                int a=st1.top();
                st1.pop();
                int b=st1.top();
                st1.pop();
                st1.push(cal(b,a,st2.top()));
                st2.pop();
            }
            if(!st2.empty())
                st2.pop();
        }
        else if(s[i]=='(')
            st2.push('(');
        else{
            while(!st2.empty() && precedence(st2.top())>=precedence(s[i])){
                int a=st1.top();
                st1.pop();
                int b=st1.top();
                st1.pop();
                st1.push(cal(b,a,st2.top()));
                st2.pop();
            }
            st2.push(s[i]);
        }
    }
    while(!st2.empty()){
        int a=st1.top();
                st1.pop();
                int b=st1.top();
                st1.pop();
                st1.push(cal(b,a,st2.top()));
                st2.pop();
    }
    return st1.top();
}
int main()
{
    cout<<eval("1+(2*(3-1)/3+2)");
    return 0;
}