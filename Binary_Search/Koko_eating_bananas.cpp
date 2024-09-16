#include <iostream>
#include <vector>
using namespace std;

int helper(int m, vector<int> &arr){
    if(m==0)
        return INT_MAX;
    int c=0;
    for(int i=0;i<arr.size();i++){
        c+=(arr[i]/m);
        if(arr[i]%m)
            c++;
    }
    return c;
}

int minEatingSpeed(vector<int>& arr, int h) {
    int m=INT_MIN;
    for(int i=0;i<arr.size();i++)
        m=max(m,arr[i]);
    int ans=m;
    if(h==arr.size())
        return ans;
    int l=0,r=m;
    while(l<=r){
        int mid=(l+r)/2;
        int t=helper(mid,arr);
        if(t<=h){
            ans=min(ans,mid);
            r=mid-1;
        }else{
            l=mid+1;
        }
    }
    return ans;
}

int main()
{
    vector<int> arr={3,6,7,11};
    cout<<minEatingSpeed(arr,8);
    return 0;
}