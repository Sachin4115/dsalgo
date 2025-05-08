#include <iostream>
using namespace std;

int main()
{
    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        string s;
        cin>>s;
        long long ans=0;
        for(int i=0;i<n;i++){
            if(s[i]=='0') ans++;
            else ans+=(n-1);
        }
        cout<<ans<<endl;
    }
    return 0;
}