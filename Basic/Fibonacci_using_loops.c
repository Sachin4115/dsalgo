#include <stdio.h>

int main()
{
    int a=0,b=1,c,n;
    printf("Enter the number of the terms you want to print : ");
    scanf("%d",&n);
    printf("0,1,");
    for(int i=1;i<=n-2;i++){
        c=a+b;
        a=b;
        b=c;
        printf("%d,",c);
    }
    return 0;
}