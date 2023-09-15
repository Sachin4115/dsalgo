#include <iostream>
#include <vector>
#include <algorithm>
#include <stack>
using namespace std;

int maxArea(vector <int> &arr){
    stack<int> st;
    int n,p,element;//n->next smaller index  p->prev smaller index
    int m=INT_MIN;
    st.push(0);
    for(int i=1;i<arr.size();i++){
        while(!st.empty() && arr[i]<arr[st.top()]){
            element=arr[st.top()];
            st.pop();
            n=i;
            p=st.empty()?-1:st.top();
            m=max(m,element*(n-p-1));
        }
        st.push(i);
    }
    return m;
}

int main()
{
    vector <int> arr = {2,1,5,6,2,3,0,2,1,5,6,2,3};
    cout<<maxArea(arr);
    return 0;
}