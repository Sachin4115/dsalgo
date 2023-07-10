#include <iostream>
#include <vector>
#include <set>
#include <algorithm>
using namespace std;
void printvec(vector<int> vec){
        cout<<"[";
    for(int i=0;i<vec.size();i++){
        cout<<vec[i]<<" ";
    }
        cout<<"]\t";
    return;
}
void DC(vector <int> arr,set <vector<int>> &ans,int length,vector <int> comb,int p){
        if(length == 0){
            ans.insert(comb);
            return;
        }
        for(int i=p;i<arr.size();i++){
            while(i!=p&&arr[i]==arr[p]){
                i++;
            }
            comb.push_back(arr[i]);
            DC(arr,ans,length-1,comb,i);
            comb.pop_back();
        }
}
int main()
{
    vector <int> arr;
    vector <int> comb;
    set <vector<int>> ans;
    int n,element,length;
    cout<<"Enter the number of elements you want in the array : ";
    cin>>n;
    for(int i=0;i<n;i++){
        cout<<"Enter the element at the "<<i<<"th position : ";
        cin>>element;
        arr.push_back(element);
    }
    sort(arr.begin(),arr.end());
    cout<<"Enter the length of the combinations : ";
    cin>>length;
    DC(arr,ans,length,comb,0);
    for(auto it=ans.begin();it!=ans.end();it++){
        printvec(*it);
    }
    return 0;
}