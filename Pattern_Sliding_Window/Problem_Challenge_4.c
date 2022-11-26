#include <stdio.h>
#include <string.h>

int main()
{
    int flag=0,k=0,t=0,arr[10],r=0;
    char str[100],substr[100],temp[100],temp1[100],subcpy[100];
    printf("Enter the main string : ");
    fgets(str,100,stdin);
    printf("Enter the three letter words you want to search without spaces : ");
    fgets(substr,100,stdin);
    strcpy(subcpy,substr);
    for(int i=0;i<strlen(str)-1;i++){
        strncpy(temp1,str+i,3);
        flag=0;
        for(int j=0;j<strlen(substr)-1;j=j+3){
            strncpy(temp,substr+j,3);
            if(temp[0]==temp1[0]&&temp[1]==temp1[1]&&temp[2]==temp1[2]){
                k++;
                if(k==1){
                    t=i;
                }
                flag=1;
                i+=2;
                for(int l=0;l<3;l++){
                    substr[j+l]='0';
                }
            }
        }
        if(k*3==strlen(substr)-1){
            k=0;
            i=t;
            arr[r]=t;
            r++;
            strcpy(substr,subcpy);
        }
        else if(flag==0&&k==0){
            strcpy(substr,subcpy);
            k=0;
        }
        else if(flag==0&&k!=0){
            strcpy(substr,subcpy);
            i=i-3;
            k=0;
        }
    }
    for(int i=0;i<r;i++){
    printf("\t%d",arr[i]);
    }
    return 0;
}
