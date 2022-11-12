#include<stdio.h>
//For Math Fuction
#include<math.h>
int main()
{
    float First_Number,Second_Number;
    printf("Enter the First Number");
    scanf("%f",&First_Number);
    
    printf("Enter the Second Number");
    scanf("%f",&Second_Number);
    
//Addition
    printf("The sum of both the numbers is %f\n",First_Number+Second_Number);
//Suntraction
    printf("The diffrence between both the numbers is %f\n",First_Number-Second_Number);
//Multiplation
    printf("The product of both the numbers is %f\n",First_Number*Second_Number);
//Division
    printf("The Quotient when %f is devided by %f is  %f\n",First_Number,Second_Number,First_Number/Second_Number);
//Power
    printf("Power of First Number to the Second Number is %f\n",pow(First_Number,Second_Number));
//Remainder
//    printf("Remainder when First Number is Devided by Second Number is %f\n",First_Number%Second_Number);
//This won't work because % function works only for integers

    return 0;
}