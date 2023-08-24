#include <iostream>
#include <limits>
using namespace std;
void countsort(int* arr,int n){
    int m=INT_MIN;
    int i,j;
    for(i=0;i<n;i++){
        m=max(m,arr[i]);
    }
    int *count = new int[m+1];
    for(i=0;i<m+1;i++){
        count[i]=0;
    }
    for(i=0;i<n;i++){
        count[arr[i]]=count[arr[i]]+1;
    }
    i=0;
    j=0;
    while(i<=m){
        if(count[i]>0){
            arr[j]=i;
            count[i]--;
            j++;
        }
        else{
            i++;
        }
    }
}
int main()
{
    int n=7;
    int arr[n]={3,1,9,7,1,2,4};
    countsort(arr,n);
    for(int i=0;i<n;i++){
        cout<<arr[i]<<" ";
    }
    return 0;
}