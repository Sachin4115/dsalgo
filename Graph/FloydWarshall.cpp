#include <iostream>
#include <vector>
using namespace std;

void shortestDistance(vector<vector<int>>& arr) {
    int n = arr.size();
    for(int k=0;k<n;k++){
        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                if(i==k||j==k||i==j) continue;
                int d = arr[i][j];
                int l = arr[i][k];
                int r = arr[k][j];
                if(l==-1 || r==-1) continue;
                if(d==-1) arr[i][j]=l+r;
                else arr[i][j]=min(d,l+r);
            }
        }
    }
}

int main()
{
    vector<vector<int>> arr = {{0, 1, 43},{1, 0, 6}, {-1, -1, 0}};
    shortestDistance(arr);
    for(auto a:arr){
        for(int i:a) cout<<i<<" ";
        cout<<endl;
    }
    return 0;
}