#include <stdio.h>

int main()
{
    int Ram,Shyam,Ajay;
    printf("Enter the age of Ram : ");
    scanf("%d",&Ram);
    printf("Enter the age of Shyam : ");
    scanf("%d",&Shyam);
    printf("Enter the age of Ajay : ");
    scanf("%d",&Ajay);
    if(Ram>Shyam){
        if(Ram>Ajay){
            printf("Ram is the oldest out of the three i.e. %d years old.",Ram);
        }
        else if(Ram<Ajay){
            printf("Ajay is the oldest out of the three i.e. %d years old.",Ajay);
        }
        else{
            printf("The age of Ram and Ajay is same and both are %d year old",Ajay);
        }
    }
    else if(Ram<Shyam){
        if(Shyam>Ajay){
            printf("Shyam is the oldest out of the three i.e. %d years old.",Shyam);
        }
        else if(Shyam<Ajay){
            printf("Ajay is the oldest out of the three i.e. %d years old.",Ajay);
        }
        else{
            printf("The age of Shyam and Ajay is same and both are %d year old",Ajay);
        }
    }
    else{
        printf("The age of Ram and Shyam is same and both are %d year old",Ram);
    }
    return 0;
}