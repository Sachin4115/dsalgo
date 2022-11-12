#include <stdio.h>
#include <math.h>
void square();
void area_of_circle();
void area_of_square();
void area_of_rectangle();
int main()
{
    int action;
    printf("Enter the action you want to perform.\n1. Square the number \n2. Area of circle \n3. Area of square \n4. Area of rectangle\n -->");
    scanf("%d",&action);
    switch (action)
    {
    case 1 :
        square();
        break;
    case 2 :
        area_of_circle();
        break;
    case 3 :
        area_of_square();
        break;
    case 4 :
        area_of_rectangle();
        break;

    default:
        printf("Enter the correct number corresponding the action you want to perform");
        break;
    }
    return 0;
}
void square(){
    int number;
    printf("Enter the number that you want to square : ");
    scanf("%d",&number);
    printf("The square of the number %d is %f \n",number,pow(number,2));
}
void area_of_circle(){
    int radius;
    printf("Enter the value of the radius of the circle you want to calculate the area of : ");
    scanf("%d",&radius);
    printf("The area of the circle with radius %d is %f \n",radius,pow(radius,2)*3.14);
}
void area_of_square(){
    int side;
    printf("Enter the value of the side of the square you want to calculate the area of : ");
    scanf("%d",&side);
    printf("The area of the square with the side %d is %f \n",side,pow(side,2));
}
void area_of_rectangle(){
    int length,breadth;
    printf("Enter the value of the length of the rectangle you want to calculate the area of : ");
    scanf("%d",&length);
    printf("Enter the value of the breadth of the rectangle you want to calculate the area of : ");
    scanf("%d",&breadth);
    printf("The area of the rectangle with length %d and breadth %d is %d. \n",length,breadth,length*breadth);
}