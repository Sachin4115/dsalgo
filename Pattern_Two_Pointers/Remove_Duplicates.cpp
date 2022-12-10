#include <iostream>
#include <vector>
using namespace std;

int main()
{
    int p1=0,p2=1,n,repeating_digits=0,element;
    vector<int> arr;
    cout<<"Enter the number of terms in the array : ";
    cin>>n;
    for(int i=0;i<n;i++){
        cout<<"Enter the number at "<<i<<"th position : ";
        cin>>element;
        arr.push_back(element);
    }
    while(p2<n){
        if(arr[p1]!=arr[p2]){
            p1=p2;
            p2++;
        }
        else{
            repeating_digits++;
            p2++;
        }
    }
    cout<<n-repeating_digits;
    return 0;
}