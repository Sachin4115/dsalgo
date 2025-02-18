#include <iostream>
#include <vector>
using namespace std;

int main()
{
    int n;
    cin>>n;
    vector<int> p(n);
    vector<int> q(n);
    vector<int> ans(n);
    for(int i=0;i<n;i++) cin>>p[i];
    for(int i=0;i<n;i++) cin>>q[i];
    for(int i=0;i<n;i++){
        ans[q[i]-1]=q[p[i]-1];
    }
    for(int i=0;i<n;i++) cout<<ans[i]<<" ";
    return 0;
}