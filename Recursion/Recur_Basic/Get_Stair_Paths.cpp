#include <iostream>
#include <string>
using namespace std;

void Count(int n,string s){
    if(n<0)
        return;
    if(n==0){
        cout<<s<<" ";
        return;
    }
    Count(n-1,s+"1");
    Count(n-2,s+"2");
    Count(n-3,s+"3");
}

int main()
{
    int n=5;
    cout<<"[";
    Count(n,"");
    cout<<"]";
    return 0;
}