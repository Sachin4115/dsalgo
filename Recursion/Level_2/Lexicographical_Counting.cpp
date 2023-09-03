#include <iostream>
using namespace std;

void solution(int n,int asf){
    if(asf>n)
        return;
    cout<<asf<<endl;
    for(int i=0;i<10;i++){
        solution(n,10*asf+i);
    }
}

int main()
{
    int n=50;
    for(int asf=1;asf<10;asf++)
    solution(n,asf);
    return 0;
}