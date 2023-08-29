#include<iostream>
using namespace std;
int pow(int n,int p){
    if(p==0)
        return 1;
    return n*pow(n,p-1);
}
int main(){
    int n=5,p=4,r;
    r=pow(n,p);
    cout<<r;
    return 0;
}