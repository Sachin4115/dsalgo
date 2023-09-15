#include <iostream>
#include <vector>
#include <stack>
using namespace std;

vector <int> NextGreat(vector<int> &arr){
    vector<int>ans(arr.size(),-1);
    stack<int> st;
    st.push(0);
    for(int i=1;i<arr.size();i++){
        while(!st.empty() && arr[i]>arr[st.top()]){
            ans[st.top()]=i;
            st.pop();
        }
        st.push(i);
    }
    return ans;
}

int main()
{
    vector<int> arr = {2,1,5,6,2,3,0,2,1,5,6,2,3};
    vector <int> ans = NextGreat(arr);
    for(auto a:ans)
        cout<<a<<" ";
    return 0;
}