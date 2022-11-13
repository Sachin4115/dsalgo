#include <stdio.h>

int main()
{
    int x,y;
    printf("Enter the x coordinate of the point you want to locate : ");
    scanf("%d",&x);
    printf("Enter the y coordinate of the point you want to locate : ");
    scanf("%d",&y);
    if(x==0&&y==0){
        printf("The point lies on origin.");
    }
    else if(x==0){
        printf("The point lies on y axis.");
    }
    else if(y==0){
        printf("The point lies on x axis.");
    }
    else{
        printf("The given point neither lies on the origin or on any coordinate axis.");
    }
    return 0;
}