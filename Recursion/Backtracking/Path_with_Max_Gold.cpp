// In a gold mine grid of size m x n, each cell in this mine has an
// integer representing the amount of gold in that cell, 0 if it is
// empty.

// Return the maximum amount of gold you can collect under the
// conditions:

// Every time you are located in a cell you will collect all the gold
// in that cell.
// From your position, you can walk one step to the left, right, up,
// or down.
// You can't visit the same cell more than once.
// Never visit a cell with 0 gold.
// You can start and stop collecting gold from any position in the
// grid that has some gold.


#include <iostream>
#include <vector>
using namespace std;

int fun(vector<vector<int>>& arr, int i, int j){
    int t = arr[i][j];
    int s = 0;
    arr[i][j]=0;
    if(i>0 && arr[i-1][j])
        s=max(s,fun(arr,i-1,j));
    if(j>0 && arr[i][j-1])
        s=max(s,fun(arr,i,j-1));
    if(i<arr.size()-1 && arr[i+1][j])
        s=max(s,fun(arr,i+1,j));
    if(j<arr[0].size()-1 && arr[i][j+1])
        s=max(s,fun(arr,i,j+1));
    arr[i][j]=t;
    return s+t;
}

int getMaximumGold(vector<vector<int>>& arr) {
    int r=0;
    int n=arr.size(),m=arr[0].size();
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            if(arr[i][j])
                r=max(r,fun(arr,i,j));
        }
    }
    return r;
}

int main()
{
    vector<vector<int>> arr = {{1,0,7},{2,0,6},{3,4,5},{0,3,0},{9,0,20}};
    int a = getMaximumGold(arr);
    cout<<a;
    return 0;
}