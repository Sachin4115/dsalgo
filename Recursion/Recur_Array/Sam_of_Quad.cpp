#include <iostream>
#include <string>
#include <unordered_map>
using namespace std;

bool sum_exists(int nums[],int target, int n, int count){
    if(target==0&&count==4)
        return true;
    if(target<0||n==0||count==4)
        return false;
    return sum_exists(nums,target-nums[n-1],n-1,count+1)||sum_exists(nums,target,n-1,count);
}
int main()
{
    int nums[]={2,7,4,0,9,5,1,3};
    int target = 20;
    int n=sizeof(nums)/sizeof(nums[0]);
    cout<<sum_exists(nums,target,n,0);
    return 0;
}