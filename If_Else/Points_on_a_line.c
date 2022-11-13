#include <stdio.h>

int main()
{
    float x1,x2,x3,y1,y2,y3;
    printf("Enter the x coordinate of the first point : ");
    scanf("%f",&x1);
    printf("Enter the x coordinate of the second point : ");
    scanf("%f",&x2);
    printf("Enter the x coordinate of the third point : ");
    scanf("%f",&x3);
    printf("Enter the y coordinate of the first point : ");
    scanf("%f",&y1);
    printf("Enter the y coordinate of the second point : ");
    scanf("%f",&y2);
    printf("Enter the y coordinate of the third point : ");
    scanf("%f",&y3);
    if(((y3-y2)/(x3-x2))==((y2-y1)/(x2-x1))){
        printf("The points given are on the same straight line.");
    }
    else{
        printf("The points given are not on the same straight line.");
    }
    return 0;
}