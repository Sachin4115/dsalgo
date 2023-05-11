#include <iostream>
#include <string>
using namespace std;
void allperm(string str,int i,int n){
    if(i==n-1){
        cout<<str<<" ";
        return;
    }
    for(int j=i;j<n;j++){
        swap(str[i],str[j]);
        allperm(str,i+1,n);
        swap(str[i],str[j]);
    }
}
int main()
{
    string str;
    cout<<"Enter the word you want to find permutions of : ";
    cin>>str;
    allperm(str,0,str.length());
    return 0;
}