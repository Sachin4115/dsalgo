#include <stdio.h>

void square(int *n);
int main()
{
    int n;
    printf("Enter the number you want the square of : ");
    scanf("%d",&n);
    square(&n);
    printf("Number = %d",n);
    return 0;
}
//call by refrence
void square(int *n){
    *n = (*n)*(*n);
    printf("square = %d\n",*n);
}