#include <iostream>
#include <vector>
using namespace std;

int main()
{
    vector <int> arr;
    int n;
    cout<<"Enter the number of terms in the array : ";
    cin>>n;
    for(int i=0;i<n;i++){
        cout<<"Enter the number at "<<i<<"th position : ";
        int element;
        cin>>element;
        arr.push_back(element);
    }
    int target_sum,start=0,stop=arr.size()-1;
    cout<<"Enter the target sum : ";
    cin>>target_sum;
    while(arr[start]+arr[stop]!=target_sum){
        if((arr[start]+arr[stop])>target_sum){
            stop--;
        }
        else if((arr[start]+arr[stop])<target_sum){
            start++;
        }
    }
        cout<<"The required numbers are at the indexes "<<start<<" and "<<stop;
    return 0;
}