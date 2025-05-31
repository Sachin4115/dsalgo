#include <iostream>
#include <math.h>
#include <vector>
#include <unordered_map>
using namespace std;

int m = 998244353;
vector<long long> po = {1};

int main()
{
    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        int a[n],b[n];
        unordered_map<int,int> m1,m2;
        for(int i=0;i<n;i++) {
            cin>>a[i];
            m1[a[i]]=i;
        }
        for(int i=0;i<n;i++){
            cin>>b[i];
            m2[b[i]]=i;
        }
        vector<int> q(n),w(n);
        q[0]=a[0];
        w[0]=b[0];

        for(int i=1;i<n;i++){
            q[i]=max(q[i-1],a[i]);
            w[i]=max(w[i-1],b[i]);
        }

        if ((int)po.size() <= n) {
            int old = po.size();
            po.resize(n + 1);
            for (int i = old; i <= n; i++) {
                po[i] = (po[i - 1] * 2) % m;
            }
        }

        for(int i=0;i<n;i++){
            int e = max(q[i],w[i]);
            int r;
            // cout<<q[i]<<" "<<w[i]<<" ";
            if(q[i]>w[i]){
                int l = m1[e];
                int j = i-l;
                r = b[j];
            }else if(q[i]<w[i]){
                int l = m2[e];
                int j = i-l;
                r = a[j];
            }else{
                int j1 = m1[e];
                int j2 = m2[e];
                int k1 = i-j1;
                int k2 = i-j2;
                int r1 = (k1>=0 && k1<n ? b[k1] : -1);
                int r2 = (k2>=0 && k2<n ? a[k2] : -1);
                r = max(r1,r2);
            }
            // cout<<i<<" "<<e<<" "<<r<<" "<<(1<<e)<<" "<<(1<<r)<<"=>";
            cout<< ((po[e]) + (po[r])) % m<<" ";
        }
        cout<<endl;
    }
    return 0;
}