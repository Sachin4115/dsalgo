#include<stdio.h>

int main()
{
    for (int i=7;i<=70;i++){
        if(i%2 == 0){
            continue;
        }
        printf("%d\n",i);
    }
    return 0;
}