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
        vector<int>arr(n);
        for(int i=0;i<n;i++) cin>>arr[i];
        vector<int>v=arr;
        sort(v.begin(),v.end());
        bool q=1;
        for(int i=0;i<n;i++){
            if(i!=0 && v[i]==v[i-1]) continue;
            int c = v[i];
            int g=0;
            for(int j=0;j<n;j++){
                if(arr[j]==c) continue;
                if(g==0) g=arr[j];
                else g=__gcd(g,arr[j]);
            }
            if(g!=c && g!=0){
                q=0;
                cout<<"Yes\n";
                for(int j=0;j<n;j++){
                    if(arr[j]==c) cout<<"1 ";
                    else cout<<"2 ";
                }
                cout<<endl;
                break;
            }
        }
        if(q) cout<<"No\n";
    }
    return 0;
}