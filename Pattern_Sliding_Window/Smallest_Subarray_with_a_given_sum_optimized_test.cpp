#include <iostream>
#include <vector>
using namespace std;
int main()
{
    int window_sum=0,window_start=0,sum,min_length,element,n,window_end,flag=0;
    vector <int> arr;
    cout<<"Enter the value of the sum : ";
    cin>>sum;
    cout<<"Enter the number of elements in the array : ";
    cin>>n;
    for(int i=0;i<n;i++){
        cout<<"Enter the element at "<<i<<"th postion : ";
        cin>>element;
        arr.push_back(element);
    }
    min_length=n;
    for(window_end=0;window_end<n;window_end++){
        window_sum+=arr[window_end];
        while(window_sum>=sum){
            min_length=min(min_length,(window_end-window_start+1));
            flag=1;
            window_sum-=arr[window_start];
            window_start++;
        }
    }
    if(flag)
        cout<<min_length;
    else
        cout<<"0";
    return 0;
}