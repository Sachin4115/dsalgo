#include <iostream>
#include <map>
using namespace std;

int main()
{
    int t;
    cin>>t;
    while(t--){
        int n,k;
        cin>>n>>k;
        long long a = LLONG_MAX;
        long long b = LLONG_MIN;
        long long s = 0, e;
        int f = 0;
        for(int i=0;i<n;i++){
            cin>>e;
            a=min(a,e);
            if(e>b){
                b=e;
                f=0;
            }
            s+=e;
            if(e==b) f++;
        }
        if(b-a>k+1 || (b-a==k+1 && f>1)) cout<<"Jerry\n";
        else{
            if(s%2) cout<<"Tom\n";
            else cout<<"Jerry\n";
        }
    }
    return 0;
}