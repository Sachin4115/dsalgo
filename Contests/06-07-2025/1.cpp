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
        vector<int> arr(n),copy;
        // bool b=true;
        for(int i=0;i<n;i++){
            cin>>arr[i];
        }
        copy=arr;
        sort(copy.begin(),copy.end());
        vector<int> c;
        for(int i=0;i<n;i++){
            if(arr[i]!=copy[i]){
                c.push_back(arr[i]);
            }
        }
        if(c.size()==0) cout<<"No"<<endl;
        else{
            cout<<"Yes"<<endl<<c.size()<<endl;
            for(int i=0;i<c.size();i++) cout<<c[i]<<" ";
            cout<<endl;
        }

    }
    return 0;
}