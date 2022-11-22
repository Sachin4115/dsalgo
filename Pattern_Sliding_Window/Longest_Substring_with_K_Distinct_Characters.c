#include <stdio.h>
#include <string.h>

int main()
{
    int i, j, l, k,max_temp=0, max=0, temp, unique_char=0;
    char str[100];
    printf("Enter the string : ");
    fgets(str, 100, stdin);
    printf("Enter the no. of distinct characters : ");
    scanf("%d", &k);
    for(l=0;l<strlen(str);l++){
        max_temp=0;
    for(i=l;i<strlen(str);i++){
        temp=1;
        for(j=i-1;j>=0;j--){
                if(str[i]==str[j]){
                    max_temp++;
                    temp=0;
                    break;
                }
        }
        if(temp==1){
            unique_char++;
            if(unique_char>k){
                break;
            }
            max_temp++;
        }
        if(max_temp>max){
            max=max_temp;
        }
    }
    }
    printf("%d",max);
    return 0;
}