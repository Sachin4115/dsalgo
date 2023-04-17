//Reverse a string using recursion
#include <iostream>
#include <string>
using namespace std;

void rev(string &str,int n,int i){
    if(i<n-i){
    swap(str[i],str[n-i]);
    rev(str,n,i+1);
    }
}
int main()
{
    string str;
    // string str = "a s d";
    cout<<"Enter the string : ";
    cin>>str;
    rev(str,str.length()-1,0);
    cout<<"Reverse of the given string is : "<<str;
    return 0;
}