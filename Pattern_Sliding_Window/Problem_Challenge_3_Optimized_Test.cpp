#include <iostream>
#include <string>
#include <unordered_map>
using namespace std;

int main()
{
    int window_start=0,window_end,temp=0,start,length;
    string str,ptr,ans="";
    unordered_map <char,int> map;
    cout<<"Enter the string : ";
    cin>>str;
    cout<<"Enter the pattern : ";
    cin>>ptr;
    length=str.length()+1;
    for(int i=0;i<ptr.length();i++){
        char ptr_char = ptr[i];
        map[ptr_char]++;
    }
    for(window_end=0;window_end<str.length();window_end++){
        char right_char=str[window_end];
        if(map.find(right_char)!=map.end()){
            map[right_char]--;
            if(map[right_char]==0){
                temp++;
            }
        }
        while(temp==ptr.length()){
            if(length>window_end-window_start+1){
                length=window_end-window_start+1;
                start=window_start;
            }
            char left_char=str[window_start];
            if(map.find(left_char)!=map.end()){
                if(map[left_char]==0){
                    temp--;
                }
                map[left_char]++;
            }
            window_start++;
        }
    }
    if(length<str.length())
        ans=str.substr(start,length);
    cout<<ans;
    return 0;
}