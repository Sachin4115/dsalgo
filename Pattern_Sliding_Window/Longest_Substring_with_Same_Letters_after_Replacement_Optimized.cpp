#include <iostream>
#include <string>
#include <unordered_map>
using namespace std;

int main()
{
    int window_start=0,window_end,max_length=0,temp=0,k;
    string str;
    unordered_map <char,int> map;
    cout<<"Enter the string : ";
    cin>>str;
    cout<<"Enter the maximum number of times the letters can be replaced : ";
    cin>>k;
    for(window_end=0;window_end<str.length();window_end++){
        char right_char=str[window_end];
        map[right_char]++;
        temp=max(temp,map[right_char]);
        if(window_end-window_start+1-temp>k){
            char left_char=str[window_start];
            map[left_char]--;
            window_start++;
        }
        max_length=max(max_length,window_end-window_start+1);
    }
    cout<<max_length;
    return 0;
}