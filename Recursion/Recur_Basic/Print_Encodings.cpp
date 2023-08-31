#include <iostream>
#include<string>
using namespace std;

void printEncoding(string str, string asf){
    if(str.length()==0){
        cout<<asf<<endl;
        return;
    }
    else if(str.length()==1){
        char ch=str[0];
        if(ch=='0')
            return;
        else{
            int chv=ch-'0';
            char code='a'+chv-1;
            cout<<asf+code<<endl;
        }
    }
    else{
        char ch=str[0];
        string stronright=str.substr(1);
        if(ch=='0')
            return;
        else{
            int chv=ch-'0';
            char code='a'+chv-1;
            printEncoding(stronright,asf+code);
        }
        string ch12=str.substr(0,2);
        stronright=str.substr(2);
        int ch12v=(ch12[0]-'0')*10+ch12[1]-'0';
        if(ch12v<=26){
            char code='a'+ch12v-1;
            printEncoding(stronright,asf+code);
        }
    }
}

int main(){
    string str;
    cin>>str;
    printEncoding(str,"");

}