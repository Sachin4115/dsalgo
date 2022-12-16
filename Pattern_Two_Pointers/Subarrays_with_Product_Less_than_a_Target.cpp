#include <iostream>
#include <vector>
using namespace std;

int main()
{
    int left=0,right=0,n,element,product,p=1;
    vector<int> arr;
    cout<<"Enter the number of terms in the array : ";
    cin>>n;
    vector<int> arr_result;
    for(int i=0;i<n;i++){
        cout<<"Enter the number at "<<i<<"th position : ";
        cin>>element;
        arr.push_back(element);
    }
    cout<<"Enter the product : ";
    cin>>product;
    while(left<=n-1){
            p*=arr[right];
            if(p<product){
                arr_result.push_back(arr[right]);
                cout<<"[";
                for(int i=0;i<arr_result.size();i++){
                    cout<<arr_result[i]<<" ";
                }
                cout<<"] ";
                right++;
                if(right>n-1){
                    arr_result.clear();
                    left++;
                    p=1;
                    right=left;
                }
            }
            else{
                arr_result.clear();
                left++;
                p=1;
                right=left;
            }
    }
    return 0;
}