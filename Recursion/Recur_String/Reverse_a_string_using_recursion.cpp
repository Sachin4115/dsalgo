//Reverse a string using recursion
#include <iostream>
#include <string>
using namespace std;

void rev(string &str,int i){
    if(i>(str.length()-1)/2)
        return;
    swap(str[i],str[str.length()-1-i]);
    rev(str,++i);
}

int main()
{
    string str;
    cout<<"Enter the string : ";
    cin>>str;
    rev(str,0);
    cout<<"Reverse of the given string is : "<<str;
    return 0;
}