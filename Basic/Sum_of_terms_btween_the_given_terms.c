#include<stdio.h>

int main()
{
    int a,l,sum = 0;
    printf("Enter the intial term : ");
    scanf("%d",&a);
    printf("Enter the final term : ");
    scanf("%d",&l);
    for(int i=a;i<=l;i++){
        sum += i;
    }
    printf("%d",sum);
    return 0;
}