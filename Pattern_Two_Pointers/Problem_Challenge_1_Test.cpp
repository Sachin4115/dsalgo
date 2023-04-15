#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main()
{
    int left,right,n,T_sum,element,sum;
    vector <int> arr,ans;
    cout<<"Enter the number of elements you want to enter in the array : ";
    cin>>n;
    for(int i=0;i<n;i++){
        cout<<"Enter the element in the "<<i<<"th postion : ";
        cin>>element;
        arr.push_back(element);
    }
    cout<<"Enter the target sum : ";
    cin>>T_sum;
    sort(arr.begin(),arr.end());
    for(int i=0;i<n-3;i++){
        if(arr[i]==arr[i-1])
            continue;
        ans.clear();
        for(int j=i+1;j<n-2;j++){
            if(arr[j]==arr[j-1])
                continue;
            left=j+1;
            right=n-1;
            sum=T_sum-arr[i]-arr[j];
            while(left<right){
                ans.clear();
                if(arr[left]+arr[right]==sum){
                    ans.push_back(arr[i]);
                    ans.push_back(arr[j]);
                    ans.push_back(arr[left]);
                    ans.push_back(arr[right]);
                    cout<<"[";
                    for(auto num : ans){
                        cout<<num<<" ";
                    }
                    cout<<"]"<<endl;
                    left++;
                    right--;
                    while(left<right&&arr[left]==arr[left-1])
                        left++;
                    while(left<right&&arr[right]==arr[right+1])
                        right--;
                }
                else if(arr[left]+arr[right]<sum)
                    left++;
                else
                    right--;
            }
        }
    }
    return 0;
}