#include <iostream>
#include <vector>
#include <algorithm>
#include <stack>
using namespace std;

vector <int> nse(vector <int> &arr){
    stack<int> st;
    vector <int> ans(arr.size(),arr.size());
    st.push(0);
    for(int i=1;i<arr.size();i++){
        while(!st.empty() && arr[i]<arr[st.top()]){
            ans[st.top()]=i;
            st.pop();
        }
        st.push(i);
    }
    // for(auto a: ans){
    //     cout<<a<<" ";
    // }
    // cout<<endl;
    return ans;
}
vector <int> pse(vector <int> &arr){
    stack<int> st;
    vector <int> ans(arr.size(),arr.size());
    reverse(arr.begin(),arr.end());
    st.push(0);
    for(int i=1;i<arr.size();i++){
        while(!st.empty() && arr[i]<arr[st.top()]){
            ans[st.top()]=arr.size()-i-1;
            st.pop();
        }
        st.push(i);
    }
    reverse(arr.begin(),arr.end());
    reverse(ans.begin(),ans.end());
    // for(auto a: ans){
    //     cout<<a<<" ";
    // }
    // cout<<endl;
    return ans;
}

int maxArea(vector <int> &arr){
    vector <int> a1=nse(arr);
    vector <int> a2=pse(arr);
    int m=INT_MIN;
    for(int i=0;i<a1.size();i++){
        m=max(m,(a1[i]-a2[i]-1)*arr[i]);
    }
    return m;
}

int main()
{
    vector <int> arr = {2,1,5,6,2,3,0,2,1,5,6,2,3};
    cout<<maxArea(arr);
    return 0;
}