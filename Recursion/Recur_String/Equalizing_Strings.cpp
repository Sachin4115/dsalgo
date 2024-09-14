#include <iostream>
#include <algorithm>
using namespace std;

int fun(string a, string b,int m, int n){
    if(n==-1 || m==-1){
        return m+n+2;
    }
    if(a[m]==b[n])
        return fun(a,b,m-1,n-1);
    else{
        return min(fun(a,b,m-1,n-1),min(fun(a,b,m-1,n),fun(a,b,m,n-1)))+1;
    }
}

int main()
{
    string a=""
    cout<<fun("SUNDAY","SATURDAY",5,7);
    return 0;
}