#include <iostream>
#include <vector>
using namespace std;

int main()
{
    int element,left=0,right,n,t_sum;
    vector <int> arr;
    cout<<"Enter the number of elements in the sorted array : ";
    cin>>n;
    for(int i=0;i<n;i++){
        cout<<"Enter the element in the "<<i<<"th postion if the sorted array : ";
        cin>>element;
        arr.push_back(element);
    }
    cout<<"Enter the value of the target sum : ";
    cin>>t_sum;
    right=n-1;
    while(left<right){
        if(arr[left]+arr[right]==t_sum){
            cout<<"["<<left<<", "<<right<<"]"<<endl;
            left++;
        }
        else if(arr[left]+arr[right]>t_sum)
            right--;
        else
            left++;
    }
    return 0;
}