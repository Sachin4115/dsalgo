#include <iostream>
using namespace std;

// Given number n
// Set its ith bit
// Unset its jth bit
// Toggle its kth bit
// Check its mth bit
int main()
{
    int n,i,j,k,m;
    cin>>n;
    cin>>i;
    cin>>j;
    cin>>k;
    cin>>m;

    int SetMask = (1<<i);
    int UnSetMask = ~(1<<j);
    int ToggleMask = (1<<k);
    int CheckMask = (1<<m);

    cout<<(n | SetMask)<<endl;
    cout<<(n & UnSetMask)<<endl;
    cout<<(n ^ ToggleMask)<<endl;
    cout<<((n & CheckMask)==0?false:true)<<endl;

    return 0;
}