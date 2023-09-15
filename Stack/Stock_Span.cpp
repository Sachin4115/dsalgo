#include <iostream>
#include <algorithm>
#include <vector>
#include <stack>
using namespace std;
vector <int> span(vector <int> &arr){
    vector<int>ans(arr.size(),-1);
    stack<int> st;
    reverse(arr.begin(),arr.end());
    st.push(0);
    for(int i=1;i<arr.size();i++){
        while(!st.empty() && arr[i]>arr[st.top()]){
            ans[st.top()]=arr.size()-i-1;
            st.pop();
        }
        st.push(i);
    }
    reverse(ans.begin(),ans.end());
    reverse(arr.begin(),arr.end());
    return ans;
}

int main()
{
    vector<int> arr = {100,80,60,70,60,75,85};
    vector <int> ans = span(arr);
    for(int i=0;i<arr.size();i++)
        cout<<i-ans[i]<<" ";
    return 0;
}