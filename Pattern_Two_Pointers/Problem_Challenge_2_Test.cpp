#include <iostream>
#include <string>
using namespace std;

int main()
{
    int r1,r2,flag=1,count;
    string str1,str2;
    cout<<"Enter the first string : ";
    cin>>str1;
    cout<<"Enter the second string : ";
    cin>>str2;
    r1=str1.length()-1;
    r2=str2.length()-1;
    while(r1>=0&&r2>=0){
        count=0;
        while(str1[r1]=='#'){
            count++;
            r1--;
        }
        r1-=count;
        count=0;
        while(str2[r2]=='#'){
            count++;
            r2--;
        }
        r2-=count;
        if(str1[r1]==str2[r2]){
            r1--;
            r2--;
        }
        else{
            flag=0;
            break;
        }
    }
    if(flag&&r1==r2)
        cout<<"True";
    else
        cout<<"False";
    return 0;
}