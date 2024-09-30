#include <iostream>
using namespace std;

int main()
{
    int a=0,ab=0,abc=0;
    string s = "abcabcbc";
    for(char c:s){
        if(c=='a')
            a=2*a+1;
        else if(c=='b')
            ab=2*ab+a;
        else
            abc=abc*2+ab;
    }
    cout<<abc;
    return 0;
}