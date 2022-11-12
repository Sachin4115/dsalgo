#include<stdio.h>

int main()
{
    int i,n;
    printf("Enter the number of terms that you want to print in reverse");
    scanf("%d",&n);
    for(i=n;i>0;i--){
        printf("%d\n",i);
    }
    return 0;
}