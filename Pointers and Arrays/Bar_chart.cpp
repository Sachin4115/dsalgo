#include <iostream>
using namespace std;

int main()
{
    int n = 5 ;
    int arr[n] = {3,1,0,7,5};
    int m=-1;
    for(int i=0;i<n;i++){
        m=m>arr[i]?m:arr[i];
    }
    for(int i=m;i>0;i--){
        for(int j=0;j<n;j++){
            if(arr[j]>=i){
                cout<<"* ";
            }else{
                cout<<"  ";
            }
        }
        cout<<endl;
    }
    return 0;
}