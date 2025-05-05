#include <iostream>
#include <vector>
using namespace std;

// To Do: Up Solve 1023 Div 2

int main()
{
    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        vector<int> arr(n);
        long long ans=0;
        for(int i=0;i<n;i++) cin>>arr[i];
        for(int i=n-1;i>=0;i--){
            int c=arr[i];
            int t=i;
            for(int j=i-1;j>=0 && i-j+1<c;j--){
                if(i-j+arr[j]<c){
                    // swap(arr[i],arr[j]);
                    t=j;
                    c=i-j+arr[j];
                    // ans+=(i-j);
                }
            }
            for(int j=i+1;j<n&& j-i+1<c;j++){
                if(j-i+arr[j]<c){
                    // swap(arr[i],arr[j]);
                    t=j;
                    c=j-i+arr[j];
                    // ans+=(j-i);
                    // break;
                }
            }
            swap(arr[t],arr[i]);
            ans+=abs(t-i);
            ans+=arr[i];
            cout<<ans<<endl;
        }
        cout<<ans<<endl;
    }
    return 0;
}