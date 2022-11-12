#include<stdio.h>

int main()
{
//This won't work since compiler can not change float/double to int through implicit conversion 
    // int a = 1.99999999;
    // print("%d \n",a);
//So we will have to perform explicit conversion
    int a = (int) 1.9999999;
    printf("%d \n",a);

    return 0;
}