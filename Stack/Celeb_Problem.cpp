#include <iostream>
#include <stack>
using namespace std;

bool checkCeleb(int i,int n,int arr[][10]){
    for(int j=0;j<n;j++){
        if(arr[i][j])
            return false;
        if(!arr[j][i] && j!=i){
            return false;
        }
    }
    return true;
}

int main()
{
    int n=4;
    int arr[10][10] = {
        {0,1,1,1},
        {1,0,0,0},
        {0,0,0,0},
        {1,1,1,0}
    };
    stack <int> st;
    for(int i=0;i<n;i++){
        st.push(i);
    }

    while(st.size()>1){
        int a = st.top();
        st.pop();
        int b = st.top();
        st.pop();
        if(arr[a][b]){
            st.push(b);
        }else{
            st.push(a);
        }
    }

    int c = st.top();
    if(checkCeleb(c,n,arr))
        cout<<"Celebrity "<<c<<" is present.";
    else
        cout<<"No celebrity is present";

    return 0;
}