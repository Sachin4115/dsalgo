#include <iostream>
#include <vector>
using namespace std;

int main()
{
    int n=6;
    vector<int>zero(n+1,0);//string ending with zero
    vector<int>one(n+1,0);//string ending with one
    zero[1]=1;
    one[1]=1;
    for(int i=2;i<=n;i++){
        zero[i]=one[i-1];
        one[i]=zero[i-1]+one[i-1];
    }
    cout<<one[n]+zero[n]<<endl;
    n=5;
    // Without array
    int zp=1,op=1,z,o;//previous zero, previous one, zero, one
    for(int i=2;i<=n;i++){
        z=op;
        o=zp+op;
        zp=z;
        op=o;
    }
    cout<<z+o;
    return 0;
}