// cost of painting ith house with give color is given
// find the min cost such that no 2 adj houses have same color

#include <iostream>
using namespace std;

int main()
{
    int n=4;
    int R[n] = {1,5,3,1};
    int G[n] = {5,8,2,2};
    int B[n] = {7,4,9,4};
    int r=R[0],g=G[0],b=B[0];
    for(int i=1;i<n;i++){
        int nr=min(g,b)+R[i];
        int ng=min(r,b)+G[i];
        int nb=min(g,r)+B[i];
        r=nr;
        b=nb;
        g=ng;
    }
    cout<<min(r,min(g,b));
    return 0;
}