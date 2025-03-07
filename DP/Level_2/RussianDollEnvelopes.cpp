#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

// Optimization of LIS (nlogn)

int fun(vector<int>&dp,int a){
    int l=0,r=dp.size()-1;
    while(l<=r){
        int m=l+(r-l)/2;
        if(dp[m]<a) l=m+1;
        else r=m-1;
    }
    return r+1;
}
int maxEnvelopes(vector<vector<int>>& arr) {
    sort(arr.begin(),arr.end(),[](vector<int> a, vector<int> b) -> bool{
        if(a[0]!=b[0]) return a[0]<b[0];
        else return a[1]>b[1];
    });
    int n = arr.size();
    vector<int>dp;
    dp.push_back(arr[0][1]);
    for(int i=1;i<n;i++){
        if(arr[i][1]>dp.back()) dp.push_back(arr[i][1]);
        else dp[fun(dp,arr[i][1])]=arr[i][1];
    }
    return dp.size();
}

int main()
{
    vector<vector<int>> arr = {{5,4},{6,4},{6,7},{2,3}};
    return 0;
}