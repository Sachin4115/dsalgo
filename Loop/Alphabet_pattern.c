#include <stdio.h>

int main()
{
    for(int i=0;i<=6;i++){
        for(int j=65;j<=71-i;j++){
            printf("%c ",j);
        }
        for(int k=1;k<=i*2-1;k++){
            printf("  ");
        }
        for(int l=71-i;l>=65;l--){
            if(l==71);
            else{
                printf("%c ",l);
            }
        }
        printf("\n");
    }
    return 0;
}