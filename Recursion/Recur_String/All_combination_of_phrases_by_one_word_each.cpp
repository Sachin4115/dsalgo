#include <iostream>
#include <string>
#include <vector>
using namespace std;
void printAllCombinations(vector<vector<string>> lists,string results,int n){
    if(n==lists.size()){
        cout<<results.substr(1)<<endl;
        return;
    }
    int m=lists[n].size();
    for(int i=0;i<m;i++){
        printAllCombinations(lists, results+" " + lists[n][i], n+1);
    }
}
int main()
{
    vector<vector<string>> lists =
    {
        {"John","Emma"},
        {"Plays","Hates","Watches"},
        {"Cricket","Soccer","Chess"}
    };
    printAllCombinations(lists, "", 0);
    return 0;
}