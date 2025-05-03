#include <iostream>
#include <set>
#include <algorithm>
using namespace std;

int main()
{
    int t;
    cin>>t;
    while(t--){
        int n, k;
        cin>>n>>k;
        int a[n];
        for(int i=0;i<n;i++) cin>>a[i];
        set<int>st;
        sort(a,a+n);
        for(int i=0;i<n;i++){
            if(abs(i-(n-i-1))<=k+1) st.insert(a[i]);
        }
        cout<<*st.rbegin()-*st.begin()+1;
        cout<<endl;
    }

    return 0;
}