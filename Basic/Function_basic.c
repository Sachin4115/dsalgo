#include<stdio.h>
//Declaration/prototype
void greater_number();
void add_two_number();
int main()
{
    greater_number();//function call
    add_two_number();
    return 0;
}
//function definition
void greater_number(){
    int a,b,c;
    printf("Enter the first number that you want to compare : ");
    scanf("%d",&a);
    printf("Enter the first number that you want to compare : ");
    scanf("%d",&b);
    printf("Enter the first number that you want to compare : ");
    scanf("%d",&c);
    if(a>b && a>c){
        printf("The largest number between %d , %d and %d is %d\n.",a,b,c,a);
    }
    else if(b>a && b>c){
        printf("The largest number between %d , %d and %d is %d\n.",a,b,c,b);
    }
    else{
        printf("The largest number between %d , %d and %d is %d\n.",a,b,c,c);
    }
}
void add_two_number(){
    int a,b;
    printf("Enter the first number that you want to compare : ");
    scanf("%d",&a);
    printf("Enter the first number that you want to compare : ");
    scanf("%d",&b);
    printf("The sum of the given numbers %d and %d is %d.\n",a,b,a+b);
}