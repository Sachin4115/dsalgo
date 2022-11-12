#include <stdio.h>

int main()
{
    int age = 22;
    int _age = 23;
    int *ptr = &age;
    int *_ptr = &_age;
    printf("%u\n",ptr);
    ptr++;
    printf("%u\n",ptr);
    ptr--;
    printf("%u\n",ptr);
    printf("%u\n",ptr);
    printf("%u\n",_ptr);
    printf("%u\n",ptr-_ptr);//difference can only be done on similiar data type :)
    return 0;
}