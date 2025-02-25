#include <iostream>
#include <vector>
using namespace std;

int main()
{
    vector<int>arr;
    int n,e;
    cin>>n;
    for(int i=0;i<n;i++){
        cin>>e;
        arr.push_back(e);
    }
    int s=0,ans=0;
    for(int i=0;i<n;i++){
        s+=arr[i];
        ans=max(ans,s);
        if(s<0) s=0;
    }
    cout<<ans;
    return 0;
}