#include<stdio.h>

int main()
{
    int n;
    for(int i=1;;i++){
        printf("Enter the number of terms that you want to add");
        scanf("%d",&n);
        if(n%2==1){
            break;
        }
    }
    printf("The End");
    return 0;
}