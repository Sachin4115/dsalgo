#include <stdio.h>

int main()
{
    float hardness,carbon_content,tensile_strength;
    printf("Enter the HARDNESS of the steel : ");
    scanf("%f",&hardness);
    printf("Enter the CARBON CONTENT of the steel : ");
    scanf("%f",&carbon_content);
    printf("Enter the TENSILE STRENGTH of the steel : ");
    scanf("%f",&tensile_strength);
    if((hardness>50)&&(carbon_content<0.7)&&(tensile_strength>5600)){
        printf("The given sample of the steel is of grade 10.");
    }
    else if((hardness>50)&&(carbon_content<0.7)){
        printf("The given sample of the steel is of grade 9.");
    }
    else if((carbon_content<0.7)&&(tensile_strength>5600)){
        printf("The given sample of the steel is of grade 8.");
    }
    else if((hardness>50)&&(tensile_strength>5600)){
        printf("The given sample of the steel is of grade 7.");
    }
    else if((hardness>50)||(carbon_content<0.7)||(tensile_strength>5600)){
        printf("The given sample of the steel is of grade 6.");
    }
    else{
        printf("The given sample of the steel is of grade 5.");
    }
    return 0;
}