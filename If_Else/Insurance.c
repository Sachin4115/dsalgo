#include <stdio.h>

int main()
{
    char l,g,h;
    int age;
    printf("Enter the age of the person : ");
    scanf("%d",&age);
    printf("Enter the m for male and f for female : ");
    scanf("\n%c",&g);
    printf("Enter c for city and v for village : ");
    scanf("\n%c",&l);
    printf("Enter e for excellent health and p poor health : ");
    scanf("\n%c",&h);
    if((g=='m')&&(l=='c')&&(h=='e')&&(age>=25||age<=35)){
        printf("The premium is Rs. 4 per thousand and his policy amount cannot exceed Rs. 2 lakhs.");
    }

    else if((g=='f')&&(l=='c')&&(h=='e')&&(age>=25||age<=35)){
        printf("The premium is Rs. 3 per thousand and her policy amount cannot exceed Rs. 1 lakh.");
    }

    else if((g=='m')&&(l=='v')&&(h=='p')&&(age>=25||age<=35)){
        printf("the premium is Rs. 6 per thousand and his policy cannot exceed Rs. 10,000.");
    }

    else{
        printf("Sorry, you are not eligeble to get medical ensurance.");
    }
    return 0;
}