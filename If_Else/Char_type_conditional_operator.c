#include <stdio.h>

int main()
{
    char test;
    printf("Enter the character you want to test : ");
    scanf("%s",&test);
    test>97&&test<122?printf("The entered character is a small character."):printf("The entered character is not a small character.");
    (test>0&&test<47)||(test>58&&test<64)||(test>91&&test<96)||(test>123&&test<127)?printf("\nThe entered character is a special character."):printf("\nThe entered character is not a special character.");
    return 0;
}