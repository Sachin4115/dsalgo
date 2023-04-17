#include <iostream>
#include <string>
using namespace std;
bool palindrome(string &str,int p1,int p2){
    if(str[p1]!=str[p2])
        return false;
    if(p2>=p1)
        return true;
    return palindrome(str,p1+1,p2-1);
}
int main()
{
    string str;
    bool result;
    cout<<"Enter the string you want to check : ";
    cin>>str;
    result=palindrome(str,0,str.length()-1);
    cout<<result;
    return 0;
}