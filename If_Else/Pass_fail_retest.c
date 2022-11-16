#include <stdio.h>

int main()
{
    int a,b;
    printf("Enter the number scored by the student in subject A : ");
    scanf("%d",&a);
    printf("Enter the number scored by the student in subject B : ");
    scanf("%d",&b);
    if(a>=55&&b>=45){
        printf("Passed");
    }
    else if(a>=45&&a<55&&b>=55){
        printf("Passed");
    }
    else if(a>=65&b<45){
        printf("You are allowed to reappear exam for subject B.");
    }
    else{
        printf("Failed");
    }
    return 0;
}