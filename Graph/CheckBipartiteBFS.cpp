#include <iostream>
#include <queue>
#include <vector>
using namespace std;

bool isBipartiteBFS(vector<vector<int>>& arr) {
    int n=arr.size();
    vector<int>vis(n,0);
    queue<int>q;
    for(int i=0;i<n;i++){
        if(!vis[i]){
            q.push(i);
            vis[i]=1;
            while(q.size()){
                int c=q.front();
                q.pop();
                for(int w:arr[c]){
                    if(vis[w]){
                        if(vis[w]==vis[c]) return 0;
                        continue;
                    }else{
                        vis[w]=3-vis[c];
                        q.push(w);
                    }
                }
            }
        }
    }
    return 1;
}

int main()
{
    vector<vector<int>> arr = {{1,2,3},{0,2},{0,1,3},{0,2}};
    cout<<isBipartiteBFS(arr);
    return 0;
}