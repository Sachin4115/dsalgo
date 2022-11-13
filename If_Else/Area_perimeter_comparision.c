#include <stdio.h>

int main()
{
    int length,breadth;
    printf("Enter the value of the length of the rectangle : ");
    scanf("%d",&length);
    printf("Enter the value of the breadth of the rectangle : ");
    scanf("%d",&breadth);
    if(length*breadth>2*(length+breadth)){
        printf("The area of the given rectangle is greater than the perimeter of the rectangle");
    }
    else{
        printf("The area of the given rectangle is not greater than the perimeter of the rectangle");
    }
    return 0;
}