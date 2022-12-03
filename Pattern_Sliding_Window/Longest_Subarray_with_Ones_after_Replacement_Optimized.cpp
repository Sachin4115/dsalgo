#include <iostream>
#include <vector>
using namespace std;

int main()
{
    int window_end,max_length=0,window_start=0,noof1=0,k,n,element;
    vector<int> arr;
    cout<<"Enter the value of the maximum replacements : ";
    cin>>k;
    cout<<"Enter the number of elements in the array : ";
    cin>>n;
    for(int i=0;i<n;i++){
        cout<<"Enter the element at "<<i<<" position : ";
        cin>>element;
        arr.push_back(element);
    }
    for(window_end=0;window_end<n;window_end++){
        if(arr[window_end]==1){
            noof1++;
        }
        if(window_end-window_start+1-noof1>k){
            if(arr[window_start]==1){
                noof1--;
            }
            window_start++;
        }
        max_length=max(max_length,window_end-window_start+1);
    }
    cout<<max_length;
    return 0;
}