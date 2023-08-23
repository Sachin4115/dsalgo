#include <iostream>
using namespace std;
int main()
{
    int i,j,temp;
    int arr[7]={12,45,23,51,19,8,32};
    for(i=0;i<7;i++){
        for(j=i+1;j<7;j++){
            if(arr[j]<arr[i]){
                temp=arr[i];
                arr[i]=arr[j];
                arr[j]=temp;
            }
        }
    }
    for(i=0;i<7;i++){
        cout<<arr[i]<<",";
    }
    return 0;
}