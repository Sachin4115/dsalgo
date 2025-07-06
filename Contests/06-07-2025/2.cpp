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
        long long ans=0;
        cin>>n;
        vector<long long> arr(n),mi(n);
        for(int i=0;i<n;i++){
            cin>>arr[i];
            if(i==0) mi[i]=arr[i];
            else mi[i]=min(mi[i-1],arr[i]);
            ans+=mi[i];
        }
        ans=min(ans,arr[0]+arr[1]);
        long long a=mi[0]+mi[1];
        for(int i=2;i<n;i++){
            ans=min(ans,a);
            a+=mi[i];
        }
        cout<<"      "<<ans<<endl;
    }
    return 0;
}