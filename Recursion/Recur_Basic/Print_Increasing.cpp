#include <iostream>
using namespace std;
void print_increasing(int i,int n){
    if(i==n+1)
        return;
    cout<<i<<endl;
    print_increasing(i+1,n);
}
int main()
{
    int n=5;
    print_increasing(1,n);
    return 0;
}