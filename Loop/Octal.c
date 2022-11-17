#include <stdio.h>
#include<math.h>
int main()
{
    int num,oct,temp,power;
    printf("Enter the number whose octal equivalent you want to find out : ");
    scanf("%d",&num);
    for(int i=1;i<=10;i++){
        if(num==0){
            break;
        }
        temp=num%8;
        power=(pow(10,i));
        oct=oct+temp*power;
        num/=8;
    }
    printf("The octal equivalent of the number entered by the user is %d",oct/10);
    return 0;
}