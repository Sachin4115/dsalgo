#include <iostream>
#include <string>
using namespace std;
int palindrome(string &str,int p1,int p2,int diff){
    if(p1>=p2)
        return diff;
    else if(str[p1]==str[p2])
        palindrome(str,p1+1,p2-1,diff);
    else
        palindrome(str,p1+1,p2-1,diff+1);
}
int main()
{
    string str;
    int result;
    int k=2;
    cout<<"Enter the string you want to check : ";
    cin>>str;
    result=palindrome(str,0,str.length()-1,0);
    if(result>k){
        cout<<"Not a K-Palindrome";
    }
    else{
        cout<<"K-Palindrome";
    }
    return 0;
}