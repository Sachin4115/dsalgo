#include <stdio.h>
#include <string.h>

int main()
{
    int n,freq1,freq2,max1=0,max2=0;
    char arr[100],element1,element2;
    printf("Enter the elements of the array : ");
    fgets(arr,100,stdin);
    n=strlen(arr);
    for(int i=0;i<n;i++){
        freq1=0;
        for(int j=i;j<n;j++){
            if(arr[i]==arr[j]){
                freq1++;
                if(freq1>max1){
                    element1=arr[i];
                    max1=freq1;
                }
            }
        }
    }
    for(int i=0;i<n;i++){
        freq2=0;
        for(int j=i;j<n;j++){
            if(arr[i]!=element1)
            {
                if(arr[i]==arr[j]){
                    freq2++;
                    if(freq2>max2){
                        element2=arr[i];
                        max2=freq2;
                    }
                }
            }
            else{
                continue;
            }
        }
    }
    printf("\nWe can put %d element '%c' in first basket.",max1,element1);
    printf("\nWe can put %d element '%c' in second basket.",max2,element2);
    return 0;
}