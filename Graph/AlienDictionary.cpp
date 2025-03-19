#include <iostream>
#include <queue>
#include <vector>
using namespace std;

int main()
{
    int n = 5,k = 4;
    vector<string> dict = {"baa","abcd","abca","cab","cad"};
    vector<vector<int>> adj(k);
    for(int i=0;i<n-1;i++){
        int l = min(dict[i].size(),dict[i+1].size());
        for(int j=0;j<l;j++){
            if(dict[i][j]!=dict[i+1][j]){
                adj[dict[i][j]-'a'].push_back(dict[i+1][j]-'a');
                break;
            }
        }
    }
    // for(auto a:adj){
    //     for(auto i:a) cout<<i<<" ";
    //     cout<<endl;
    // }

    vector<int>vis(k);
    for(auto a:adj){
        for(int i:a){
            vis[i]++;
        }
    }
    queue<int>q;
    vector<int>ans;
    for(int i=0;i<k;i++) if(vis[i]==0) q.push(i);
    while(q.size()){
        int c = q.front();
        q.pop();
        for(int i:adj[c]){
            vis[i]--;
            if(vis[i]==0) q.push(i);
        }
        ans.push_back(c);
    }
    for(int i:ans) cout<<(char)('a'+i)<<" ";
    return 0;
}