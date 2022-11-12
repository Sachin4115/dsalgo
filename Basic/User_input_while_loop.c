#include<stdio.h>

int main()
{
    int i=1,n;
    char ch='A';
    printf("Enter the Number of letters you want to print[1-26]");
    scanf("%d",&n);

    while(i<=n){
        printf("%c\n",ch);
        ch++;
        i++;
    }
    return 0;
}