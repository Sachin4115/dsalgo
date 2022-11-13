#include <stdio.h>

int main()
{
    int num;
    printf("Enter the number you want the absolute value of : ");
    scanf("%d",&num);
    if(num<0){
        num*=-1;
    }
    printf("The absolute value of the given number is %d",num);
    return 0;
}