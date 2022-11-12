#include <stdio.h>

int main()
{
    int arr[3];
    printf("Enter Phy : ");
    scanf("%d",&arr[0]);

    printf("Enter Chem : ");
    scanf("%d",&arr[1]);

    printf("Enter Maths : ");
    scanf("%d",&arr[3]);

    printf("prh = %d, chem = %d, maths = %d\n",arr[0],arr[1],arr[2]);
    printf("%d",arr[3]);
    return 0;
}