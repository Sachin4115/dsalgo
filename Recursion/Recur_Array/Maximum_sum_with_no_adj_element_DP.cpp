#include <iostream>
#include <vector>
//Dynamic Programing
using namespace std;
int max_sum(vector <int> &arr,int n){
    int lookup[n];
    lookup[0]=arr[0];
    lookup[1]=max(arr[0],arr[1]);
    for(int i=2;i<n;i++){
        lookup[i]=max(lookup[i-1],lookup[i-2]+arr[i]);
        lookup[i]=max(lookup[i],arr[i]);
    }
    return lookup[n-1];
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