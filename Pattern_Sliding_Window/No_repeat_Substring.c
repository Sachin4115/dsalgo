#include <stdio.h>
#include <string.h>

int main()
{
    char str[100],distinct[100];
    int temp,n=0,k;
    printf("Enter the string : ");
    fgets(str, 100, stdin);
    k=strlen(str);
    for(int i=0;i<strlen(str)-1;i++){
        temp=0;
        for(int j=i-1;j>=0;j--){
            if(str[i]==str[j]){
                temp=1;
            }
        }
        if(temp==0){
            distinct[n]=str[i];
            n++;
        }
    }
    for(int i=0;i<n;i++){
        printf("%c",distinct[i]);
    }
    return 0;
}