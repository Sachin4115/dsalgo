#include <iostream>
#include <vector>
#include <set>
using namespace std;
void DC (vector <int> &arr,set <vector<int>> &ans,int length,vector <int> &comb,int k,int p){
    if(k==length){
        ans.insert(comb);
        return;
    }
    for(int i=p+1;i<arr.size();i++){
        comb.push_back(arr[i]);
        DC(arr,ans,length,comb,k+1,i);
//**
        comb.pop_back();
    }
}
void printvec(vector<int> vec){
        cout<<"[";
    for(int i=0;i<vec.size();i++){
        cout<<vec[i]<<" ";
    }
        cout<<"]\t";
    return;
}
int main()
{
    vector <int> arr;
    set <vector<int>> ans;
    vector <int> comb;
    int n,element,length;
    cout<<"Enter the number of elements you want in the array : ";
    cin>>n;
    for(int i=0;i<n;i++){
        cout<<"Enter the element at the "<<i<<"th position : ";
        cin>>element;
        arr.push_back(element);
    }
    cout<<"Enter the length of the combinations : ";
    cin>>length;
    DC(arr,ans,length,comb,0,-1);
    for(auto it = ans.begin();it != ans.end(); it++){
        printvec(*it);
    }
    return 0;
}