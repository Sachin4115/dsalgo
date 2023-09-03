#include <iostream>
using namespace std;

int solution(int n,int k){
    if(n==0)
        return 0;
    int x = solution(n-1,k);
    return  (x+k)%n;
}

int main()
{
    int n=8,k=3;
    cout<<solution(n,k);
    return 0;
}