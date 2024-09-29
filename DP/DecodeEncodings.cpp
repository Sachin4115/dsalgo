#include <iostream>
using namespace std;

int main()
{
    string s = "21123";

    int dp[s.length()];
    dp[0]=1;//string will not start from 0

    for(int i=1;i<s.length();i++){
        int a = s[i-1]-'0', b = s[i]-'0';
        if(a==0 && b==0){
            dp[i]=0;
        }else if(a==0){
            dp[i]=dp[i-1];
        }else if(b==0){
            if((a==1 || a==2)&&i>=2)
                dp[i]=(i>1?dp[i-2]:1);
            else
                dp[i]=0;
        }else{
            dp[i]=dp[i-1];
            int d = (a*10)+b;
            if(d<=26)
                dp[i]+=(i>1?dp[i-2]:1);
        }
    }
    cout<<dp[s.length()-1]<<endl;
    return 0;
}