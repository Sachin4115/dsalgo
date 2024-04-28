#include <iostream>
#include <stack>
#include <string>
using namespace std;

bool chekDup(string str){

    stack<char> st;
    for(int i=0;i<str.length();i++){
        if(str[i]!=')'){
            st.push(str[i]);
        }else{
            if(st.top()=='('){
                return true;
            }while(st.top()!='('){
                st.pop();
            }
            st.pop();
        }
    }
    return false;
}

int main()
{

    string str1 = "((a+b)+(c+d)+(e+f))";
    string str2 = "(a+b)+((c+d))";

    cout<<chekDup(str1)<<endl;
    cout<<chekDup(str2);

    return 0;
}