#include <iostream>
#include <vector>
using namespace std;

int main()
{
    int n;
    cin>>n;
    int i,j,element;
    vector <int> arr;
    for(i=0;i<n;i++){
        cin>>element;
        arr.push_back(element);
    }
    i=0;
    j=0;
    while(i<arr.size()){
        if(arr[i]){
            i++;
        }
        else{
            element=arr[i];
            arr[i]=arr[j];
            arr[j]=element;
            i++;
            j++;
        }
    }
    for(int i : arr)
        cout<<i<<" ";
    return 0;
}