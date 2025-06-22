#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main()
{
    int t;
    cin>>t;
    while(t--){
        long long  n, m;
        cin>>n>>m;
        long long maxPoss = ((n*n)+n)/2;
        if(maxPoss<m || m<n){
            cout<<-1<<endl;
            continue;
        }
        vector<bool>vis(n,0);
        long long p=-1;
        long long in=n;
        long long l=n;
        while(m>=0){
            if(m==l){
                for(int i=0;i<int(n);i++){
                    if(vis[i]==0){
                        if(p!=-1) cout<<p<<" ";
                        cout<<i+1<<endl;
                        p=i+1;
                    }
                }
                break;
            }
            int c = min(in,m-in+1);
            l--;
            vis[c-1]=1;
            m-=c;
            if(p!=-1) cout<<p<<" ";
            cout<<c<<endl;
            p=c;
            while(in>0 && vis[in-1]) in--;
        }
    }
    return 0;
}