#include <iostream>
using namespace std;

int main()
{
    int t;
    cin>>t;
    while(t--){
        int x;
        cin>>x;
        int d=10;
        while(x){
            d=min(d,x%10);
            x/=10;
        }
        cout<<d<<endl;
    }
    return 0;
}