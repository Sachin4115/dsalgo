#include <iostream>
#include <vector>
#include <map>
using namespace std;
int isvalid(int row,int column){
    if(row>3||column>2||row<0||column<0)
        return 0;
    if(row==3&&column!=1)
        return 0;
    return 1;
}

multimap<int,int> mapping(vector<vector<char>> &keypad){
    multimap<int,int> map;
    int row[]={0,-1,0,1};
    int column[]={-1,0,1,0};
    for(int i=0;i<4;i++){
        for(int j=0;j<3;j++){
            for(int k=0;k<4;k++){
                int r=i+row[k];
                int c=j+column[k];
                if(isvalid(r,c)&&isvalid(i,j)){
                    map.insert(make_pair(keypad[i][j]-'0',keypad[r][c]-'0'));
                }
            }
        }
    }
    return map;
}
// Function to count all numbers starting from i and having length n
int getcount(multimap<int , int> map,int n ,int i){

}

int main()
{
    int n = 2;
    vector<vector<char>> keypad =
    {
        { '1', '2', '3' },
        { '4', '5', '6' },
        { '7', '8', '9' },
        { '*', '0', '#' }
    };
    // cout<< count(keypad,n);
    multimap<int , int> map = mapping(keypad);
    for(auto& p:map)
        cout<< "{"<<p.first<<","<<p.second<<"}";
    return 0;
}