#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main()
{
    int t;
    cin>>t;
    while(t--){
        int n,s,ans=0;
        cin>>n>>s;
        for(int i=0;i<n;i++){
            int dx,dy,x,y;
            cin>>dx>>dy>>x>>y;
            long long dir = (dx*1LL*x-dy*1LL*y)%s;
            if(dir<0) dir+=s;
            if(dir==0) ans++;
        }
        cout<<ans<<endl;
    }
    return 0;
}