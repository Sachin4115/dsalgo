#include<stdio.h>

int main()
{
//++i -> pre increment operator
//i++ -> post increment operttor
    int i=1,j=1;
    printf("%d,%d\n",i,j);
    printf("%d,%d\n",i++,++j);
    printf("%d,%d\n",i,j);
    return 0;
}
//Same for decrement opertators