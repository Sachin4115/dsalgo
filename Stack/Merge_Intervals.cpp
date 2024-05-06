#include <iostream>
#include <stack>
#include <algorithm>
using namespace std;

int main()
{
    int n=6;
    int arr[n][2] = {
        {22,28},
        {1,8},
        {25,27},
        {14,19},
        {27,30},
        {5,12}
    };

    for(int i=0;i<n;i++){
        for(int j=0;j<n-i-1;j++){
            if(arr[j][0]>arr[j+1][0]){
                swap(arr[j],arr[j+1]);
            }
        }
    }
    stack<int*> st;
    st.push(arr[0]);
    for(int i=1;i<n;i++){
        if(arr[i][0]>st.top()[0] && arr[i][0]<st.top()[1]){
            st.top()[1]=st.top()[1]>arr[i][1]?st.top()[1]:arr[i][1];
        }else{
            st.push(arr[i]);
        }
    }
    // cout<<st.size();
    n=st.size();
    int ans[n][2];
    for(int i=0;i<n;i++){
        ans[n-i-1][0]=st.top()[0];
        ans[n-i-1][1]=st.top()[1];
        st.pop();
    }
    for(int i=0;i<n;i++){
        for(int j=0;j<2;j++){
            cout<<ans[i][j]<<"\t";
        }cout<<endl;
    }
    return 0;
}