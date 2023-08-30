#include <iostream>
using namespace std;

void path(int r,int c,int n,int m, string s){
    if((r>n)||(c>n))
        return;
    if((r==n)&&(c==m)){
        cout<<s<<" ";
        return;
    }
    if(r<=n){
        path(r+1,c,n,m,s+"h1");
        path(r+2,c,n,m,s+"h2");
        path(r+3,c,n,m,s+"h3");
    }
    if(c<=m){
        path(r,c+1,n,m,s+"v1");
        path(r,c+2,n,m,s+"v2");
        path(r,c+3,n,m,s+"v3");
    }
    if((r<=n)&&(c<=m)){
        path(r+1,c+1,n,m,s+"d1");
        path(r+2,c+2,n,m,s+"d2");
        path(r+3,c+3,n,m,s+"d3");
    }
}

int main()
{
    int n=2,m=2;
    path(1,1,n,m,"");
    return 0;
}