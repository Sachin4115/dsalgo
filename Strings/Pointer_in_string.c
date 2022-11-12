#include <stdio.h>

int main()
{
    char str[]="Hello World";//Cannot be reintialized.
    char *name = "Byy Motto";//Can be reintialized.

    gets(str);
    puts(name);

    str[]="Hello World:)";
    &name = "Byy Motto:)";

    gets(str);
    puts(name);

    return 0;
}