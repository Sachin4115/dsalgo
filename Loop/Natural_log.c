#include <stdio.h>
#include <math.h>

int main()
{
        float x,log=0,temp;
        printf("Enter the number whose logarithm you want to calculate : ");
        scanf("%f",&x);
        for(int i=1;i<=7;i++){
            temp=(x-1)/x;
            temp=pow(temp,i);
            if(i==1){
                log+=temp;
            }
            else{
                log+=(temp/2);
            }
        }
        printf("The value of natural logarithm of the number %f is %f.",x,log);
    return 0;
}