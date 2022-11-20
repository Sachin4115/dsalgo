#include <stdio.h>
#include <math.h>

int main()
{
    float a,p,q,r,n,temp;
    for(int i=1;i<=10;i++){
        printf("Enter the principle amount : ");
        scanf("%f",&p);
        printf("Enter the rate : ");
        scanf("%f",&r);
        printf("Enter the time in years : ");
        scanf("%f",&n);
        printf("Enter the number of times principle amount is compunded in a year : ");
        scanf("%f",&q);
        temp=pow((1+(r/q)),n*q);
        a=p*temp;
        printf("%.2f\t\t%.2f\t%.2f\t%.2f\t%.2f\n",a,p,r,n,q);
    }
    return 0;
}