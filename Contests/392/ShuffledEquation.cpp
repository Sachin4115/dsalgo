#include <iostream>
using namespace std;

int main()
{
    int a, b, c;
    cin>>a>>b>>c;
    bool f=false;
    if(a*b==c || a*c==b || b*c==a) f=true;
    if(f) cout<<"Yes"<<endl;
    else cout<<"No"<<endl;
    return 0;
}