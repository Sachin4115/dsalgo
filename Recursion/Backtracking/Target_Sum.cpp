#include <iostream>
#include <vector>
using namespace std;

void Target_Sum(vector<int> &arr,vector<int> &ans,int Tsum,int i){
    if(i==arr.size()){
        if(Tsum==0){
            for(auto el : ans){
                cout<<el<<" ";
            }
            cout<<endl;
        }
        return;
    }
    ans.push_back(arr[i]);
    Target_Sum(arr,ans,Tsum-arr[i],i+1);
    ans.pop_back();
    Target_Sum(arr,ans,Tsum,i+1);
}

int main()
{
    int n,element,Tsum;
    vector<int> arr;
    vector<int> ans;
    cout<<"Enter the size of array : ";
    cin>>n;
    while(n>0){
        cin>>element;
        arr.push_back(element);
        n--;
    }
    cout<<"Enter the Target sum of array : ";
    cin>>Tsum;
    Target_Sum(arr,ans,Tsum,0);
    return 0;
}