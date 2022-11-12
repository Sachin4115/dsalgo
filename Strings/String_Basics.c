#include <stdio.h>

void printstring(char a[]);

int main()
{
    char firstname[]={'S','a','c','h','i','n',' ','\0'};
    printf("%s",firstname);
    char secondname[]="Sachdeva";
    printf("%s\n",secondname);
    printstring(firstname);
    printstring(secondname);

    char fname[15],lname[15];
    printf("\nEnter your first name : ");
    scanf("%s",&fname);
    printf("Enter your second name : ");
    scanf("%s",&lname);
    printf("Your name is : %s %s",fname,lname);

    return 0;
}
void printstring(char a[]){
    for(int i=0;a[i]!='\0' ; i++ ){
        printf("%c",a[i]);
    }
    printf("\n");
}