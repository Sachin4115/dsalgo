#include <stdio.h>

int main()
{
    int num,num1,x,y;
    printf("Enter the number you want to check : ");
    scanf("%d",&num);
    num1=num;
    for(int i=0;i<5;i++){
        x=num%10;
        num/=10;
        y=y*10+x;
    }
    if(num1==y){
        printf("The number you entered is a palindrome");
    }
    else{
        printf("The number you entered is not a palindrome");
    }
    return 0;
}