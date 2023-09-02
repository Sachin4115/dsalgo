#include <iostream>
#include <vector>
using namespace std;
void display(vector<vector<int>>& chess) {
    for (int i = 0; i < chess.size(); i++) {
        for (int j = 0; j < chess.size(); j++) {
            cout << chess[i][j] << " ";
        }
        cout << endl;
    }
    cout << endl;
}
void knight_move(vector<vector<int>> chess,int r, int c, int m){
    if((r>chess.size()-1)||(c>chess.size()-1)||(r<0)||(c<0)||chess[r][c]>0){
        return;
    }
    if(m==25){
        chess[r][c]=m;
        display(chess);
        chess[r][c]=0;
        return;
    }
    chess[r][c]=m;
    knight_move(chess,r-2,c+1,m+1);
    knight_move(chess,r-1,c+2,m+1);
    knight_move(chess,r+1,c+2,m+1);
    knight_move(chess,r+2,c+1,m+1);
    knight_move(chess,r+2,c-1,m+1);
    knight_move(chess,r+1,c-2,m+1);
    knight_move(chess,r-1,c-2,m+1);
    knight_move(chess,r-2,c-1,m+1);
    chess[r][c]=0;

}
int main()
{
    int n,r,c;
    cout<<"Enter n : ";
    cin >> n;
    cout<<"Enter r : ";
    cin >> r;
    cout<<"Enter c : ";
    cin >> c;
    vector<vector<int>> chess(n, vector<int> (n));
    knight_move(chess,r,c,1);
    cout<<"---------------------";
    return 0;
}