#include <stdio.h>
#include<string.h>

int main()
{
    int k,freq,max=0,to_be_changed;
    char str[100],element;
    printf("Enter the string : ");
    fgets(str, 100, stdin);
    printf("Enter the minimum time replacement can take place : ");
    scanf("%d",&k);
    for(int i=0;i<strlen(str);i++){
        freq=0;
        to_be_changed=0;
        for(int j=i;j<strlen(str);j++){
            if(str[i]==str[j]){
                freq++;
                if(max<freq){
                    max=freq;
                    element=str[i];
                }
            }
            else{
                if(to_be_changed>k){
                    break;
                }
                to_be_changed++;
            }
        }
    }
    printf("Longest string length of %c as only character : %d.",element,max+k);

    return 0;
}