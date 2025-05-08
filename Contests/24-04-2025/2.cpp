#include <iostream>
using namespace std;

int main()
{
    int t;
    cin>>t;
    while(t--){
        int n,x;
        cin>>n>>x;
        cout<<"\t";
        for(int i=0;i<n;i++){
            if(i==x) continue;
            cout<<i<<" ";
        }
        if(x<n) cout<<x;
        cout<<endl;
    }
    return 0;
}