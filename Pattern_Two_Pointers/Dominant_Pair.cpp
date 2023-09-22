#include <bits/stdc++.h>
using namespace std;

class Solution{
public:
    int dominantPairs(int n,vector<int> &arr){
        sort(arr.begin(),arr.begin()+n/2);
        sort(arr.begin()+n/2,arr.end());
        int count=0;
        int l=0,r=n/2;
        while(l<n/2 && r<n){
            if(arr[l]>=5*arr[r]){
                count+=(n/2)-l;
                r++;
            }
            else{
                l++;
            }
        }
        return count;
    }
};

int main(){
    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        vector<int> arr(n);
        for(int i=0;i<n;i++){
            cin>>arr[i];
        }
        Solution ob;
        cout<<ob.dominantPairs(n,arr)<<endl;
    }
}