#include <stdio.h>

int main()
{
    float years;
    float earn_machine=2000,earn_investment=6000;
    for(float n=1;n>0;n++){
        earn_machine+=1000;
        earn_investment=earn_investment+(6000*0.12);
        if(earn_machine>earn_investment){
            years = n;
            break;
        }
    }
    printf("The minimum life of the machine to be a better choice for investment is %f years.",years);
    return 0;
}