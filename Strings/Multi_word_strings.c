#include <stdio.h>

int main()
{
    //char fullname[50];
    // printf("Enter your full name : ");
    // scanf("%s",&fullname);
    // printf("%s\n",fullname);
//You can not scan multi words using %s,so we use gets(str)         --> outdated & dangerour
                                                //puts(str)         --> output a string
                                                //fgets(str,n,file) --> stops when n-1 char input or new line is entered
    char str[50];
    gets(str);
    puts(str);

    char newstr[100];
    fgets(newstr,100,stdin);
    puts(newstr);
    return 0;
}