#include <stdio.h>
void dowork(int a, int b, int *sum, int *prod, int *avg);
int main()
{
    int a = 5, b = 11, sum, prod, avg;
    dowork(a,b,&sum,&prod,&avg);
    printf("%d,%d,%d", sum, prod, avg);

    return 0;
}
void dowork(int a, int b, int *sum, int *prod, int *avg)
{
    *sum = a + b;
    *prod = a * b;
    *avg = (a + b) / 2;
}