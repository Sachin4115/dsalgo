#include <iostream>
#include <set>
#include <vector>
using namespace std;

int main()
{
    int a = 8,b = 4288;
    vector<int> arr = {20,14,1,4,20};
    // vector<int> arr = {2,5,7};
    set<pair<int,int>>q;
    q.insert({0,a});
    // vector<int>ans(b-a+1,INT_MAX);
    vector<bool>v(100000,0);
    v[0]=1;
    while(q.size()){
        pair<int,int> c = *q.begin();
        q.erase(c);
        int s = c.first, n = c.second;
        if(n==b){
            cout<<s;
            break;
        }
        // cout<<s<<" "<<n<<", ";
        for(int i:arr){
            int x = (i*n)%100000;
            // if(x<=b){
                if(!v[x]){ v[x]=1;
                    q.insert({s+1,x});}
            // }
        }
    }
    // cout<<-1;
    // cout<<ans[b-a];
    return 0;
}