#include <iostream>
#include <string>
using namespace std;

void printstring(string result, int n, char pr){
    if(n){
        for(char ch = pr+1;ch <= '9';ch++){
            printstring( result + ch,n-1,ch);
        }
    }
    else{
        cout<< result <<" ";
    }
}

int main()
{
    int n = 7;
    string result;
    printstring(result,n,'0');
    return 0;
}