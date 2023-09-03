#include <iostream>
#include <string>
#include <vector>
using namespace std;
void countsort(vector <string> &arr,int e,int m,int r){
    vector<int> count(r);
    for(int i=0;i<arr.size();i++){
        int j=((stoi(arr[i]))/e)%m;
        count[j]++;
    }
    for(int i=1;i<r;i++){
        count[i]=count[i]+count[i-1];
    }
    vector <string> ans(arr.size());
    for(int i=arr.size()-1;i>=0;i--){
        int val=((stoi(arr[i]))/e)%m;
        int ind=count[val];
        ans[ind-1]=arr[i];
        count[val]--;
    }
    for(int i=0;i<arr.size();i++){
        arr[i]=ans[i];
    }
}

void radiaxsort(vector <string> &arr){
    countsort(arr,1000000,100,32);
    countsort(arr,10000,100,13);
    countsort(arr,1,10000,2501);
}

int main()
{
    vector <string> arr={"12041996","20101996","05061997","12041989","11081987"};
    radiaxsort(arr);
    for(auto i : arr){
        cout<<i<<" ";
    }
    return 0;
}