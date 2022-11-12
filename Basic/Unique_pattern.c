#include<stdio.h>

int main()
{
    for(int i = 5;i >= 1; i--){
        for(int j=1;j<i;j++){
            printf(" ");
        }
        for(int j=5;j>=i;j--){
            printf("* ");
        }
        printf("\n");
    }
    int row;
    printf("Enter the number of the rows you want in the pyramid : ");
    scanf("%d",&row);
    for(int i=1;i<=row;i++){
        for(int j=i;j<row;j++ ){
            printf(" ");
        }
        for(int j=1;j<=2*i-1;j++){
            printf("*");
        }
        printf("\n");
    }
    printf("\n");
    for(int i=1;i<=row;i++){
        for(int j=1;j<i;j++ ){
            printf(" ");
        }
        for(int j=2*i-1;j<=2*row-1;j++){
            printf("*");
        }
        printf("\n");
    }

    return 0;
}