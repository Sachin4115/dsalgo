#include <stdio.h>

int main()
{
    int n,f[n+1];
    printf("Enter the number of terms you want to print : ");
    scanf("%d",&n);
    f[0]=0;
    f[1]=1;
    for(int i=2;i<=n;i++){
        f[i]=f[i-1]+f[i-2];
    }
    for(int i=0;i<=n;i++){
        printf("%d\t",f[i]);
    }
    return 0;
}