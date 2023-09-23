#include <bits/stdc++.h>
using namespace std;
string transform(string s);

int main(){
    int t;
    cin >> t;
    while(t--){
        string s;
        cin >> s;
        cout << transform(s) << endl;
    }
return 0;
}
string transform(string s){
    for(auto &x:s)
        x=tolower(x);
    string ans="";
    for(int i=0;i<s.length();i++){
        int count=1;
        while(s[i]==s[i+1]){
            i++;
            count++;
        }
        ans+=to_string(count);
        ans+=s[i];
    }
    return ans;
}
