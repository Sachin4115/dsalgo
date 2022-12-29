#include <iostream>
#include <string>
using namespace std;

int main()
{
    int p1,p2,f=1,count;
    string str1,str2;
    cout<<"Enter the first string : ";
    cin>>str1;
    cout<<"Enter the second string : ";
    cin>>str2;
    p1=str1.length()-1;
    p2=str2.length()-1;
    // cout<<p1;
    while(p1>=0&&p2>=0){
        count=0;
        while(str1[p1]=='#'){
            count++;
            p1--;
        }
        p1-=count;
        count=0;
        while(str2[p2]=='#'){
            count++;
            p2--;
        }
        p2-=count;
        if(str1[p1]==str2[p2]){
            p1--;
            p2--;
        }
        else/*(str1[p1]!=str2[p2])*/{
            cout<<"False";
            f=0;
            break;
        }
    }
    if(f==1&&p1==p2){
        cout<<"True";
    }
    return 0;
}