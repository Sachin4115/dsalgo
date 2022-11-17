#include <stdio.h>

int main()
{
    int hrs;
    for(int i=1;i<=10;i++){
        printf("\nEnter the number of hours %dth employee worked : ",i);
        scanf("\n%d",&hrs);
        printf("\nThe overtime pay of the %dth employee for working %d hours extra is %d",i,hrs-40,12*(hrs-40));
    }
    return 0;
}