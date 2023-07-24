#include <iostream>
#include <string>
using namespace std;
void possub(string str,int i, string result){
    if(i==str.length())
        cout<<result<<endl;
    for(int j=str.length()-1;j>=i;j--){
        string sub="{"+str.substr(i,j-i+1)+"}";
        possub(str,j+1,result+sub);
    }
}
int main()
{
    string str = "ABCD";
    possub(str,0,"");
    return 0;
}