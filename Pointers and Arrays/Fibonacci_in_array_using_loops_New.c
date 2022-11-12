// Fibonacci Series using Dynamic Programming
#include <stdio.h>

void fib(int f[],int n)
{
    f[0] = 0;
    f[1] = 1;
    for (int i = 2; i <= n; i++) {
        f[i] = f[i - 1] + f[i - 2];
    }
}
int main()
{
    int n = 9;
    int f[n+1];
    fib(f,n);
    for(int j=0;j<=n;j++){
        printf("%d\t",f[j]);
    }
    return 0;
}