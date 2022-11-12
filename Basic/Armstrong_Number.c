#include<stdio.h>

int main()
{
    int a,b,c;
     printf("Enter the hundreds digit of the number");
    scanf("%d",&a);
    printf("Enter the tens digit of the number");
    scanf("%d",&b);
    printf("Enter the once digit of the number");
    scanf("%d",&c);
    if(a*a*a+b*b*b+c*c*c == c+b*10+a*100){
        printf("Yes the number is an armstrong number");
    } else{
        printf("No the number is not an armstrong number");
    }
    return 0;
}