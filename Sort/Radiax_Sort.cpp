#include <iostream>
#include <climits>
using namespace std;
void countsort(int* arr,int n,int e){
    int i;
    int *count = new int[10];
    for(i=0;i<n;i++){
        count[((arr[i]/e)%10)]++;
    }
    for(i=1;i<n;i++){
        count[i]=count[i]+count[i-1];
    }
    int ans[n];
    for(i=n-1;i>=0;i--){
        int val=(arr[i]/e)%10;
        int ind=count[val];
        ans[ind-1]=arr[i];
        count[((arr[i]/e)%10)]--;
    }
    for(int i=0;i<n;i++){
        arr[i]=ans[i];
    }
}

void radiaxsort(int* arr,int n){
    int m=INT_MIN;
    for(int i=0;i<n;i++){
        if(arr[i]>m){
            m=arr[i];
        }
    }
    int e=1;
    while(e<=m){
        countsort(arr,n,e);
        e*=10;
    }
}

int main()
{
    int n=10;
    int arr[n]={213,97,718,123,37,443,982,64,375,683};
    radiaxsort(arr,n);
    for(int i=0;i<n;i++){
        cout<<arr[i]<<" ";
    }
    return 0;
}