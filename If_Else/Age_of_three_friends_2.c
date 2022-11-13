#include <stdio.h>

int main()
{
    int Ram,Shyam,Ajay;
    printf("Enter the age of Ram : ");
    scanf("%d",&Ram);
    printf("Enter the age of Shyam : ");
    scanf("%d",&Shyam);
    printf("Enter the age of Ajay : ");
    scanf("%d",&Ajay);
    Ram>Shyam?(Ram>Ajay?printf("Ram"):printf("Ajay")):(Shyam>Ajay?printf("Shyam"):printf("Ajay"));
    return 0;
}