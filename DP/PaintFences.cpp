#include <iostream>
using namespace std;

int main()
{
    int n=5,k=3;
    int dp[3][n];
    dp[0][0]=k;
    dp[1][0]=k;
    dp[2][0]=k;
    long same = k;
    long diff = k;
    long total = k;
    for(int j=1;j<n;j++){
        long s=diff;
        long d=total*(k-1);
        same=s;
        diff=d;
        total=same+diff;
    }
    cout<<total;
    return 0;
}