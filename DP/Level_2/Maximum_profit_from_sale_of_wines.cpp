#include <iostream>
#include <vector>
using namespace std;

// Given n wines in a row, with integers denoting the cost of each wine respectively. Each year you can
// sale the first or the last wine in a row. However, the price of wines increases over time. Let the
// initial profits from the wines be P1, P2, P3…Pn. In the Yth year, the profit from the ith wine will be
// Y*Pi. For each year, your task is to print “beg” or “end” denoting whether first or last wine should
// be sold. Also, calculate the maximum profit from all the wines

int main()
{
    vector<int> wines = {2,4,6,2,5};
    int n = wines.size();
    vector<vector<int>> dp(n,vector<int>(n,0));
    vector<vector<int>> move(n,vector<int>(n,0));
    for(int g=0;g<n;g++){
        for(int i=0,j=g;j<n;i++,j++){
            int  y = n - g;
            if(g==0) dp[i][j]=y*wines[i];
            else{
                int a = y*wines[i]+dp[i+1][j];
                int b = y*wines[j]+dp[i][j-1];
                if(a>b){
                    dp[i][j]=a;
                    move[i][j]=0;
                }else{
                    dp[i][j]=b;
                    move[i][j]=1;
                }
            }
        }
    }
    cout<<dp[0][n-1]<<endl;
    int i = 0,j = n-1;
    while(i<=j){
        if(move[i][j]){
            cout<<"end ";
            j--;
        }else{
            cout<<"beg ";
            i++;
        }
    }
    return 0;
}