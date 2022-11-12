#include<stdio.h>

void Simple_Calculator();
void Addition();
void Subtraction();
void Multiplication();
void Division();

int main()
{
    Simple_Calculator();
    return 0;
}

void Simple_Calculator(){
    int action;
    printf("Enter the Operation that you want to perform : \n 1.Addition\n 2.Subtraction\n 3.Multiplication\n 4.Division\n --> ");
    scanf("%d",&action);
    switch (action)
    {
    case 1:
        Addition();
        break;
    case 2:
        Subtraction();
        break;
    case 3:
        Multiplication();
        break;
    case 4:
        Division();
        break;
    default:
    printf("Enter the correct Operation");
        break;
    }

}
void Addition(){
    int a,b;
    printf("Enter the first number : ");
    scanf("%d",&a);
    printf("Enter the second number : ");
    scanf("%d",&b);
    printf("%d",a+b);
}
void Subtraction(){
    int a,b;
    printf("Enter the first number : ");
    scanf("%d",&a);
    printf("Enter the second number : ");
    scanf("%d",&b);
    printf("%d",a-b);
}
void Multiplication(){
    int a,b;
    printf("Enter the first number : ");
    scanf("%d",&a);
    printf("Enter the second number : ");
    scanf("%d",&b);
    printf("%d",a*b);
}
void Division(){
    int a,b;
    printf("Enter the first number : ");
    scanf("%d",&a);
    printf("Enter the second number : ");
    scanf("%d",&b);
    printf("%d",a/b);
}