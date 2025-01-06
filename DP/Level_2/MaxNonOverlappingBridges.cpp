#include <iostream>
using namespace std;

void merge(int arr[][2], int s , int m, int e){
    int n1 = m-s+1, n2 = e-m;
    int a[n1][2],b[n2][2];
    for(int i=0;i<n1;i++){
        a[i][0]=arr[s+i][0];
        a[i][1]=arr[s+i][1];
    }
    for(int i=0;i<n2;i++){
        b[i][0]=arr[m+1+i][0];
        b[i][1]=arr[m+1+i][1];
    }
    int i=0,j=0,k=s;
    while(i<n1 && j<n2){
        if(a[i][0]>b[j][0]){
            arr[k][0]=b[j][0];
            arr[k++][1]=b[j++][1];
        }else if(a[i][0]<b[j][0]){
            arr[k][0]=a[i][0];
            arr[k++][1]=a[i++][1];
        }else{
            if(a[i][1]>b[j][1]){
                arr[k][0]=b[j][0];
                arr[k++][1]=b[j++][1];
            }else if(a[i][1]<b[j][1]){
                arr[k][0]=a[i][0];
                arr[k++][1]=a[i++][1];
            }
        }
    }
    while(i<n1){
        arr[k][0]=a[i][0];
        arr[k++][1]=a[i++][1];
    }
    while(j<n2){
            arr[k][0]=b[j][0];
            arr[k++][1]=b[j++][1];
    }
}

void mergeSort(int arr[][2], int s, int e){
    if(s>=e) return;
    int m = s+(e-s)/2;
    mergeSort(arr,s,m);
    mergeSort(arr,m+1,e);
    merge(arr,s,m,e);
}
int main()
{
    int n=10,m,ans=0;
    int arr[n][2]={
        {10,20},
        {2,7},
        {8,15},
        {17,3},
        {21,40},
        {50,4},
        {41,57},
        {60,80},
        {80,90},
        {1,30}
    };
    mergeSort(arr,0,n-1);
    for(int i=0;i<n;i++) cout<<arr[i][0]<<" "<<arr[i][1]<<endl;
    int dp[n];
    for(int i=0;i<n;i++){
        m=0;
        for(int j=i-1;j>=0;j--){
            if(arr[i][1]>arr[j][1]) m=max(m,dp[j]);
        }
        dp[i]=m+1;
        ans=max(ans,dp[i]);
    }
    cout<<ans<<endl;
    for(int i=0;i<n;i++) cout<<dp[i]<<" ";
    return 0;
}