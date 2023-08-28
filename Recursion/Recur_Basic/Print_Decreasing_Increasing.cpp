#include <iostream>
using namespace std;
void print_DI(int n){
    if(n==0)
        return;
    cout<<n<<endl;
    print_DI(n-1);
    cout<<n<<endl;
}
int main()
{
    int n=5;
    print_DI(n);
    return 0;
}