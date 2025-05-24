#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int main()
{
    int t;
    cin>>t;
    while(t--){
        string s;
        cin>>s;
        int a=0,b=0;
        bool f=1;
        for(char c:s){
            if(c=='(') a++;
            else b++;
        }
        int l=0,r=0;
        for(char c:s){
            if(c=='(') l++;
            else r++;
            if(r<b && l-r-1<0){
                cout<<"YES"<<endl;
                f=0;
                break;
            }
        }
        if(f) cout<<"NO"<<endl;
    }
    return 0;
}