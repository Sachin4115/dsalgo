#include <iostream>
#include <vector>
#include <limits>
#include <algorithm>
using namespace std;

int main()
{
    int left,right,n,element,mins = numeric_limits<int>::max(),Tsum,flag=1;
    vector<int> arr;
    vector<int> ans;
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
        if(i>0&&arr[i]==arr[i-1]){
            continue;
        }
        ans.clear();
        left=i+1;
        right=n-1;
        while(left<right){
            int sum=arr[left]+arr[right]+arr[i];
            // ans.clear();
            if(Tsum==sum){
                cout<<Tsum;
                flag=0;
            }
            else if(abs(Tsum-sum)<abs(mins)){
                mins=min(mins,Tsum-sum);
            }
            if(mins>0){
                left++;
            }
            else{
                right--;
            }
        }
    }
    if(flag){
        cout<<Tsum-mins;
    }
    return 0;
}