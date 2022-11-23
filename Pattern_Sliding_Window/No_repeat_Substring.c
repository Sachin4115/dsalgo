#include <stdio.h>
#include <string.h>

int main()
{
    char str[100],distinct[100];
    int temp,n=0,k;
    printf("Enter the string : ");
    fgets(str, 100, stdin);
    printf("Enter the length of the substring : ");
    scanf("%d", &k);
    for(int i=0;i<strlen(str);i++){
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
    for(int i=0;i<k;i++){
        printf("%c",distinct[i]);
    }
    return 0;
}