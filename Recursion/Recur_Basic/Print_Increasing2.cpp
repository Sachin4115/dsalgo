#include <iostream>
using namespace std;
void print_increasing(int n){
    if(n==0)
        return;
    print_increasing(n-1);
    cout<<n<<endl;
}
int main()
{
    int n=5;
    print_increasing(n);
    return 0;
}