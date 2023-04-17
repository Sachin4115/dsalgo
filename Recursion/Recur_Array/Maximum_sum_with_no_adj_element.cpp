#include <iostream>
#include <vector>
#include <climits>
using namespace std;
int max_sum(vector <int> &arr,int n,int i,int p){
    if(i==n)
        return 0;
        int inc=0;
    if(p+1!=i)
        inc=arr[i]+max_sum(arr,n,i+1,i);
    int exc=max_sum(arr,n,i+1,p);
    return max(inc,exc);
}
int main()
{
    vector <int> arr;
    int n,element;
    cout<<"Enter the number of elements you want to add in the array :";
    cin>>n;
    for(int i=0;i<n;i++){
        cout<<"Enter the element at the "<<i<<"th position : ";
        cin>>element;
        arr.push_back(element);
    }
    int S=max_sum(arr,n,0,INT_MIN);
    cout<<S;
    return 0;
}