#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main()
{
    int left,right,n,element,count=0,Tsum,sum;
    vector<int> arr;
    cout<<"Enter the number of terms you want to add in the array : ";
    cin>>n;
    for(int i=0;i<n;i++){
        cout<<"Enter the element at the "<<i<<"th postion : ";
        cin>>element;
        arr.push_back(element);
    }
    cout<<"Enter the target sum : ";
    cin>>Tsum;
    sort(arr.begin(),arr.end());
    for(int i=0;i<n-2;i++){
        left=i+1;
        right=n-1;
        while(left<right){
            sum=arr[i]+arr[left]+arr[right];
            if(sum<Tsum){
                count+=right-left;
                left++;
            }
            else{
                right--;
            }
        }
    }
    cout<<count;
    return 0;
}