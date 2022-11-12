#include <stdio.h>

int main()
{
    char ch;
    char *ptr=&ch;
    for(*ptr = 'A';*ptr <='Z';(*ptr)++){
        printf("%c\n",*ptr);
    }
    return 0;
}