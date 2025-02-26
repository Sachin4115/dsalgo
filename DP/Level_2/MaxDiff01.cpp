#include <iostream>
#include <vector>
using namespace std;

// Kadane's Implementation
int main()
{
    string s = "11000010001";
    int a=0,ans=-1;
    for(char i:s){
        if(i=='1') a--;
        else a++;
        ans=max(ans,a);
        if(a<0) a=0;
    }
    cout<<ans;
    return 0;
}