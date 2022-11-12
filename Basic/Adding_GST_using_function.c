#include<stdio.h>

void calculateprice(float rate);
int main()
{
    float rate;
    printf("Enter the rate of the product : ");
    scanf("%f",&rate);
    calculateprice(rate);
    printf("%f",rate);
// Even if the value of the vriable rate is changed in calculateprice() function, the value of variable rate will not change in the main function.
// So when we print the value of the variable rate after calling the calculateprice() function we get the value which the user has entered previously.
// The value of argument rate is copied to parameter rate.
    return 0;
}
void calculateprice(float rate){
    rate=rate + (rate * 0.18);
    printf("The price of the product after adding GST is : %f\n",rate);
}