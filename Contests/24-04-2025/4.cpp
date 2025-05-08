#include <iostream>
using namespace std;

int main()
{
    int t;
    cin>>t;
    while(t--){
        int n,m;
        cin>>n>>m;
        int a[n],b[m];
        for(int i=0;i<n;i++) cin>>a[i];
        for(int i=0;i<m;i++) cin>>b[i];
        // cout<<"\n";
        int l[n],r[n];
        int k=0;
        for(int i=0;i<n;i++){
            l[i]=k;
            if(k!=m && a[i]>=b[k]) k++;
        }
        if(k==m){
            cout<<0<<endl;
            continue;
        }
        k=0;
        for(int i=n-1;i>=0;i--){
            r[i]=k;
            if(k!=m && a[i]>=b[m-1-k]) k++;
        }
        if(k==m){
            cout<<0<<endl;
            continue;
        }
        // for(int i=0;i<n;i++) cout<<l[i]<<" ";
        // cout<<endl;
        // for(int i=0;i<n;i++) cout<<r[i]<<" ";
        // cout<<endl;
        int q = INT_MAX;
        for(int i=0;i<n;i++){
            // if(m-l[i]-r[i]==0) q=min(q,max(b[l[i]],b[l[i+1]]));
            if(m-l[i]-r[i]==1) q=min(q,b[l[i]]);
            if(m-l[i]-r[i]==2) {
                if(a[i]>=b[l[i]]) q=min(q,b[l[i]+1]);
                if(a[i]>=b[l[i]+1]) q=min(q,b[l[i]]);
            }

        }
        if(q==INT_MAX) cout<<-1<<endl;
        else cout<<q<<endl;
        // cout<<endl;

    }
    return 0;
}