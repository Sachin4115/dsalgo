#include<stdio.h>

void printtable(int n);

int table(int n,int i);
int main()
{
    int n,product;
    printf("Enter the number whose table you want to print : ");
    scanf("%d",&n);
    for(int i=1;i<=10;i++){
        product=table(n,i);//argument/actual parameter
        printf("%d x %d = %d\n",n,i,product);
    }
    printf("\n");
    printtable(n);
    return 0;
}
int table(int n,int i)/*parameter/formal parameter*/ {
    return n*i;
}
void printtable(int n){
    for(int i = 1; i<=10;i++){
        printf("%d x %d = %d\n",n,i,n*i);
    }

}