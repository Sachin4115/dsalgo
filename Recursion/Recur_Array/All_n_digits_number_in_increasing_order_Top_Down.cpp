#include <iostream>
#include <string>
using namespace std;

void printstring(string result, int n, char pr){
    if(n){
        for(char ch = pr;ch > '0';ch--){
            printstring( ch + result,n-1,ch-1);
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
    printstring(result,n,'9');
    return 0;
}