#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int m = 998244353;

int main()
{
    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        vector<int> a(n);
        int g;
        for(int i=0;i<n;i++){
            if(i==0) g=a[i];
            else g=__gcd(g,a[i]);
        }
        int c=0;
        for(int i=0;i<n;i++) if(g==a[i]) c++;

        if(c!=0){
            cout<<n-c<<endl;
            continue;
        }

        

        cout<<endl;
    }
    return 0;
}