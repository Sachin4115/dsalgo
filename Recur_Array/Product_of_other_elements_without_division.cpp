#include <iostream>
#include <vector>
using namespace std;
int sq(vector <int> &arr,int n,int left){
    if(n==arr.size())
        return 1;
    int curr=arr[n];
    int right=sq(arr,n+1,left*curr);
    arr[n]=left*right;
    return curr*right;
}
int main()
{
    int n,element;
    vector <int> arr;
    cout<<"Enter the number of elements you want to enter : ";
    cin>>n;
    for(int i=0;i<n;i++){
        cout<<"Enter the element in the "<<i<<"th position : ";
        cin>>element;
        arr.push_back(element);
    }
    sq(arr,0,1);
    cout<<"[";
    for(int i=0;i<n;i++)
        cout<<arr[i]<<" ";
    cout<<"]";
    return 0;
}