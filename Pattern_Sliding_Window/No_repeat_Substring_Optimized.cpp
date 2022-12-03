#include<iostream>
#include<string>
#include<unordered_map>

using namespace std;
int main(){
    int window_start=0,window_end,max_length;
    string str;
    unordered_map <char,int> map;
    cout<<"Enter the string : ";
    cin>>str;
    for(window_end=0;window_end<str.length();window_end++){
        char right_char = str[window_end];
        if(map.find(right_char) != map.end()){
            window_start=max(window_start,map[right_char]+1);
        }
        map[right_char]=window_end;
        max_length=max(max_length,window_end-window_start+1);
    }
    cout<<max_length;
}