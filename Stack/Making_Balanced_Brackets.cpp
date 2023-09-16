#include <iostream>
#include <stack>
using namespace std;

int isBal(string s){
    stack <char> st;
    int count=0;
    for(int i=0;i<s.length();i++){
        if(s[i]=='('||s[i]=='['||s[i]=='{')
            st.push(s[i]);
        else if(s[i]==')' && !st.empty()){
            if(st.top()=='(')
                st.pop();
            else{
                count++;
            }
        }
        else if(s[i]==']' && !st.empty()){
            if(st.top()=='[')
                st.pop();
            else{
                count++;
            }
        }
        else if(s[i]=='}' && !st.empty()){
            if(st.top()=='{')
                st.pop();
            else{
                count++;
            }
        }
        else
            count++;
    }
    return count+st.size();
}

int main()
{
    string str="()[(()})";
    cout<<isBal(str);
    return 0;
}