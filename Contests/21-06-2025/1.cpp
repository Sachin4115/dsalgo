#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main()
{
    int t;
    cin>>t;
    while(t--){
        vector<pair<int,int>> a(3),b(3);
        int q=0,w=0;
        for(int i=0;i<3;i++){
            cin>>a[i].first;
            cin>>a[i].second;
            q+=a[i].first;
            w+=a[i].second;
            b[i].first=a[i].second;
            b[i].second=a[i].first;
        }
        sort(a.rbegin(),a.rend());
        sort(b.rbegin(),b.rend());
        if(a[0].first==a[2].first && a[0].first==w) cout<<"Yes";
        else if(b[0].first==b[2].first && b[0].first==q) cout<<"Yes";
        else if(a[0].first==a[1].first+a[2].first && a[1].second==a[2].second && a[0].second+a[1].second==a[0].first) cout<<"Yes";
        else if(b[0].first==b[1].first+b[2].first && b[1].second==b[2].second && b[0].second+b[1].second==b[0].first) cout<<"Yes";
        else cout<<"No";
        cout<<endl;
    }
    return 0;
}