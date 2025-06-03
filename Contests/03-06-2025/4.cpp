#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int f[11] = {1,1,2,3,5,8,13,21,34,55,89};

int main()
{
    int t;
    cin>>t;
    while(t--){
        int n,m;
        cin>>n>>m;
        vector<int> arr(m);
        for(int i=0;i<m;i++) cin>>arr[i];
        sort(arr.begin(),arr.end());
        bool f=n%2;
        for(int i=0;i<n/2;i++){
            for(int j=0;j<3;j++){
                cout<<arr[i]<<" "<<arr[m-i-1]<<" ";
            }
            cout<<endl;
            for(int j=0;j<3;j++){
                cout<<arr[m-i-1]<<" "<<arr[i]<<" ";
            }
            cout<<endl;
        }
        int i=(n/2);
        if(f){
            for(int j=0;j<3;j++){
                cout<<arr[i]<<" "<<arr[m-i-1]<<" ";
            }
            cout<<endl;
        }
    }
    return 0;
}