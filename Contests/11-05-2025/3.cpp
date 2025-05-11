#include <iostream>
#include <vector>
using namespace std;

int main()
{
    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        int t=0,l=0,b=n-1,r=n-1;
        int as=n*n-1;
        vector<vector<int>> ans(n,vector<int>(n,0));
        while(t<=b && l<=r){
            for(int i=l;i<=r;i++){
                ans[t][i]=as--;
            }
            t++;
            for(int i=t;i<=b;i++){
                ans[i][r]=as--;
            }
            r--;
            if(t<=b){
                for(int i=r;i>=l;i--){
                    ans[b][i]=as--;
                }
                b--;
            }
            if(l<=r){
                for(int i=b;i>=t;i--){
                    ans[i][l]=as--;
                }
                l++;
            }
        }
        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                cout<<ans[i][j]<<" ";
            }cout<<endl;
        }
    }
    return 0;
}