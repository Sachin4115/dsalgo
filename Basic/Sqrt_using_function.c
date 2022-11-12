#include <stdio.h>
#include <math.h>

float sqareroot(float n);
int main()
{
    float n;
    printf("Enter the number you want square root of : ");
    scanf("%f",&n);
    printf("The square root of the number %f is %f.",n,sqareroot(n));
    return 0;
}
float sqareroot(float n){
    float root=pow(n,0.5);
    return root;
}