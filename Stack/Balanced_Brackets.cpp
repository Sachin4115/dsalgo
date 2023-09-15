#include <iostream>
#include <stack>
using namespace std;

bool isBal(string s){
    stack <char> st;
    for(int i=0;i<s.length();i++){
        if(s[i]=='('||s[i]=='['||s[i]=='{')
            st.push(s[i]);
        else if(s[i]==')' && !st.empty()){
            if(st.top()=='(')
                st.pop();
            else
                return 0;
        }
        else if(s[i]==']' && !st.empty()){
            if(st.top()=='[')
                st.pop();
            else
                return 0;
        }
        else if(s[i]=='}' && !st.empty()){
            if(st.top()=='{')
                st.pop();
            else
                return 0;
        }
        else
            return 0;
    }
    return st.empty();
}

int main()
{
    string str="({[{[()]}{([{}[()]])}]})";
    cout<<isBal(str);
    return 0;
}