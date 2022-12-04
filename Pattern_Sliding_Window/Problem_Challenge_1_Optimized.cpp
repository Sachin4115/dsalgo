#include <iostream>
#include <string>
#include <unordered_map>
using namespace std;

int main()
{
    int window_start=0,sub=0,window_end,flag=1;
    string str,pattern;
    unordered_map<char,int> map;
    cout<<"Enter the string  : ";
    cin>>str;
    cout<<"Enter the pattern : ";
    cin>>pattern;
    for(int i=0;i<pattern.length();i++){
        char char_ptr=pattern[i];
        map[char_ptr]++;
    }
    for(window_end=0;window_end<str.length();window_end++){
        char right_char=str[window_end];
        if(map.find(right_char) != map.end()){
            // cout<<" '"<<right_char<<"' ";
            map[right_char]--;
            if(map[right_char]==0){
                sub++;
                // cout<<sub;
            }
        }
        if(sub==(int)map.size()){
            cout<<"True";
            flag=0;
            break;
        }
        if(window_end>=pattern.length()-1){
            char left_char=str[window_start];
            if(map.find(left_char)!=map.end()){
                if(map[left_char]==0){
                    sub--;
                }
                // cout<<left_char;
                map[left_char]++;
            }
            window_start++;
        }
    }
    if(flag){
        cout<<"False";
    }
    return 0;
}