#include <stdio.h>

int main()
{
    int arr[]={123,456,789,741,852,963,753,951,761,943};
    int *ptr=&arr[0];
    printf("{");
    for(int i=1;i<11;i++){
        printf("%d",*ptr);
        if(i==10){
            printf("}");
            break;
        }
        printf(",");
        ptr++;
    }
    return 0;
}