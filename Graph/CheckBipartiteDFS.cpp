#include <iostream>
#include <queue>
#include <vector>
using namespace std;

bool fun(vector<vector<int>> &arr, vector<int>&vis, int c){
    for(int w : arr[c]){
        if(vis[w]){
            if(vis[w]==vis[c]) return 0;
            continue;
        }else{
            vis[w]=3-vis[c];
            if(!fun(arr,vis,w)) return 0;
        }
    }
    return 1;
}

bool isBipartiteDFS(vector<vector<int>>& arr) {
    int n=arr.size();
    vector<int>vis(n,0);
    for(int i=0;i<n;i++){
        if(!vis[i]){
            vis[i]=1;
            if(!fun(arr,vis,i)) return 0;
        }
    }
    return 1;
}

int main()
{
    vector<vector<int>> arr = {{1,2,3},{0,2},{0,1,3},{0,2}};
    cout<<isBipartiteDFS(arr);
    return 0;
}