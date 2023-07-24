#include <iostream>
#include <string>
using namespace std;
void find_n_digit_numbers(int n,int tsum,string str){
    if(n==0&&tsum==0)
        cout<<str<<" ";
    if(n==0)
        return;
    char d='0';
    if(str == "\0")
        d='1';
    while(d<='9'){
        int digit=d-'0';
        find_n_digit_numbers(n-1,tsum-digit,str+d);
        d++;
    }

}
int main()
{
    int n=3;
    int tsum=6;
    find_n_digit_numbers(n,tsum,"");
    return 0;
}