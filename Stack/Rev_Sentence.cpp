#include <iostream>
#include <stack>
#include <string>
using namespace std;

void rev(string s){
    stack<string> st;
    for(int i=0;i<s.length();i++){
        string word="";
        while(s[i]!=' ' && i<s.length()){
            word+=s[i];
            i++;
        }
        st.push(word);
    }
    while(!s.empty()){
        cout<<st.top()<<" ";
        st.pop();
    }
}

int main()
{
    string s="My Name Is Sachin";
    rev(s);
    return 0;
}