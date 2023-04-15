#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main()
{
    int left,right,n,element;
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
    sort(arr.begin(),arr.end());
    for(int i=0;i<n-2;i++){
        if(i>0&&arr[i]==arr[i-1]){
            continue;
        }
        ans.clear();
        left=i+1;
        right=n-1;
        int Tsum=-1*arr[i];
        while(left<right){
            int sum=arr[left]+arr[right];
            ans.clear();
            if(Tsum==sum){
                ans.push_back(arr[i]);
                ans.push_back(arr[right]);
                ans.push_back(arr[left]);
                cout<<"[";
                for(auto num : ans){
                    cout<<num<<" ";
                }
                cout<<"]"<<endl;
                left++;
                right--;
                while(left<right&&arr[left]==arr[left-1]){
                    left++;
                }
                while(left>right&&arr[right]==arr[right+1]){
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
    return 0;
}