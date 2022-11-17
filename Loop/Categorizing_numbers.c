#include <stdio.h>

int main()
{
    int num,p=0,n=0,z=0,turn;
    printf("Enter the number of terms you want to enter : ");
    scanf("%d",&turn);
    for(int i=1;i<=turn;i++){
        printf("\nEnter the number you want to classify : ");
        scanf("%d",&num);
        if(num>0){
            p+=1;
        }
        else if(num<0){
            n+=1;
        }
        else{
            z+=1;
        }
    }
    printf("\nThe number of the positive terms that the user entered are %d",p);
    printf("\nThe number of the negative terms that the user entered are %d",n);
    printf("\nThe number of the zero terms that the user entered are %d",z);
    return 0;
}