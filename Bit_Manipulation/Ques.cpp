#include <iostream>
using namespace std;

void swap(int a,int b){
    cout<<"First Number :"<<a<<endl;
    cout<<"Second Number :"<<b<<endl;

    a=a^b;
    b=a^b;
    a=a^b;

    cout<<"New First Number :"<<a<<endl;
    cout<<"New Second Number :"<<b<<endl;

}

// by Left Shift Operator
bool checkSetBitLSO(int n, int i){
    int x = 1<<i;
    if((n&x)!=0){
        return true;
    }
    return false;
}

// by Right Shift Operator
bool checkSetBitRSO(int n, int i){
    int x = n>>i;
    if((x&1)!=0)
        return true;
    return false;
}

// Off Last Set Bit
void UnsetLastSetBit(int n){
    int mask = n-1;
    int ans = n & mask;
    cout<<ans<<endl;
}

// Check Power of Two
bool PowOf2(int n){
    if((n&(n-1))==0)
        return true;
    return false;
}

// No. of Set Bits
int noOfSetBits(int n){
    int ans=0;
    while(n){
            ans+=n&1;
        n=n>>1;
    }
    return ans;
}

// Second Approach (Better Approach)
int noOfSetBits2(int n){
    int ans=0;
    while(n){
        // Right Most Bit will be turned OFF
        n=n&(n-1);
        ans++;
    }
    return ans;
}

int main()
{

    swap(5,6);
    cout<<checkSetBitLSO(17,4)<<endl;
    cout<<checkSetBitRSO(17,3)<<endl;
    UnsetLastSetBit(28);
    cout<<PowOf2(1024)<<endl;
    cout<<noOfSetBits(7)<<endl;
    cout<<noOfSetBits2(11)<<endl;
    return 0;
}