#include<iostream>
#include<vector>
#include<string>
using namespace std;

bool queenissafe(vector<vector<int>> chess,int r, int c){
    for(int i=r-1,j=c;i>=0;i--){
        if(chess[i][j]==1){
            return false;
        }
    }
    for(int i=r-1,j=c-1;i>=0 && j>=0;i--,j--){
        if(chess[i][j]==1){
            return false;
        }
    }
    for(int i=r-1,j=c+1;i>=0 && j<chess.size();i--,j++){
        if(chess[i][j]==1){
            return false;
        }
    }
    return true;
}
void printNQueens(vector<vector<int>> chess, string qsf, int row) {
    if(row==chess.size()){
        cout<<qsf<<"."<<endl;
        return;
    }
    for(int i=0;i<chess.size();i++){
        if(queenissafe(chess,row,i)==true){
            char r=row+'0';
            char c=i+'0';
            chess[row][i]=1;
            printNQueens(chess,qsf+r+"-"+c+",", row+1);
            chess[row][i]=0;

        }
    }
}

int main() {
    int n;
    cin >> n;
    vector<vector<int>> chess(n, vector<int> (n));
    printNQueens(chess,"", 0);
    return 0;
}