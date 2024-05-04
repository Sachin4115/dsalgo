#include <iostream>
using namespace std;

int main()
{
    int n,m;

    n=6;
    m=8;

    int k=n>m?n:m;

    int a[n]={1,1,0,0,1,1};
    int b[m]={1,0,1,0,0,1,0,1};

    int c=0;

    int ans[k];

    for(int i=0;i<k;i++){
        if(i<n&&i<m){
            int s = a[n-i-1]+b[m-i-1]+c;
            if(s==2){
                c=1;
                s=0;
            }else if(s==3){
                c=1;
                s=1;
            }else{
                c=0;
            }
            ans[k-i-1]=s;
        }else if(i<n){
            int s = a[n-i-1]+c;
            if(s==2){
                c=1;
                s=0;
            }else{
                c=0;
            }
            ans[k-1-i]=s;
        }else if(i<m){
            int s = b[m-i-1]+c;
            if(s==2){
                c=1;
                s=0;
            }else{
                c=0;
            }
            ans[k-1-i]=s;
        }
    }

    if(c)
        cout<<c<<" ";
    for(int i=0;i<k;i++){
        cout<<ans[i]<<" ";
    }

    return 0;
}