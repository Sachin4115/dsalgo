#include <iostream>
#include <string>
using namespace std;
void findlex(string str,string result){
    if(result.length()==str.length()){
        cout<<result<<" ";
        return;
    }
    int n=0;
    while(n!=str.length()){
        while((n+1!=str.length())&&str[n]==str[n+1])
            n++;
        findlex(str,result+str[n]);
        n++;
    }
}
int main()
{
    string str = "AAC";
    findlex(str,"");
    return 0;
}