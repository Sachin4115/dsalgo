#include <iostream>
#include <string>
using namespace std;

void findnumbers(int n,int target,string result){

    if(n!=0){
        char i='0';
        if(result == "")
            i='1';
        while(i<='9'){
            findnumbers(n-1,target-(i-'0'),result+i);
            i++;
        }
    }
    if(n==0&&target==0)
        cout<<result << " ";
}
int main()
{
    int n=3;
    int target=6;
    string result;
    findnumbers(n,target,result);
    return 0;
}