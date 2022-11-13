#include <stdio.h>
#include <math.h>

int main()
{
    float x,cx,cy,r,px,py;
    printf("Enter the x coordinate of the center : ");
    scanf("%f",&cx);
    printf("Enter the y coordinate of the center : ");
    scanf("%f",&cy);
    printf("Enter the value of the radius of the circle : ");
    scanf("%f",&r);
    printf("Enter the x coordinate of the point : ");
    scanf("%f",&px);
    printf("Enter the y coordinate of the point : ");
    scanf("%f",&py);
    x=sqrt((pow((px-cx),2)+pow((py-cy),2)));
    if(x>r){
        printf("The point entered is outside the circle");
    }
    else if(x<r){
        printf("The point entered is inside the circle");
    }
    else{
        printf("The point entered is on the circle");
    }
    return 0;
}