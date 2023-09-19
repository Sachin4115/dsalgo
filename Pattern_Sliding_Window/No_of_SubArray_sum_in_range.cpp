// Given an array A[] of N integers and a range(L, R). The task is to find the number of
// subarrays having sum in the range L to R (inclusive).

#include<iostream>
#include<vector>
using namespace std;

class Solution {
  public:
    long long countSubarray(int N,vector<int> A,long long L,long long R) {
        long long sum=0,ans;
        int s=0,e=0;
        long long count1=0,count2=0;
        for(e=0;e<N;e++){
            sum+=A[e];
            while(sum>R){
                sum-=A[s];
                s++;
            }
            count1+=(e-s+1);
        }
        sum=0;
        s=0;
        for(e=0;e<N;e++){
            sum+=A[e];
            while(sum>L-1){
                sum-=A[s];
                s++;
            }
            count2+=(e-s+1);
        }
        ans=count1-count2;
        return ans;
    }
};

int main(){
    int t;
    cin>>t;
    while(t--){
        int N;
        long long L,R;
        cin>>N>>L>>R;
        vector<int> A(N);
        for(int i=0;i<N;i++){
            cin>>A[i];
        }
        Solution obj;
        auto ans = obj.countSubarray(N,A,L,R);
        cout<<ans<<endl;
    }
    return 0;
}