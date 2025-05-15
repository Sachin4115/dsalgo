#include <iostream>
using namespace std;

int main()
{
    int n = 16;
    int arr[n] = {1,0,2,1,1,3,0,4,2,5,2,2,3,1,0,2};
    int fenwick[n+1];
    for(int i=0;i<=n;i++) fenwick[i]=0;
    for(int i=0;i<n;i++){
        int in = i+1;
        while(in<=n){
            fenwick[in]+=arr[i];
            in+=(in&-in);
        }
    }
    int queries[4][2] = {
        {0,3},
        {1,5},
        {5,7},
        {12,15}
    };
    for(int i=0;i<=n;i++) cout<<fenwick[i]<<" ";
    cout<<endl;
    for(int i=0;i<4;i++){
        int s = queries[i][0], e = queries[i][1]+1;
        int l=0,r=0;
        while(s){
            l+=fenwick[s];
            s-=(s&-s);
        }
        while(e){
            r+=fenwick[e];
            e-=(e&-e);
        }
        cout<<r-l<<endl;
    }
    return 0;
}