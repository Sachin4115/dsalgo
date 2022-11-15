#include <stdio.h>

int main()
{
    char test;
    printf("Enter the character you want to check : ");
    scanf("%s",&test);
    if(test>65&&test<90){
        printf("The entered character is a capital letter.");
    }
    else if(test>97&&test<122){
        printf("The entered character is a small letter.");
    }
    else if(test>48&&test<57){
        printf("The entered character is  number ");
    }
    else if((test>0&&test<47)||(test>58&&test<64)||(test>91&&test<96)||(test>123&&test<127)){
        printf("The entered character is a special character.");
    }
    else{
        printf("Please enter a valid character.");
    }
    return 0;
}