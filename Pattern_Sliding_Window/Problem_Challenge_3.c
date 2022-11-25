#include <stdio.h>
#include<string.h>

int main()
{
    int flag=0,start,stop,position,i,result=999999,result_temp=1000000,open,close;
    char str[100],substr[100],temp[100];
    printf("Enter the string : ");
    fgets(str,100,stdin);
    printf("Enter the sub string : ");
    fgets(substr,100,stdin);
    strcpy(temp,substr);
    for(start=0;start<strlen(str)-1;start++){
        for(stop=strlen(str)-2;stop>=start;stop--){
            flag=0;
            for(position=start;position<=stop;position++){
                for(i=0;i<strlen(substr)-1;i++){
                    if(str[position]==substr[i]){
                        substr[i]='o';
                    }
                }
            }
            for(i=0;i<strlen(substr)-1;i++){
                if(substr[i]==temp[i]){
                    flag=1;
                    strcpy(substr,temp);
                }
            }
            if(flag==0){
                result_temp=stop-start+1;
                strcpy(substr,temp);
                if(result_temp<result){
                    result=result_temp;
                    open=start;
                    close=stop;
                }
            }
        }
    }
    if(result!=999999){
        for(i=open;i<=close;i++){
            printf("%c",str[i]);
        }
    }
    else{
        printf("The sub string that you entered is not present in the given string.");
    }
    return 0;
}