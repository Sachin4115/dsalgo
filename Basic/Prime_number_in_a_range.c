#include<stdio.h>

int main()
{
    int a,l,f;
    printf("Enter the intial term : ");
    scanf("%d",&a);
    printf("Enter the final term : ");
    scanf("%d",&l);
    for(int i=a;i<=l;i++){
        f=1;
        for(int j=2;j<i;j++){
            if(i%j==0){
                f=0;
                break;
            }
        }
        if(f==1){
            printf("%d\n",i);
        }
    }
    return 0;
}
