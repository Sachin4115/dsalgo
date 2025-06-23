#include <iostream>
using namespace std;

int main()
{
    int t;
    cin>>t;
    while(t--){
        int a,x,y;
        cin>>a>>x>>y;
        int d1 = abs(a-x);
        int d2 = abs(a-y);

        bool f=0;

        for(int i=1;i<=100;i++){
            if(i==a) continue;
            int e1=abs(i-x);
            int e2=abs(i-y);

            if(e1<d1 && e2<d2){
                f=1;
                break;
            }
        }

        if(f) cout<<"YES";
        else cout<<"No";
        cout<<endl;

    }
    return 0;
}