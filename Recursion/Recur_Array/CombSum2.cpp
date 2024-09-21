// Given a collection of candidate numbers (candidates) and a target
// number (target), find all unique combinations in candidates where
// the candidate numbers sum to target.

// Each number in candidates may only be used once in the combination.

// Note: The solution set must not contain duplicate combinations.

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

vector<vector<int>> ans;
void fun(int i, vector<int> &a, int t, vector<int> &p){
    if(t==0){
        ans.push_back(p);
        return;
    }
    for(int j=i;j<a.size();j++){
        if(j>i && a[j]==a[j-1])
            continue;
        if(a[j] <= t){
            p.push_back(a[j]);
            fun(j+1, a, t-a[j], p);
            p.pop_back();
        }
    }
}
vector<vector<int>> combinationSum2(vector<int> &a, int t) {
    vector<int> p;
    sort(a.begin(), a.end());
    fun(0, a, t, p);
    return ans;
}

int main()
{
    vector<vector<int>> result;
    vector<int> a = {10,1,2,7,6,1,5};
    result = combinationSum2(a,8);
    cout<<"{"<<endl;
    for(int i=0;i<result.size();i++){
        cout<<"{";
        for(int j=0;j<result[i].size();j++){
            cout<<result[i][j]<<" ";
        }
        cout<<"}"<<endl;
    }
    cout<<"}"<<endl;

    return 0;
}