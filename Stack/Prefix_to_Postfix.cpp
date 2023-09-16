#include <iostream>
#include <algorithm>
#include <stack>
using namespace std;

string convert(string str){
    stack <string> st;
    reverse(str.begin(),str.end());
    for(int i=0;i<str.length();i++){
        if(isdigit(str[i])){
            st.push(to_string(str[i]-'0'));
        }
        else{
            string v1=st.top();
            st.pop();
            string v2=st.top();
            st.pop();
            string v3=v1+v2+str[i];
            st.push(v3);
        }
    }
    cout<<st.top();
}

int main()
{
    cout<<convert("*+32-15");
    return 0;
}