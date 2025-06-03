#include <iostream>
#include <math.h>
using namespace std;

int main()
{
    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        int p=0;
        for(int i=0;i<64;i++){
            if(pow(2,i)<=n){
                p=i;
            }else{
                break;
            }
        }
        cout<<2LL*p+3<<endl;
    }
    return 0;
}