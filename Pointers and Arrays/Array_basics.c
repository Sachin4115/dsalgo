#include <stdio.h>

int main()
{
    int marks[3];
    printf("Maths : ");
    scanf("%d", &marks[0]);

    printf("Physics : ");
    scanf("%d", &marks[1]);

    printf("Chemistry : ");
    scanf("%d", &marks[2]);

    printf("%d\n%d\n%d\n", marks[0],marks[1],marks[2]);
    return 0;
}