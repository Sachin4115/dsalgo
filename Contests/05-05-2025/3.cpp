#include <iostream>
using namespace std;

#define ll long long

int main()
{
    int t;
    cin>>t;
    while(t--){
        int n;
        ll k;
        char s[200100];
        // string s;
        cin>>n>>k>>s;
        // cin>>s;
        ll arr[n+1];
        ll l[n+2], r[n+2];
        l[0] = r[n+1] = 0;
        for(int i=1;i<=n;i++){
            cin>>arr[i];
            if(s[i-1]=='0'){
                arr[i]=-1e18;
            }
            l[i] = max(l[i-1]+arr[i],arr[i]);
        }
        for(int i=n;i>=1;i--) r[i] = max(r[i+1]+arr[i],arr[i]);
        for(int i=1;i<=n;i++){
            if(s[i-1]=='0'){
                arr[i] = k - max((ll)0,l[i-1]) - max((ll)0, r[i+1]);
                break;
                // i++;
            }
        }
        ll b=arr[1];
        for(int i=n;i>=1;i--){
            r[i] = max(r[i+1]+arr[i],arr[i]);
            b = max(b,r[i]);
        }
        if(b==k){
            cout<<"Yes\n";
            for(int i=1;i<=n;i++) cout<<arr[i]<<" ";
            cout<<endl;
        }else{
            cout<<"No\n";
        }
    }
    return 0;
}