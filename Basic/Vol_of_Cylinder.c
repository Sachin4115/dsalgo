#include<stdio.h>

int main()
{
    float Radius,Height,Pi,Vol;
    Pi=3.14;

    printf("Enter the value of the Radius\n");
    scanf("%f",&Radius);

    printf("Enter the value of the Height\n");
    scanf("%f",&Height);

    Vol=Pi*Radius*Radius*Height;
    printf("The Volume of the given cylindder is %f", Vol);
    return 0;
}