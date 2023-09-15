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
            ans[st.top()]=arr[i];
            st.pop();
        }
        st.push(i);
    }
    return ans;
}

int main()
{
    vector<int> arr = {4,6,3,1,0,9,5,6,7,3,2};
    vector <int> ans = NextGreat(arr);
    for(auto a:ans)
        cout<<a<<" ";
    return 0;
}