#include<stdio.h>

int Simple_Calculator();
int Addition(int a,int b);
int Subtraction(int a,int b);
int Multiplication(int a,int b);
int Division(int a,int b);

int main()
{
    int Answer;
    Answer=Simple_Calculator();
    printf("%d",Answer);
    return 0;
}

int Simple_Calculator(){
    int action,a,b,result;
    printf("Enter the Operation that you want to perform : \n 1.Addition\n 2.Subtraction\n 3.Multiplication\n 4.Division\n --> ");
    scanf("%d",&action);
    printf("Enter the first number :  ");
    scanf("%d",&a);
    printf("Enter the second number : ");
    scanf("%d",&b);
 //   Input_2_Number();
    switch (action)
    {
    case 1:
        result = Addition(a,b);
        break;
    case 2:
        result = Subtraction(a,b);
        break;
    case 3:
        result = Multiplication(a,b);
        break;
    case 4:
        result = Division(a,b);
        break;
    default:
    printf("Enter the correct Operation");
        break;
    }
    return(result);
}
int Addition(int a,int b){
    return a+b;
}
int Subtraction(int a,int b){
    return a-b;
}
int Multiplication(int a,int b){
    return a*b;
}
int Division(int a,int b){
    return a/b;
}