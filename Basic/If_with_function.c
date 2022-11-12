#include<stdio.h>

void printnamaste();
void printbonjour();

int main()
{
    char nationality;
    printf("Enter the LETTER corresponding to your nationality.\n 1.India --> I\n 2.France --> F\n -->");
    scanf("%c",&nationality);

    if(nationality=='I'){
        printnamaste();
    }
    else if(nationality=='F'){
        printbonjour();
    }
    else{
        printf("Please enter the correct letter.");
    }
    return 0;
}

void printnamaste(){
    printf("Namaste\n");
}
void printbonjour(){
    printf("Bonjour\n");
}