#include <iostream>
#include <vector>
#include <climits>
using namespace std;
int LDS(vector<int> a,int i, int p){
    if(i==a.size())
        return 0;
    int ex=LDS(a,i+1,p);
    int in=0;
    if(a[i]<p){
        in=1+LDS(a,i+1,a[i]);
    }
    return max(in,ex);
}
int main()
{
    vector<int> arr = {0,8,4,12,2,10,6,14,1,9,5,13,3,11,7,15};
    cout<< LDS(arr,0,INT_MAX);
    return 0;
}