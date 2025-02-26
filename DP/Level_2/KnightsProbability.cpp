#include <iostream>
#include <vector>
using namespace std;

int main()
{
    int r,c,k,n;
    cin>>n>>r>>c>>k;
    vector<vector<double>>curr(n,vector<double>(n,0));
    vector<vector<double>>next(n,vector<double>(n,0));
    vector<vector<double>>t(n,vector<double>(n,0));
    curr[r][c]=1;
    for(int m=1;m<=k;m++){
        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                if(curr[i][j]!=0){
                    int nr,nc;
                    nr=i-2;nc=j-1;
                    if((nr>=0&&nr<n)&&(nc>=0&&nc<n)) next[nr][nc]+=curr[i][j]/8;
                    nr=i-2;nc=j+1;
                    if((nr>=0&&nr<n)&&(nc>=0&&nc<n)) next[nr][nc]+=curr[i][j]/8;
                    nr=i+2;nc=j-1;
                    if((nr>=0&&nr<n)&&(nc>=0&&nc<n)) next[nr][nc]+=curr[i][j]/8;
                    nr=i+2;nc=j+1;
                    if((nr>=0&&nr<n)&&(nc>=0&&nc<n)) next[nr][nc]+=curr[i][j]/8;
                    nr=i-1;nc=j-2;
                    if((nr>=0&&nr<n)&&(nc>=0&&nc<n)) next[nr][nc]+=curr[i][j]/8;
                    nr=i-1;nc=j+2;
                    if((nr>=0&&nr<n)&&(nc>=0&&nc<n)) next[nr][nc]+=curr[i][j]/8;
                    nr=i+1;nc=j-2;
                    if((nr>=0&&nr<n)&&(nc>=0&&nc<n)) next[nr][nc]+=curr[i][j]/8;
                    nr=i+1;nc=j+2;
                    if((nr>=0&&nr<n)&&(nc>=0&&nc<n)) next[nr][nc]+=curr[i][j]/8;
                }
            }
        }
        curr=next;
        next=t;
    }
    double ans=0;
    for(int i=0;i<n;i++)
        for(int j=0;j<n;j++)
            ans+=curr[i][j];
    cout<<ans;
    return 0;
}