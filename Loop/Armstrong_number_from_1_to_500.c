#include <stdio.h>

int main()
{
    for(int i=1;i<=500;i++){
        int z=i,t=1,h=0;
        for(int j=1;j<4;j++){
            if(z==0){
                continue;
            }
            t=z%10;
            h=h+t*t*t;
            z/=10;
        }
        if(h==i){
            printf("\n%d",h);
            continue;
        }
    }
    return 0;
}