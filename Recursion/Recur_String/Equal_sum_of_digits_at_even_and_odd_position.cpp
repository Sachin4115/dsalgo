#include <iostream>
#include <string>
using namespace std;
void findnumbers(int n,int diff,string str){
    if(n){
        char ch ='0';
    if(str=="")
        ch ='1';
    while(ch<='9'){
        if(n%2)
            findnumbers(n-1,diff+(ch-'0'),str+ch);
        else
            findnumbers(n-1,diff-(ch-'0'),str+ch);
        ch++;
    }
    }
    else if((!n)&&(!abs(diff))){
        cout<<str<<" ";
    }

}
int main()
{
    int n=3;
    findnumbers(n,0,"") ;
    return 0;
}