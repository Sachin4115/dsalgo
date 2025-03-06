#include <iostream>
#include <set>
#include <vector>
#include <queue>
using namespace std;

int countDistinctIsland(vector<vector<int>>& grid) {
    queue<pair<int,int>>q;
    set<vector<pair<int,int>>>s;
    int n=grid.size(),m=grid[0].size();
    vector<vector<bool>> vis(n,vector<bool>(m,0));
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            if(grid[i][j] && !vis[i][j]){
                q.push({i,j});
                vector<pair<int,int>>ans;
                ans.push_back({0,0});
                vis[i][j]=1;
                while(q.size()){
                    pair<int,int>p=q.front();
                    q.pop();
                    int a=p.first,b=p.second;
                    if(a>0 && grid[a-1][b] && !vis[a-1][b]){ ans.push_back({a-i-1,b-j});vis[a-1][b]=1;q.push({a-1,b});}
                    if(b>0 && grid[a][b-1] && !vis[a][b-1]){ ans.push_back({a-i,b-j-1});vis[a][b-1]=1;q.push({a,b-1});}
                    if(a<n-1 && grid[a+1][b] && !vis[a+1][b]){ ans.push_back({a-i+1,b-j});vis[a+1][b]=1;q.push({a+1,b});}
                    if(b<m-1 && grid[a][b+1] && !vis[a][b+1]){ ans.push_back({a-i,b-j+1});vis[a][b+1]=1;q.push({a,b+1});}
                }
                s.insert(ans);
            }
        }
    }
    return s.size();
}

int main()
{
    vector<vector<int>> arr = {
        {1,1,0,1,1},
        {1,0,0,0,0},
        {0,0,0,0,0},
        {0,0,0,1,1},
        {1,1,0,1,0}
    };
    cout<<countDistinctIsland(arr);
    return 0;
}