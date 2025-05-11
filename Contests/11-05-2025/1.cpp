#include <iostream>
using namespace std;

int main()
{
    int t;
    cin>>t;
    while(t--){
        int n,m,p,q;
        cin>>n>>m>>p>>q;
        if(n%p==0){
            if((n/p)*q!=m){
                cout<<"No"<<endl;
                continue;
            }
        }
        cout<<"Yes"<<endl;
    }
    return 0;
}