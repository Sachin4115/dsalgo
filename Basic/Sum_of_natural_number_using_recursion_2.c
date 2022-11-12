#include <stdio.h>
int sumofnaturalnumber(int n);
int main()
{
    int n;
    printf("Enter the value of n : ");
    scanf("%d",&n);
    printf("%d",sumofnaturalnumber(n));
    return 0;
}
int sumofnaturalnumber(int n){
    if(n==1){
        return 1;
    }
    int sumnm1=sumofnaturalnumber(n-1);
    int sumn=sumnm1+n;
    return sumn;
}