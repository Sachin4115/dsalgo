#include <iostream>
#include <string>
#include <vector>
#include <unordered_set>
using namespace std;

void allcombinations(vector <vector<char>> &keypad,vector <int> &key,unordered_set <string> &comb,string results,int index){
    if(index==-1){
        comb.insert(results);
        return;
    }
    int n = key[index];
    for(char c : keypad[n])
        allcombinations(keypad,key,comb,c+results,index-1);
}
int main()
{
    unordered_set <string> comb;
    vector <vector<char>> keypad={
        {},{},
        {'A','B','C'},
        {'D','E','F'},
        {'G','H','I'},
        {'J','K','L'},
        {'M','N','O'},
        {'P','Q','R','S'},
        {'T','U','V'},
        {'W','X','Y','Z'}
    };
    vector <int> key = {2,3,4};
    allcombinations(keypad,key,comb,"",key.size()-1);
    for(string s : comb){
        cout<<s<<' ';
    }
    return 0;
}