#include <iostream>
using namespace std;

int divide(int a, int b){
    if(a == b)
        return 1;
    bool sign = true;
    if((a>=0 && b<0)||(a<0 && b>0)) sign = false;

    long n = abs(a);
    long d = abs(b);

    long ans=0;
    while(n>=d){
        int count = 0;
        // int sub = d;
        while(n>=(d<<(count+1))){
            count++;
        }
        ans+=1<<count;
        n=n-(d<<count);
    }
    if(ans == (1<<31) && sign){
        return INT_MAX;
    }else if(ans ==(1<<31) && !sign)
        return INT_MIN;
    if(sign)
        return ans;
    return -ans;
}

int main()
{
    cout<<divide(123456,17);
    return 0;
}