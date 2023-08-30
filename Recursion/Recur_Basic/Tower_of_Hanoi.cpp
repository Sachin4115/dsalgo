#include <iostream>
#include <string>
using namespace std;
void Hanoi(int n,string a,string b,string c){
    if(n==0)
        return;
    Hanoi(n-1,a,c,b);
    cout<<n<<"["<<a<<"->"<<b<<"]"<<endl;
    Hanoi(n-1,c,b,a);


}
int main()
{
    string A="10",B="11",C="12";
    int n=3;
    Hanoi(n,A,B,C);
    return 0;
}