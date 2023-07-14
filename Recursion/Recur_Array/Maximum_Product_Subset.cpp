#include <iostream>
#include <vector>
#include <climits>
using namespace std;
void max_product(vector <int> arr, int n, int consider, int m,int &p){
    if(n==-1)
        return;
    if(arr[n]!=0){
        if(consider==0){
            p*=arr[n];
            max_product(arr,n-1,0,m,p);
        }
        else{
            if(m!=arr[n]){
                p*=arr[n];
                max_product(arr,n-1,1,m,p);
            }
            else
            max_product(arr,n-1,consider,m,p);
        }
    }
    else
        max_product(arr,n-1,consider,m,p);
}
int main()
{
    vector<int> arr;
    int n,negatives=0,m=INT_MIN;
    int p=1;
    cout << "Enter the size of the array : ";
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        cout<<"Enter the element at "<<i<<" position : ";
        int element;
        cin>>element;
        arr.push_back(element);
        if(arr[i]<0){
            negatives++;
            m=max(m,arr[i]);
        }
    }
    max_product(arr,n-1,negatives%2,m,p);
    cout<<p;
    return 0;
}