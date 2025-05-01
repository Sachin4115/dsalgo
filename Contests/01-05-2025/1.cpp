#include <iostream>
using namespace std;

int main()
{
    int t;
    cin>>t;
    while(t--){
        int n,q=1;
        cin>>n;
        if(n%2==0){
            q+=((n/2)*n/2);
        }else{
            n/=2;
            q+=n*(n+1);
        }
        cout<<q<<endl;
    }
    return 0;
}