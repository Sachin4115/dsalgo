#include <iostream>
#include <algorithm>
// #include <map>
using namespace std;

int main()
{
    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        int a[n];
        string s = "No";
        // map<int,int>f;
        for(int i=0;i<n;i++) cin>>a[i];
        sort(a,a+n);
        int c=0,q=0;
        for(int i=0;i<n;i++){
            if(i==0){
                q++;
            }
            if(a[i]==a[i-1]){
                if(q==1) c++;
                q++;
                if(c>=2 || q>=4){
                    s = "Yes";
                    break;
                }
            }else{
                q=1;
                if(a[i]-a[i-1]==1) continue;
                c=0;
            }
        }
        cout<<s<<endl;
    }

    return 0;
}