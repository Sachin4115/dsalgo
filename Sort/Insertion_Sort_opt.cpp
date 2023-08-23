#include <iostream>
using namespace std;

int main()
{
    int i,j,temp,n=7;
    int arr[n]={12,45,23,51,19,8,32};
    for(i=1;i<n;i++){
        int current = arr[i];
        j=i-1;
        while(current<arr[j]&&j>=0){
            arr[j+1]=arr[j];
            // temp=arr[j];
            // arr[j]=arr[i];
            // arr[i]=temp;
            j--;
            // i--;
        }
        arr[j+1]=current;
    }
    for(i=0;i<n;i++){
        cout<<arr[i]<<",";
    }
    return 0;
}