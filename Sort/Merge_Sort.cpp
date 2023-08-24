#include <iostream>
using namespace std;
void conquer(int arr[],int start,int mid,int end){
    // int *merged = new int[end-start+1];
    // int index1=start;
    // int index2=mid+1;
    // int x=0;
    // while(index1<=mid && index2<=end){
    //     if(arr[index1]<=arr[index2])
    //         merged[x++]=arr[index1++];
    //     else
    //         merged[x++]=arr[index2++];
    // }
    // while(index1<=mid)
    //     merged[x++]=arr[index1++];
    // while(index2<=end)
    //     merged[x++]=arr[index2++];
    // for(int i=0,j=start;i<sizeof(merged)/sizeof(merged[0]);i++,j++){
    //     arr[j]=merged[i];
    // }
    int n1=mid-start+1;
    int n2=end-mid;

    int a[n1];
    int b[n2];

    for(int i=0;i<n1;i++){
        a[i]=arr[start+i];
    }
    for(int i=0;i<n2;i++){
        b[i]=arr[mid+1+i];
    }
    int index1=0;
    int index2=0;
    int x=start;

    while(index1<n1 && index2<n2){
        if(a[index1]<=b[index2])
            arr[x++]=a[index1++];
        else
            arr[x++]=b[index2++];
    }
    while(index1<n1)
        arr[x++]=a[index1++];
    while(index2<n2)
        arr[x++]=b[index2++];
}
void divide(int arr[],int start,int end){
    if(start>=end)
        return;
    // ********************
        int mid=start+(end-start)/2; /*For better space complexity*/
    // ********************
    divide(arr,start,mid);
    divide(arr,mid+1,end);
    conquer(arr,start,mid,end);
}
int main()
{
    int n=6;
    int arr[n]={6,3,9,5,2,8};
    divide(arr,0,n-1);
    for(int i=0;i<n;i++){
        cout<<arr[i]<<" ";
    }
    return 0;
}