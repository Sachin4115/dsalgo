// Rings in Hands(Easy)

#include <iostream>
using namespace std;

int main()
{
    int n, o;
    cin>>n>>o;
    int l=1,r=2,d,a=0;
    char c;
    while(o--){
        cin>>c>>d;
        if(c=='R'){
            if(d>r){
                if(l>r && l<d){
                    a+=n-d+r;
                }else{
                    a+=d-r;
                }
            }else{
                if(l>d && l<r){
                    a+=n-r+d;
                }else{
                    a+=r-d;
                }
            }
            r=d;
        }else{
            if(d>l){
                if(r>l && r<d){
                    a+=n-d+l;
                }else{
                    a+=d-l;
                }
            }else{
                if(r>d && r<l){
                    a+=n-l+d;
                }else{
                    a+=l-d;
                }
            }
            l=d;
        }
    }
    cout<<a;
    return 0;
}