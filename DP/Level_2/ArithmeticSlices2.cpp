#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;

int main()
{
    vector<int> arr = {4,2,3,5,2,6,7,9,8,11};
    vector<unordered_map<int,int>> dp(arr.size());
    dp[1][arr[1]-arr[0]]=1;
    int ans=0;
    for(int i=2;i<arr.size();i++){
        for(int j=i-1;j>=0;j--){
            long di = arr[i]-arr[j];
            if(di>=INT_MAX || di<=INT_MIN) continue;
            int d = arr[i]-arr[j];
            if(dp[j].find(d)==dp[j].end()){
                dp[i][d]+=1;
            }else{
                ans+=dp[j][d];
                dp[i][d]+=(dp[j][d]+1);
            }
        }
    }
    cout<<ans;
    return 0;
}