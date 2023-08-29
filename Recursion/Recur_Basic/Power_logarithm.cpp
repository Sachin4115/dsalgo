#include <iostream>
using namespace std;
int pow(int n,int p){
    if(p==0)
        return 1;
    if(p%2)
        return pow(n,p/2)*pow(n,p/2)*n;
    return pow(n,p/2)*pow(n,p/2);
}
int main()
{
    int n=5,p=4,r;
    r=pow(n,p);
    cout<<r;
    return 0;
}