#include <stdio.h>
int fib(int n);
int main()
{
    int n;
    printf("Enter the number of terms you want to print of the fibonacci sequence : ");
    scanf("%d",&n);
    printf("the %dth term of fibonacci series is %d.",n,fib(n));
    return 0;
}
int fib(int n){
    int ft,ftm1,ftm2;//final term = ft
        if(n==0){
            return 0;
        }
        if(n==1){
            return 1;
        }
    ftm1=fib(n-1);
    ftm2=fib(n-2);
    ft=ftm1+ftm2;
    printf("%d,",ft);
    return ft;
}