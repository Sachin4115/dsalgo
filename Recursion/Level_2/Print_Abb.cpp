#include <iostream>
#include <string>
using namespace std;

void print_abb(string str,string ptr,string ans,int i){
    if(i>=str.length()){
        cout<<ans<<endl;
        return;
    }
    if((ptr[i]=='0')&&(i<str.length())){
        print_abb(str,ptr,ans+str[i],i+1);
    }
    if(ptr[i]=='1'){
        int count=0;
        while((ptr[i]=='1')&&(i<str.length())){
            count++;
            i++;
        }
        char ch=count+'0';
        print_abb(str,ptr,ans+ch,i);
    }
}
void find_pattern(int n,string ptr,int i,string str){
    if(i==n){
        print_abb(str,ptr,"",0);
        return;
    }
    find_pattern(n,ptr+'1',i+1,str);
    find_pattern(n,ptr+'0',i+1,str);
}
int main()
{
    string str;
    cin>>str;
    find_pattern(str.length(),"",0,str);

    return 0;
}