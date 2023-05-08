#include <iostream>
#include <string>
#include <vector>
#include <unordered_map>
#include <unordered_set>
using namespace std;

void allcombinations(vector <vector<char>> &keypad,vector <int> &key,unordered_set <string> &comb,string results,int index, auto map){
    if(index==-1){
        comb.insert(results);
        return;
    }
    int n = key[index];
    if(map.find(n)==map.end()){
    for(int i = 0; i<keypad[n].size();i++){

        map[n] = keypad[n][i];
        allcombinations(keypad,key,comb,keypad[n][i]+results,index-1,map);
    }
    return;
    }
    allcombinations(keypad,key,comb,map[n]+results,index-1,map);
}
int main()
{
    unordered_set <string> comb;
    unordered_map <int,char> map;
    vector <vector<char>> keypad={
        {},
        {'A','B','C','D'},
        {'E','F','G','H','I','J','K'},
        {'L','M','N','O','P','Q'},
        {'R','S','T'},
        {'U','V','W','X','Y','Z'}
    };
    vector <int> key = {1,3,1};
    allcombinations(keypad,key,comb,"",key.size()-1,map);
    for(string s : comb){
        cout<<s<<' ';
    }
    return 0;
}