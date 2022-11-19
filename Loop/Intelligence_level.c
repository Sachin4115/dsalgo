#include <stdio.h>

int main()
{
    printf("i\t\ty\tx\n");
    for(float y=1;y<=6;y++){
        for(float x=5.5;x<12.5;x=x+0.5){
            printf("%.2f\t\t%.0f\t%.2f\n",(2+(y+0.5*(x))),y,x);
        }
    }
    return 0;
}