#include <iostream>
#include <string>
#include <vector>
#include <unordered_map>
using namespace std;

int main()
{
    int size,n,sub_index,flag=0;
    vector<int> result;
    vector<string> words;
    string element,sub,str;
    unordered_map<string,int> map;
    cout<<"Enter the string : ";
    cin>>str;
    cout<<"Enter the number of words you want to enter : ";
    cin>>n;
    for(int i=0;i<n;i++){
        cout<<"Enter the element at "<<i<<" position : ";
        cin>>element;
        words.push_back(element);
    }
    size=words[0].length();
    for(auto word : words){
        map[word]++;
    }
    for(int i=0;i<=str.length()-n*size;i++){
    /**/unordered_map<string,int> mapseen;
        flag=0;
        // for(auto word : words){
        // map[word]++;
        // }
        for(int j=0;j<n;j++){
            sub_index=i+j*size;
            sub=str.substr(sub_index,size);
            if(map.find(sub)==map.end()){
                break;
            }
            // flag++;
            // map[sub]--;
            // if(map[sub]<0){
            //     break;
            // }
            mapseen[sub]++;
            if(mapseen[sub]>map[sub]){
                break;
            }
            if(j+1==n){
                result.push_back(i);
            }
        }
    }
    for(int i=0;i<result.size();i++){
        cout<<result[i]<<" ";
    }
    return 0;
}