#include <iostream>
#include <vector>
using namespace std;
int main()
{
    int left=0,right,n,element,temp;
    vector <int> arr;
    cout<<"Enter the number of elements you want to enter : ";
    cin>>n;
    for(int i=0;i<n;i++){
        cout<<"Enter the element in the "<<i<<"th position : ";
        cin>>element;
        arr.push_back(element);
    }
    right=n-1;
    for(int i=0;i<n;i++){
        if(arr[i]==0){
            if(i<=left){
                left++;
                continue;
            }
            temp=arr[left];
            arr[left]=arr[i];
            arr[i]=temp;
            left++;
            i--;
        }
        if(arr[i]==2){
            if(i>=right){
                right--;
                continue;
            }
            temp=arr[right];
            arr[right]=arr[i];
            arr[i]=temp;
            right--;
            i--;
        }
    }
    for(int i=0;i<n;i++){
        cout<<arr[i]<<" ";
    }
    return 0;
}