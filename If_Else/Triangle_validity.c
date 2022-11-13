#include <stdio.h>

int main()
{
    int angle1,angle2,angle3;
    printf("Enter the value of first angle : ");
    scanf("%d",&angle1);
    printf("Enter the value of second angle : ");
    scanf("%d",&angle2);
    printf("Enter the value of third angle : ");
    scanf("%d",&angle3);
    if(angle1+angle2+angle3==180){
        printf("The given triangle is a valid triangle");
    }
    else{
        printf("The given triangle is not a valid triangle");
    }
    return 0;
}