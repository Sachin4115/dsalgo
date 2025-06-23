#include <iostream>
using namespace std;

int main()
{
    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        int arr[n];
        for(int i=0;i<n;i++) cin>>arr[i];
        bool f=0;
        for(int i=0;i<n-1;i++){
            if(abs(arr[i]-arr[i+1])<=1){
                cout<<0<<endl;
                f=1;
                break;
            }
        }
        if(f) continue;
        if(n==2){
            cout<<-1<<endl;
            continue;
        }
        f=0;
        for(int i=0;i<n-2;i++){
            if(arr[i+2]>=min(arr[i],arr[i+1]) && arr[i+2]<=max(arr[i],arr[i+1])){
                f=1;
                cout<<1<<endl;
                break;
            }
        }
        if(f) continue;
        for(int i=2;i<n;i++){
            if(arr[i-2]>=min(arr[i],arr[i-1]) && arr[i-2]<=max(arr[i],arr[i-1])){
                f=1;
                cout<<1<<endl;
                break;
            }
        }
        if(f) continue;
        cout<<-1<<endl;
    }
    return 0;
}