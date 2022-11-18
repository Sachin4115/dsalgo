#include <stdio.h>

/*series is like 1/1! + 2/2! + 3/3! + 4/4! + ..... + n/n!*/

int main()
{
    float sum=0,fact;
    int n;
    printf("Enter the number of terms you want to add : ");
    scanf("%d",&n);
    for(int i=1;i<=n;i++){
        fact=1;
        for(int j=1;j<=i;j++){
            fact=fact*j;
        }
        sum+=(i/fact);
    }
    printf("The sum of the series upto n terms is : %f",sum);
    return 0;
}