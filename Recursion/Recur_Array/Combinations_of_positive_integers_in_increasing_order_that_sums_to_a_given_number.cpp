#include <iostream>
#include <vector>
using namespace std;
void printArray(vector <int> a, int n)
{
    for (int i = 0; i <= n; i++) {
        cout<< a[i];
    }
    cout<<endl;
}
void comb(vector <int> a,int i,int sum,int sum_left){
    int Pnumber=(i>0)?a[i-1]:1;
    for(int j=Pnumber;j<=sum;j++){
        a.push_back(j);
        if(sum_left>j)
            comb(a,i+1,sum,sum_left-j);
        if(sum_left==j)
            printArray(a,i);
        a.pop_back();
    }
}
int main()
{
    int sum=5;
    vector <int> a;
    comb(a,0,sum,sum);
    return 0;
}