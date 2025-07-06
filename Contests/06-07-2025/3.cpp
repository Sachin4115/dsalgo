#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main()
{
    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        vector<long long> arr(n);
        for(int i=0;i<n;i++){
            cin>>arr[i];
        }
        long long ans=1;
        for(int i=0;i<n-1;i++){
            if(arr[i+1]%arr[i]!=0){
                long long gcd = __gcd(arr[i+1],arr[i]);
                long long temp = arr[i]/gcd;
                long long gcd2 = __gcd(ans,temp);
                ans = ans/gcd2*temp;
            }
        }
        cout<<"       "<<ans<<endl;
    }
    return 0;
}
