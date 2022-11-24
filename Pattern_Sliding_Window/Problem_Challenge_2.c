#include <stdio.h>
#include<string.h>

int main()
{
    int flag=0,k=0,s=0;
    char str[100],substr[100],temp[100];
    printf("Enter the main string : ");
    fgets(str,100,stdin);
    printf("Enter the sub string : ");
    fgets(substr,100,stdin);
    strcpy(temp,substr);
    for(int i=s;i<strlen(str)-1;i++){
        flag=0;
        for(int j=0;j<strlen(substr)-1;j++){
            if(k<strlen(substr)-1){
                if(str[i]==substr[j]){
                    substr[j]='0';
                    k++;
                    flag=1;
                    if(k==strlen(substr)-1){
                        strcpy(substr,temp);
                        k=0;
                        printf("%d ",(i-(strlen(temp))+2));
                        s++;
                        i=s-1;
                    }
                    break;
                }
            }
        }
        if(flag==0){
            strcpy(substr,temp);
            s++;
            i=s-1;
            k=0;
        }
    }
    return 0;
}