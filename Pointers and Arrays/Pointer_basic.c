#include <stdio.h>

int main()
{
    int  age = 22;
    int *ptr = &age;
    int _age = *ptr;
    printf("%d\n%d\n%d\n",age,ptr,_age);
    printf("%p\n%p\n%p\n",&age,ptr,&ptr);
    //%p--> Hexadecimal
    //%u-->unsigned int
    printf("%u\n%u\n%u\n",&age,ptr,&ptr);
    return 0;
}