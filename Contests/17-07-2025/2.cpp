#include <iostream>
#include <vector>
using namespace std;

int main()
{
    int t;
    cin>>t;
    while(t--){
        int n, k;
        cin>>n>>k;
        int arr[n];
        for(int i=0;i<n;i++) cin>>arr[i];
        int ans=0;
        int a=-1,b=-1;
        for(int i=0;i<n;i++){
            if(arr[i]==0){
                if(a==-1) a=i;
                b=i;
            }else{
                if(b!=-1){
                    int t=b-a+2;
                    ans+= (t/(k+1));
                }
                a=-1;
                b=-1;
            }
        }
        if(b!=-1){
            int t=b-a+2;
            ans+= (t/(k+1));
        }
        cout<<"       "<<ans<<endl;
    }
    return 0;
}