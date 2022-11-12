#include<stdio.h>

void printhello();
void printgoodby();
int main()
{
    for(int i=1;i<=5;i++){
    printhello();
    printgoodby();
    printf("\n");
    }
    return 0;
}
void printhello(){
    printf("Hello!\n");
}
void printgoodby(){
    printf("Good By:)\n");
}