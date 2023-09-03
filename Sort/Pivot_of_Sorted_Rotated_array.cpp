#include <iostream>
#include <vector>
using namespace std;

int main()
{
    int i,element,n,s,m,e;
    cin>>n;
    vector<int> arr;
    for(i=0;i<n;i++){
        cin>>element;
        arr.push_back(element);
    }
    s=0;
    e=n-1;
    m=s+e;
    m/=2;
    while(s<e){
        if(arr[m]>arr[e]){
            s=m+1;
        }
        else{
            e=m;
        }
        m=(s+e)/2;
    }
    cout<<arr[m];
    return 0;
}