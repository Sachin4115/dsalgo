#include <iostream>
#include <vector>
#include <limits>
using namespace std;

int main()
{
    int left=0,right,n,element,min_size,min_element=numeric_limits<int>::max(),max_element=numeric_limits<int>::min();
    vector<int> arr;
    cout<<"Enter the number of terms you want in the array : ";
    cin>>n;
    for(int i=0;i<n;i++){
        cout<<"Enter the element of the "<<i<<"th index : ";
        cin>>element;
        arr.push_back(element);
    }
    min_size=n;
    right=n-1;
    while(arr[left]<=arr[left+1]&&left<n-1){
        left++;
    }
    if(left==n-1){
        min_size=0;
    }
    while(arr[right]>=arr[right-1]&&0<right){
        right--;
    }
    for(int i=left;i<=right;i++){
        min_element=min(min_element,arr[i]);
        max_element=max(max_element,arr[i]);
    }
    while(left>0&&arr[left-1]>min_element){
        left--;
    }
    while(right<n-1&&arr[right+1]<max_element){
        right++;
    }
    if(min_size==0){
        cout<<min_size;
    }
    else{
        min_size=right-left+1;
        cout<<min_size;
    }
    return 0;
}