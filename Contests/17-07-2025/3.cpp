#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main()
{
    int t;
    cin>>t;
    while(t--){
        int n, k;
        cin>>n>>k;
        vector<int> arr(n);
        for(int i=0;i<n;i++) cin>>arr[i];
        int in=arr[k-1];
        sort(arr.begin(),arr.end());
        int i;
        int w=1;
        for(i=0;i<n-1;i++){
            if(arr[i]<in || arr[i]==arr[i+1]) continue;
            if(arr[i+1]-arr[i]<=arr[i]-w+1){
                w+=arr[i+1]-arr[i];
            }else{
                break;
            }
        }
        if(i==n-1) cout<<"Yes"<<endl;
        else cout<<"No"<<endl;
    }
    return 0;
}