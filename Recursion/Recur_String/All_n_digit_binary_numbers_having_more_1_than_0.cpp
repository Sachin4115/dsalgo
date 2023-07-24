#include <iostream>
#include <string>
using namespace std;
void printbinstr(string str, int n, int i){
    if(n==0){
        cout<<str<<endl;
        return;
    }
    printbinstr(str+"1",n-1,i+1);
    if(i>0)
        printbinstr(str+"0",n-1,i-1);
}

int main()
{
    int n=4;
    printbinstr("",n,0);
    return 0;
}