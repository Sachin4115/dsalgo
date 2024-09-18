// You are given an integer array nums. You are initially positioned
// at the array's first index, and each element in the array
// represents your maximum jump length at that position.
// Return true if you can reach the last index, or false otherwise.

#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

class Solution {
public:
    bool canJump1(vector<int>& a) {
        int m=0,n=a.size();
        for(int i=0;i<n;i++){
            if(m<i)
                return 0;
            m=max(m,i+a[i]);
        }
        if(m>=n-1)
            return 1;
        return 0;
    }

    bool canJump2(vector<int>& a) {
        int n = a.size();
        bool dp[n];
        dp[n-1]=1;
        for(int i=n-2;i>=0;i--){
            bool t=0;
            for(int j=1;j<=a[i] && i+j<n;j++){
                t=t||dp[i+j];
            }
            dp[i]=t;
        }
        return dp[0];
    }
};