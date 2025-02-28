#include <iostream>
using namespace std;

int main()
{
    vector<int> arr={2, 3, 5, 8};
    int n = arr.size();
    long long l=4,r=13;
    long long c1=0,c2=0;
    int l=0;
    long long sum=0;
    for(int i=0;i<n;i++){
        sum+=arr[i];
        while(sum>R){
            sum-=arr[l];
            l++;
        }
        c1+=(i-l+1);
    }
    l=0;
    sum=0;
    for(int i=0;i<n;i++){
        sum+=arr[i];
        while(sum>L-1){
            sum-=arr[l];
            l++;
        }
        c2+=(i-l+1);
    }

    cout<<c1-c2;
    return 0;
}