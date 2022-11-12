#include <stdio.h>
int sumdigits(int n);

int main()
{
    int n;
    printf("Enter the number whose digits you want to add : ");
    scanf("%d",&n);
    printf("Sum of the digits of thenumber %d id %d .",n,sumdigits(n));
    return 0;
}

int sumdigits(int n){
    if(n==0){
        return 0;
    }
    int a = n % 10;
    int sddt=sumdigits(n/10);
    int sdigit= a + sddt;
    return sdigit;
}