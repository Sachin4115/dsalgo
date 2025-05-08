#include <iostream>
using namespace std;

int main()
{
    int t;
    cin>>t;
    while(t--){
        int n,k;
        cin>>n>>k;
        int a[n],b[n];
        for(int i=0;i<n;i++) cin>>a[i];
        for(int i=0;i<n;i++) cin>>b[i];
        cout<<"\t";
        int q=0,w=0;
        int mm[4] = {INT_MIN,INT_MAX,INT_MIN,INT_MAX};
        int t=-1;
        bool p=0;
        for(int i=0;i<n;i++){
            if(a[i]==-1 && b[i]==-1){
                q++;w++;
            }else if(a[i]==-1){
                q++;
                mm[2] = max(mm[2],b[i]);
                mm[3] = min(mm[3],b[i]);
            }else if(b[i]==-1){
                w++;
                mm[0] = max(mm[0],a[i]);
                mm[1] = min(mm[1],a[i]);
            }else{
                if(t==-1) t=a[i]+b[i];
                else if(t!=a[i]+b[i]){
                    cout<<0<<endl;
                    p=1;
                    break;
                }
            }
        }
        if(p) continue;
        if(q==n){
            cout<<k-(mm[2]-mm[3])+1<<endl;
            continue;
        }else if(w==n){
            cout<<k-(mm[0]-mm[1])+1<<endl;
            continue;
        }
        for(int i=0;i<n;i++){
            if(a[i]==-1 && b[i]==-1) continue;
            else if(a[i]==-1 && t-b[i]>=0 && t-b[i]<=k) continue;
            else if(b[i]==-1 && t-a[i]>=0 && t-a[i]<=k) continue;
            else if(a[i]!=-1 && b[i]!=-1 && a[i]+b[i]==t) continue;
            else{
                p=1;
                cout<<0<<endl;
                break;
            }
        }
        if(!p) cout<<1<<endl;

    }
    return 0;
}