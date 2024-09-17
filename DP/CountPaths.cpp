#include <iostream>
using namespace std;

int paths(int n){
    if(n<0)
        return 0;
    if(n==0)
        return 1;
    return paths(n-1)+paths(n-2)+paths(n-3);
}

int pathsMem(int n, int arr[]){
    if(n<0)
        return 0;
    if(n==0)
        return 1;
    if(arr[n]!=0)
        return arr[n];
    int p = paths(n-1)+paths(n-2)+paths(n-3);
    arr[n]=p;
    return p;
}

int pathsTab1(int n){
    int dp[n+1];
    dp[0]=1;
    for(int i=1;i<=n;i++){
        if(i==1)
            dp[i]=dp[i-1];
        else if(i==2)
            dp[i]=dp[i-1]+dp[i-2];
        else
            dp[i]=dp[i-1]+dp[i-2]+dp[i-3];
    }
    return dp[n];
}

int pathsTab2(int n){
    if(n==0)
        return 1;
    if(n==1 || n==2)
        return n;
    int a=1,b=1,c=2;
    for(int i=2;i<n;i++){
        int d=a+b+c;
        a=b;b=c;c=d;
    }
    return c;
}

int main()
{
    int n=10;
    cout<<paths(n)<<endl;
    cout<<pathsMem(n, new int[n+1]{0})<<endl;
    cout<<pathsTab1(n)<<endl;
    cout<<pathsTab2(n)<<endl;
    return 0;
}