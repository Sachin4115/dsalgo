#include <stdio.h>
/*
Write a program to produce the following output:
                    1
                1       1
            1       2       1
        1       3       3       1
    1       4       6       4       1
*/
int main()
{
    for(int i=1;i<=5;i++){
        for(int j=1;j<=5-i;j++){
            printf("    ");
        }
        printf("      1");
        for(int j=1;j<=i-1;j++){
            int fact1=1,fact2=1,fact3=1;
            for(int k=i-1;k>=1;k--){
                fact1*=k;
            }
            for(int k=j;k>=1;k--){
                fact2*=k;
            }
            for(int k=i-1-j;k>=1;k--){
                 fact3*=k;
            }
            printf("       %d",fact1/(fact2*fact3));
        }
        printf("\n");
    }
    return 0;
}