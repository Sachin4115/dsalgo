#include <iostream>
#include <vector>
using namespace std;

int main()
{
    int left=0,right,sl,sr,n,element,result_index;
    vector<int> arr;
    cout<<"Enter the number of terms in the array : ";
    cin>>n;
    vector<int> arr_result(n);
    for(int i=0;i<n;i++){
        cout<<"Enter the number at "<<i<<"th position : ";
        cin>>element;
        arr.push_back(element);
    }
    right=n-1;
    result_index=n-1;
    while(left<=right){
        sl=arr[left]*arr[left];
        sr=arr[right]*arr[right];
        if(sl>sr){
            arr_result[result_index--]=sl;
            left++;
        }
        else{
            arr_result[result_index--]=sr;
            right--;
        }
    }
    for(int i=0;i<n;i++){
        cout<<arr_result[i]<<" ";
    }
    return 0;
}