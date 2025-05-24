#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int main()
{
    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        // int arr[n];
        vector<int> arr(n);
        for(int i=0;i<n;i++)  cin>>arr[i];
        sort(arr.begin(),arr.end());
        // cout<<"\t";
        // for(int i:arr) cout<<i<<" ";
        // cout<<endl<<"\t";
        int ans=0;
        int l=0,r=n-1;
        // while (l<=r){

        // }
        if(arr[l]%2==arr[r]%2){
            cout<<ans<<endl;
            continue;
        }
        int a=1,b=1;
        while(l<n-1){
            if(arr[l]%2==arr[l+1]%2) a++;
            else break;
            l++;
        }
        while(r>1){
            if(arr[r]%2==arr[r-1]%2) b++;
            else break;
            r--;
        }
        cout<<min(a,b)<<endl;
    }
    return 0;
}