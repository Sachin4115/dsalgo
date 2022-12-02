#include<iostream>
#include<string>
#include<unordered_map>

using namespace std;
int main(){
    char letter_end,letter_start;
    string str;
    int maxlength=0,start=0,stop=0;
    unordered_map<char,int> CharFreq;
    cout<<"Enter the string : ";
    cin>>str;
    for(stop=0;stop<str.length();stop++){
        letter_end=str[stop];
        CharFreq[letter_end]++;
        while((int)CharFreq.size()>2){
            letter_start=str[start];
            CharFreq[letter_start]--;
            if(CharFreq[letter_start]==0){
                CharFreq.erase(letter_start);
            }
            start++;
        }
        maxlength=max(maxlength,stop-start+1);
    }
    cout<<maxlength;
    return 0;
}