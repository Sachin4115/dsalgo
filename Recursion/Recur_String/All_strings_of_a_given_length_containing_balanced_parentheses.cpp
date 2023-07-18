#include <iostream>
#include <string>
using namespace std;
void balstr(int n, string str, int i){
    if((n%2)&&!i){
        return;
    }
    if(n==0 && i==0){
        cout<<str<<endl;
        return;
    }
    if(i>n)
        return;
    balstr(n-1,str+"(",i+1);
    if(i>0)
        balstr(n-1,str+")",i-1);
}
int main()
{
    int n=6;
    balstr(n,"",0);

    return 0;
}