#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main()
{
    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        vector<int> arr(n);
        for(int i=0;i<n;i++) cin>>arr[i];
        long long ans=0;
        sort(arr.begin(),arr.end());
        for(int i=2;i<n;i++){
            int m = max(arr[i],arr[n-1]-arr[i]);
            int l=0,r=i-1;
            while(l<r){
                if(arr[l]+arr[r]>m){
                    ans+=(r-l);
                    r--;
                }else l++;
            }
        }
        cout<<ans<<endl;
    }
    return 0;
}