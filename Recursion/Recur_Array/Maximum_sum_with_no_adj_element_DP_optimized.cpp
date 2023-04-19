#include <iostream>
#include <vector>
//Dynamic Programing Optimized
using namespace std;
int max_sum(vector <int> &arr,int n){
    int l1,l2;
    l1=arr[0];
    l2=max(arr[0],arr[1]);
    for(int i=2;i<n;i++){
        int t=l2;
        l2=max(l2,l1+arr[i]);
        l1=t;
        l2=max(l2,arr[i]);
    }
    return l2;
}
int main()
{
    vector <int> arr;
    int n,element;
    cout<<"Enter the number of elements in the array : ";
    cin>>n;
    for(int i=0;i<n;i++){
        cout<<"Enter the element in the "<<i<<"th position : ";
        cin>>element;
        arr.push_back(element);
    }
    int S=max_sum(arr,n);
    cout<<S;
    return 0;
}