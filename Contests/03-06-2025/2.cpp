#include <iostream>
#include <vector>
#include <algorithm>
#include <math.h>
using namespace std;

int f[11] = {1,1,2,3,5,8,13,21,34,55,89};

int main()
{
    int t;
    cin>>t;
    while(t--){
        int n,m;
        cin>>n>>m;
        vector<vector<int>> arr(m,vector<int>(3,0));
        int a,b;
        a=f[n]+f[n-1];
        b=f[n];
        string ans="";
        for(int i=0;i<m;i++){
            cin>>arr[i][0]>>arr[i][1]>>arr[i][2];
            sort(arr[i].begin(),arr[i].end());
            if(arr[i][2]>=a && arr[i][1]>=b && arr[i][0]>=b){
                ans+="1";
            }else{
                ans+="0";
            }
        }
        cout<<ans<<endl;
    }
    return 0;
}