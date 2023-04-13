#include <iostream>
#include <string>
#include <unordered_map>
using namespace std;

int main()
{
    string str,ptr;
    int window_start=0,window_end,i,temp=0,flag=1;
    unordered_map <char,int> map;
    cout<<"Enter the string : ";
    cin>>str;
    cout<<"Enter the pattern : ";
    cin>>ptr;
    for(i=0;i<ptr.length();i++){
        char char_ptr=ptr[i];
        map[char_ptr]++;
    }
    for(window_end=0;window_end<str.length();window_end++){
        char right_char=str[window_end];
        if(map.find(right_char)!=map.end()){
            map[right_char]--;
            if(map[right_char]==0){
                temp++;
            }
        }
        if(temp==(int)map.size()){
            cout<<"TRUE";
            flag=0;
            break;
        }
        if(window_end>=ptr.length()-1){
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
    if(flag){
        cout<<"False";
    }
    return 0;
}