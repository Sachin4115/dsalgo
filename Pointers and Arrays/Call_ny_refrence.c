#include <stdio.h>

void square(int* p);
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
void square(int* p){
    *p = (*p)*(*p);
    printf("square = %d\n",*p);
}