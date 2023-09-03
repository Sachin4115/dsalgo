#include <iostream>
#include <string>
#include <vector>
using namespace std;


void printNQueens(int n, string qsf, int row,vector<int> column,vector<int> d1,vector<int> d2) {
    if(row==n){
        cout<<qsf<<"."<<endl;
        return;
    }
    for(int i=0;i<n;i++){
        if(column[i]==0&&d1[row+i]==0&&d2[row-i+n-1]==0){
            char r=row+'0';
            char c=i+'0';
            column[i]=1;
            d1[row+i]=1;
            d2[row-i+n-1]=1;
            printNQueens(n,qsf+r+"-"+c+",", row+1,column,d1,d2);
            column[i]=0;
            d1[row+i]=0;
            d2[row-i+n-1]=0;

        }
    }
}

int main()
{
    int n;
    cin>>n;
    // vector<vector<int>> chess(n, vector<int> (n));
    vector <int> column(n,0);
    vector <int> diagonal(2*n-1,0);
    vector <int> cdiagonal(2*n-1,0);
    printNQueens(n,"", 0,column,diagonal,cdiagonal);
    return 0;
}