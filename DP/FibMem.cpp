#include <iostream>
using namespace std;

int fib(int n){
    if(n==0 || n==1)
        return n;
    cout<<n<<endl;
    int f1 = fib(n-1);
    int f2 = fib(n-2);
    int f = f1+f2;
    return f;
}

int fibMem(int n, int arr[]){
    if(n==0 || n==1)
        return n;
    if(arr[n]!=0)
        return arr[n];
    cout<<n<<endl;
    int f1 = fibMem(n-1,arr);
    int f2 = fibMem(n-2,arr);
    int f = f1+f2;
    arr[n]=f;
    return f;
}

int main()
{

    int n=6;
    cout<<fib(n)<<endl<<endl;
    cout<<fibMem(n,new int[n+1]{0})<<endl;
    return 0;
}