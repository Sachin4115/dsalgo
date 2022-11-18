#include <stdio.h>

int main()
{
    for(int i=1;i<=300;i++){
        int flag=1;
        for(int n=2;n<=i/2;n++){
            if(i%n==0){
                flag=0;
                continue;
            }
        }
        if(flag==1){
            printf("\n%d",i);
        }
    }
    return 0;
}