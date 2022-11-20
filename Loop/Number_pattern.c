#include <stdio.h>
/*
Write a program to produce the following output:
                1
            2       3
        4       5      6
    7       8      9       10
*/

int main()
{
    int n=1;
    for(int i=4;i>=1;i--){
        for(int j=1;j<=i;j++){
            printf("    ");
        }
        for(int k=4;k>=i;k--){
            printf("      %d",n);
            n++;
        }
        printf("\n");
    }
    return 0;
}