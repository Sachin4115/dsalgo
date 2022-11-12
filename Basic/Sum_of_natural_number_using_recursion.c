#include <stdio.h>
int sum_of_natural_numbers(int n,int sum);
int main()
{
    int n,sum=0;
    printf("Enter the value of n : ");
    scanf("%d",&n);
    sum=sum_of_natural_numbers(n,sum);
    printf("The sum of first %d natural numbers is %d",n,sum);
    return 0;
}
 int sum_of_natural_numbers(int n,int sum){
    if (n==0){
        return sum;
    }
    sum = sum+n;
    n--;
    sum_of_natural_numbers(n,sum);

 }