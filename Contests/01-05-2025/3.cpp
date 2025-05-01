#include <iostream>
#include <vector>
using namespace std;

int main()
{
    int t;
    cin>>t;
    while(t--){
        int e,n;
        cin>>n;
        vector<int> arr;
        for(int i=0;i<n;i++){
            cin>>e;
            if(i!=0 && e==arr.back()) continue;
            arr.push_back(e);
        }
        int a=0;
        n=arr.size();
        if(n==1){
            cout<<n<<endl;
            continue;
        }
        if(arr[0]>arr[1]) a++;
        if(arr[n-1]>arr[n-2]) a++;
        for(int i=1;i<n-1;i++){
            if(arr[i]>arr[i-1] && arr[i]>arr[i+1]) a++;
        }
        cout<<a<<endl;
    }
    return 0;
}