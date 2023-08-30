#include <iostream>
using namespace std;

void path(int r,int c,int n,int m, string s){

    if((r==n)&&(c==m)){
        cout<<s<<" ";
        return;
    }
    if(r<=n){
        path(r+1,c,n,m,s+"h");
    }
    if(c<=m){
        path(r,c+1,n,m,s+"v");
    }
}

int main()
{
    int n=3,m=3;
    path(1,1,n,m,"");
    return 0;
}