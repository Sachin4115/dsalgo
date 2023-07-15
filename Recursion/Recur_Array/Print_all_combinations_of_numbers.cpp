#include <iostream>
#include <vector>
using namespace std;
void printc(vector <int> out,int n){
    for(int i=0;i<n;i++){
        cout<<out[i];
    }
    cout<<endl;
}
void combination(vector <int> out,int n, int i, int index){
    if(n==0)
        printc(out, index);
    for(int j=i;j<=n;j++){
        out.push_back(j);
        combination(out,n-j,j,index+1);
        out.pop_back();
    }
}
int main()
{
    int n=5;
    vector <int> out;
    combination(out,n,1,0);
    return 0;
}