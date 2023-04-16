// How does the solution code given in question works.
#include <iostream>
#include <string>
#include <vector>
using namespace std;
void allcombinations(vector <vector<string>> &keypad,vector <int> key,vector <string> &comb,int n){
    if(n==keypad[key[0]].size()*keypad[key[1]].size()*keypad[key[2]].size())
        return;
    string str = keypad[key[0]][(n/9)%3]+keypad[key[1]][(n/3)%3]+keypad[key[2]][n%3];
    comb.push_back(str);
    return allcombinations(keypad,key,comb,n+1);
}
int main()
{
    vector <string> comb;
    vector <vector<string>> keypad={
        {},{},
        {"A","B","C"},
        {"D","E","F"},
        {"G","H","I"},
        {"J","K","L"},
        {"M","N","O"},
        {"P","Q","R","S"},
        {"T","U","V"},
        {"W","X","Y","Z"}
    };
    vector <int> key = {2,3,4};
    allcombinations(keypad,key,comb,0);
    for(auto co : comb){
        cout<<co<<" ";
    }
    return 0;
}