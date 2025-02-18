

#include <iostream>
#include <unordered_set>
#include <vector>
using namespace std;

int main()
{
    int n,m,e;
    cin>>n>>m;
    unordered_set<int> s;
    vector<int>ans;
    for(int i=1;i<=m;i++){
        cin>>e;
        s.insert(e);
    }
    for(int i=1;i<=n;i++){
        if(s.find(i)==s.end()){
            ans.push_back(i);
        }
    }
    int q = ans.size();
    cout<<q<<endl;
    for(int i=0;i<q-1;i++) cout<<ans[i]<<" ";
    if(q)
        cout<<ans[q-1]<<endl;
    return 0;
}