#include <iostream>
#include <vector>
#include <unordered_map>
#include <cmath>
using namespace std;

int main()
{
    string s;
    cin>>s;
    int n = s.length(),M=1000000007;
    long long ans=1;
    unordered_map<char,long long>mp;
    for(int j=0;j<n;j++){
        if(mp.count(s[j])==0){
            mp[s[j]]=ans;
            ans*=2;
        }else{
            int t = mp[s[j]];
            mp[s[j]]=ans;
            ans*=2;
            ans-=t;
        }
        ans%=M;
    }
    cout<<(ans-1+M)%M;
    return 0;
}