#include<stdio.h>
#include<string.h>

int main() {
    int temp=0,k=0;
    char str[100], substr[100];
    printf("Enter the main string : ");
    fgets(str, 100, stdin);
    printf("Enter the sub string : ");
    fgets(substr, 100, stdin);
    for(int i=0;i<strlen(str)-1;i++){
        k=0;
        for(int j=0;j<strlen(substr)-1;j++){
            if(str[i]==substr[j]&&str[i]!=str[i-1]){
                temp++;
                k=1;
                break;
            }
        }
        if(temp!=(strlen(substr))-1&&str[i]!=str[i-1]){
            if(k==0){
                temp=0;
            }
        }
    }
    if(temp==(strlen(substr))-1){
        printf("true");
    }
    else{
        printf("False");
    }
    return 0;
}