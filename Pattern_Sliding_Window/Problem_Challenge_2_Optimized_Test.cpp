#include <iostream>
#include <string>
#include <vector>
#include <unordered_map>
using namespace std;

int main()
{
    int window_start=0,window_end,temp=0;
    string str,ptr;
    unordered_map <char,int> map;
    vector <int> arr;
    cout<<"Enter the string : ";
    cin>>str;
    cout<<"Enter the pattern : ";
    cin>>ptr;
    for(int i=0;i<ptr.length();i++){
        char char_ptr=ptr[i];
        map[char_ptr]++;
    }
    for(window_end=0;window_end<str.length();window_end++){
        char right_char = str[window_end];
        if(map.find(right_char)!=map.end()){
            map[right_char]--;
            if(map[right_char]==0){
                temp++;
            }
        }
        if(temp==(int)map.size()){
            arr.push_back(window_start);
        }
        if(window_end>=ptr.length()-1){
            char left_char = str[window_start];
            if(map.find(left_char)!=map.end()){
                if(map[left_char]==0){
                    temp--;
                }
                map[left_char]++;
            }
            window_start++;
        }
    }
    cout<<"[";
    for(int i=0;i<arr.size();i++){
        cout<<arr[i]<<", ";
    }
    cout<<"]";
    return 0;
}