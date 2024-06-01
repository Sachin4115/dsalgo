#include <iostream>
#include <bitset>
using namespace std;

int main()
{
    int n;
    cin>>n;
    int twosCompOfN = ((~n)+1);
    int rightMostSetBitMask = (n & twosCompOfN);
    cout<<rightMostSetBitMask<<endl;

    // Direct Way

    cout<<(n & -n)<<endl;

    // Way to print it in binary form

    cout<< bitset<8>(rightMostSetBitMask);

    return 0;
}