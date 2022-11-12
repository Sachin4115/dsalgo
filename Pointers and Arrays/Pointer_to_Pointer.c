#include <stdio.h>

int main()
{
    float price = 100;
    float *ptr = &price;
    float **pptr = &ptr;
    printf("%f,%f,%f\n",price,*ptr,**pptr);
    printf("%p,%p\n",&price,ptr);
    printf("%u,%u\n",&price,ptr);
    printf("%p,%p\n",&ptr,pptr);
    printf("%u,%u\n",&ptr,pptr);
    return 0;
}