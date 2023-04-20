#include <iostream>
#include <string>
using namespace std;

void printallcomb(string &str,int n){
    if(n==(int)str.length()){
        cout<<str<<endl;
        return;
    }
    if(str[n]=='?'){
        for(int i=0;i<2;i++){
            str[n]=i+'0';
            printallcomb(str,n+1);
            str[n]='?';
        }
        return;
    }
    printallcomb(str,n+1);
}

int main()
{
    string str;
    cout<<"Enter the String : ";
    cin>>str;
    printallcomb(str,0);
    return 0;
}