#include <iostream>
#include <unordered_set>
#include <vector>
#include <queue>

using namespace std;

int main()
{
    string a = "der", b = "dfs";
    vector<string> w = {"des","der","dfr","dgt","dfs"};
    queue<vector<string>>q;
    unordered_set<string>m;
    int n = a.length();
    for(string s:w) m.insert(s);
    q.push({a});
    vector<vector<string>> ans;
    int t=0;
    while(q.size()){
        vector<string> s = q.front();
        q.pop();
        if(t && s.size()>t) break;
        string e = s.back();
        m.erase(s.back());
        if(s.back()==b){
            if(t==0) t=s.size();
            if(t==s.size()){
                ans.push_back(s);
            }
            continue;
        }
        for(int i=0;i<n;i++){
            char ch = e[i];
            for(char c ='a';c<='z';c++){
                e[i]=c;
                if(m.find(e)!=m.end()){
                    s.push_back(e);
                    q.push(s);
                    s.pop_back();
                }
            }
            e[i]=ch;
        }
    }
    return 0;
}