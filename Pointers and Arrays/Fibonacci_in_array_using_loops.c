#include <stdio.h>

int main()
{
    int n;
    printf("Enter the number of terms that you wnt to print : ");
    scanf("%d",&n);
    int arr[n];
    int a=1,b=0;
    for(int i=0;i<n;i++){
        if(i==0){
            printf("The %dth term of the Fibonacci Sequence is 0\n",i);
            continue;
        }
        if(i==2){
            printf("The %dth term of the Fibonacci Sequence is 1\n",i);
            continue;
        }
        int c=a+b;
        b=a;
        a=c;
        arr[i]=c;
        printf("The %dth term of the Fibonacci Sequence is %d\n",i,arr[i]);
    }
    return 0;
}