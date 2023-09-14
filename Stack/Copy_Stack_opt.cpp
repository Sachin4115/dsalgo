#include <iostream>
#include <stack>
using namespace std;

void stackcopy(stack <int> &st1,stack <int> &st2){
    if(st1.empty())
        return;
    int t=st1.top();
    st1.pop();
    stackcopy(st1,st2);
    st2.push(t);
}

int main()
{
    stack<int>input;
    stack<int>r;
    input.push(1);
    input.push(2);
    input.push(3);
    input.push(4);
    stackcopy(input,r);
    while(!r.empty()){
        int t=r.top();
        cout<<t<<" ";
        r.pop();
    }
    return 0;
}