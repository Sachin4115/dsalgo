#include <iostream>
#include <string>
#include <vector>
#include <unordered_map>
using namespace std;

int main()
{
    int n,size,sub_index;
    vector <int> ans;
    vector <string> arr;
    string element,sub,str;
    unordered_map <string,int> map;
    cout<<"Enter the string : ";
    cin>>str;
    cout<<"Enter the number of elements you want to enter : ";
    cin>>n;
    for(int i=0;i<n;i++){
        cout<<"Enter the element at "<<i<<"th position : ";
        cin>>element;
        arr.push_back(element);
    }
    size=arr[0].length();
    for(auto word : arr){
        map[word]++;
    }
    for(int i=0;i<=str.length()-size*n;i++){
        unordered_map <string,int> mapseen;
        for(int j=0;j<n;j++){
            sub_index=i+j*size;
            sub=str.substr(sub_index,size);
            if(map.find(sub)==map.end()){
                break;
            }
            mapseen[sub]++;
            if(mapseen[sub]>map[sub]){
                break;
            }
            if(j+1==n){
                ans.push_back(i);
            }
        }
    }
    cout<<"[";
    for(int i=0;i<ans.size();i++)
        cout<<ans[i]<<" ";
    cout<<"]";
    return 0;
}