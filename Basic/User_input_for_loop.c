#include<stdio.h>

int main()
{
    int i,n;
    char ch='A';
    printf("Enter the Number of letters you want to print[1-26]");
    scanf("%d",&n);

    for(i=1;i<=n;i++){
        printf("%c\n",ch);
        ch++;
    }
    return 0;
}