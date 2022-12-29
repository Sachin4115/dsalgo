#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main()
{
    int left,right,n,element, Sum;
    vector<int> arr;
    vector<int> ans;
    cout<<"Enter the number of terms you want to add in the array : ";
    cin>>n;
    // left =0;
    // right=n-1;
    for(int i=0;i<n;i++){
        cout<<"Enter the element at the "<<i<<"th postion : ";
        cin>>element;
        arr.push_back(element);
    }
    cout<<"Enter the target sum : ";
    cin>>Sum;
    sort(arr.begin(),arr.end());
    for(int i=0;i<n-3;i++){
        if(i>0&&arr[i]==arr[i-1]){
            continue;
        }
        ans.clear();
        for(int j=i+1; j<n-2;j++){
        if(j>0&&arr[j]==arr[j-1]){
            continue;
        }
        left=j+1;
        right=n-1;
        int Tsum=Sum-arr[i]-arr[j];
        while(left<right){
            int sum=arr[left]+arr[right];
            ans.clear();
            if(Tsum==sum){
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
                while(sum<Tsum&&arr[left]==arr[left-1]){
                    left++;
                }
                while(sum>Tsum&&arr[right]==arr[right+1]){
                    right--;
                }
            }
            else if(Tsum>sum){
                left++;
            }
            else{
                right--;
            }
        }
    }
    }
    return 0;
}