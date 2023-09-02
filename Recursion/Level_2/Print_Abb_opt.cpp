#include <iostream>
#include <string>
using namespace std;

void solution(string str,string ptr,int c,int i){
    if(i==str.length()){
        if(c>0)
            cout<<ptr<<c<<endl;
        else
            cout<<ptr<<endl;
        return;
    }
    if(c>0){
        char ch=c+'0';
        solution(str,ptr+ch+str[i],0,i+1);
    }
    else
        solution(str,ptr+str[i],0,i+1);
    solution(str,ptr,c+1,i+1);
}

int main()
{
    string str;
    cin>>str;
    solution(str,"",0,0);
    return 0;
}