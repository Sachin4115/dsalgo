#include <stdio.h>
void swap(int *a,int*b);

int main()
{
    int a,b;
    printf("Enter the first number that you wnt to swap : ");
    scanf("%d",&a);
    printf("Enter the second number that you wnt to swap : ");
    scanf("%d",&b);
    printf("Before Swapping : \n");
    printf("a=%d\nb=%d\n",a,b);
    swap(&a,&b);
    printf("After Swapping : \n");
    printf("a=%d\nb=%d",a,b);
    return 0;
}
void swap(int *a,int*b){
    int c;
    c=*a;
    *a=*b;
    *b=c;
}