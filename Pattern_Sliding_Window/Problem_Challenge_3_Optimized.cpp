#include <iostream>
#include <string>
#include <unordered_map>
using namespace std;

int main()
{
    int window_start=0,window_end,start,sub=0,length;
    string str,ptr,subs;
    unordered_map<char,int> map;
    cout<<"Enter the string  : ";
    cin>>str;
    cout<<"Enter the pattern : ";
    cin>>ptr;
    length=str.length()+1;
    for(int i=0;i<ptr.length();i++){
        char ptr_char=ptr[i];
        map[ptr_char]++;
    }
    for(window_end=0;window_end<str.length();window_end++){
        char right_char=str[window_end];
        if(map.find(right_char)!=map.end()){
            map[right_char]--;
            if(map[right_char]>=0){
                sub++;
            }
        }
        while(sub == ptr.length()){
            if(length>window_end-window_start+1){
                length=window_end-window_start+1;
                start=window_start;
            }
            char left_char=str[window_start];
            if(map.find(left_char)!=map.end()){
                if(map[left_char]>=0){
                    sub--;
                }
                map[left_char]++;
            }
            window_start++;
        }
    }
    // str.substr(start,length);
    if(length<str.length()){
        subs=str.substr(start,length);
        cout<<subs;
    }
    else{
        cout<<"This given pattern is not present in the given string";
    }
    return 0;
}