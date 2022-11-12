#include<stdio.h>

int main()
{
// Printing every number except mutiples of 3 until users says
    int n;
    printf("Enter the number of terms that you want to print : ");
    scanf("%d",&n);
    for(int i=0;i<=n;i++){
        if(i%3 == 0){
            continue;
        }
        printf("%d\n",i);
    }
    return 0;
}