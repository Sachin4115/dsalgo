#include <iostream>
#include <set>
#include <vector>
using namespace std;

int main()
{
    vector<string> wordDict {"loves","pep","coding","pepcoding","ice","cream","icecream","man","go","mangpo"};
    string s = "pepcodinglovesmangoicecream";
    set<string> st;
    for(string a:wordDict) st.insert(a);
    vector<int>dp(s.length(),0);
    for(int i=0;i<s.length();i++){
        for(int j=i;j>=0;j--){
            if(st.find(s.substr(j,i-j+1))!=st.end() ){
                if(j==0) dp[i]++;
                else dp[i]+=dp[j-1];
            }
        }
    }
    cout<< dp[s.length()-1];
    return 0;
}