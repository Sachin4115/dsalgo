#include <iostream>
using namespace std;
bool sum_exists(int num[],int n, int tsum,int count){
    if(count==3&&tsum==0)
        return true;
    if(count==3||n==0||tsum<0)
        return false;
    return sum_exists(num,n-1,tsum-num[n-1],count+1)||sum_exists(num,n-1,tsum,count);
}
int main()
{
    int nums[]={2,7,4,0,9,5,1,3};
    int tsum = 6;
    int n=sizeof(nums)/sizeof(nums[0]);
    cout<<sum_exists(nums,n,tsum,0);
    return 0;
}