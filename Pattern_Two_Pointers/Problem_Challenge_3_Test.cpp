#include <iostream>
#include <vector>
#include <limits>
using namespace std;

int main()
{
    int left=0,right,n,element,min_element=numeric_limits<int>::max(),max_element=numeric_limits<int>::min(),ans;
    vector <int> arr;
    cout<<"Enter the number of elements you want to enter : ";
    cin>>n;
    for(int i=0;i<n;i++){
        cout<<"Enter the element at the "<<i<<"th position : ";
        cin>>element;
        arr.push_back(element);
    }
    ans=n;
    right=n-1;
    while(arr[left]<=arr[left+1]&&left<n-1)
        left++;
    if(left==n-1)
        ans=0;
    while(arr[right]>=arr[right-1]&&right>0)
        right--;
    for(int i=left;i<=right;i++){
        max_element=max(max_element,arr[i]);
        min_element=min(min_element,arr[i]);
    }
    while(left>0&&arr[left-1]>min_element)
        left--;
    while(right<n-1&&arr[right+1]<max_element)
        right++;
    if(ans==0)
        cout<<ans;
    else{
        ans=right-left+1;
        cout<<ans;
    }
    return 0;
}