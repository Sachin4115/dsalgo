#include <iostream>
using namespace std;

void path(int r,int c,int n,int m, string s){
    if((r==n)&&(c==m)){
        cout<<s<<" ";
        return;
    }
    for(int i=1;i<=n-r;i++){
        path(r+i,c,n,m,s+"h"+char(i+48));
    }
    for(int i=1;i<=m-c;i++){
        path(r,c+i,n,m,s+"v"+char(i+48));
    }
    for(int i=1;((i<=n-r)&&(i<=m-c));i++){
        path(r+i,c+i,n,m,s+"d"+char(i+48));
    }
}

int main()
{
    int n=2,m=2;
    path(1,1,n,m,"");
    return 0;
}