#include <iostream>
#include <vector>
using namespace std;

int main()
{
    int left=0,right,n,element,temp=0;
    vector <int> arr;
    cout<<"Enter the number of elements in the array : ";
    cin>>n;
    right=n-1;
    for(int i=0;i<n;i++){
        cout<<"Enter the element of the "<<i<<"th position in the array : ";
        cin>>element;
        arr.push_back(element);
    }
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
    cout<<"[";
    for(int i=0;i<n;i++){
        cout<<arr[i]<<" ";
    }
    cout<<"]";
    return 0;
}