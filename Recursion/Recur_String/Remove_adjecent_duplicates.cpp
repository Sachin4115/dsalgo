#include <iostream>
#include <string>
using namespace std;
void removedup(string &str,int i){
    if(i>=str.length()-1){
        return;
    }
    if(str[i]==str[i+1]){
        str.erase(i,1);
        removedup(str,i);
    }
    else{
        removedup(str,i+1);
    }
}
int main()
{
    string str = "aaassssddd";
    removedup(str,0);
    cout<<str;
    return 0;
}