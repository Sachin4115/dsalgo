// Greatest element in the window of size s?


#include <iostream>
#include <stack>

using namespace std;

int main()
{
    int n=17;
    int arr[n] = {2,9,3,8,1,7,12,6,14,4,32,0,7,19,8,12,6};
    int nge[n] = {};
    stack <int> st;
    st.push(0);
    int s=4;
    for(int i=0;i<n;i++){
        while(!st.empty() && arr[i]>arr[st.top()]){
            nge[st.top()]=i;
            st.pop();
        }
        st.push(i);
    }
    while(!st.empty()){
        nge[st.top()]=n+s+1;
        st.pop();
    }

    int j;
    for(int i=0;i<=n-s;i++){
        j=nge[i];
        int k=i;
        while(j!=n+s+1 && j<i+4){
            k=j;
            j=nge[k];
        }
        cout<<arr[k]<<" ";
    }

    return 0;
}