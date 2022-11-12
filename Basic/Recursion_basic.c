#include <stdio.h>

void printhello(int count);
int main()
{
    int count;
    printf("Enter the number of times you want to print 'Hello' : ");
    scanf("%d",&count);
    printhello(count);
    return 0;
}
void printhello(int count){
    if(count>0){
        count--;
        printhello(count);
        printf("Hello\n");
    }
}