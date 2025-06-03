#include <iostream>
#include <vector>
using namespace std;

int f[11] = {1,1,2,3,5,8,13,21,34,55,89};

int main()
{
    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        vector<int> arr(n);
        vector<vector<int>> freq;
        int c=1;
        for(int i=0;i<n;i++){
            cin>>arr[i];
            if(i!=0){
                if(i==n-1){
                    if(arr[i]!=arr[i-1]){
                        freq.push_back({arr[i-1],c});
                        freq.push_back({arr[i],1});
                    }else{
                        freq.push_back({arr[i],c+1});
                    }
                }
                else if(arr[i]!=arr[i-1]){
                    freq.push_back({arr[i-1],c});
                    c=1;
                }else{
                    c++;
                }
            }
        }
        long long cost=LLONG_MAX;
        for(vector<int> a:freq){
            cost=min(cost,a[0]*1LL*(n-a[1]));
        }
        cout<<cost<<endl;
    }
    return 0;
}