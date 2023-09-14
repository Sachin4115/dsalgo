#include <iostream>
#include <stack>
using namespace std;

stack <int> stackcopy(stack <int> st1){
    stack <int> temp;
    stack <int> result;
    while(!st1.empty()){
        int t=st1.top();
        temp.push(t);
        st1.pop();
    }
    while(!temp.empty()){
        int t=temp.top();
        result.push(t);
        temp.pop();
    }
    return result;
}

int main()
{
    stack<int>input;
    input.push(1);
    input.push(2);
    input.push(3);
    input.push(4);
    stack<int> result = stackcopy(input);
    while(!result.empty()){
        int t=result.top();
        cout<<t<<" ";
        result.pop();
    }
    return 0;
}