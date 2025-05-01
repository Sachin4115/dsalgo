#include <iostream>
using namespace std;

int main()
{
    int t;
    cin>>t;
    while(t--){
        long n,x;
        cin>>n>>x;
        long a=0;
        int c=x;
        if(x==0){
            if(n==1){
                cout<<-1<<endl;
            }else if(n%2){
                cout<<n+3<<endl;
            }else{
                cout<<n<<endl;
            }
            continue;
        }else if(n==1){
            cout<<x<<endl;
            continue;
        }
        else if(x==1){
            if(n%2) cout<<n<<endl;
            else{
                cout<<n+3<<endl;
            }
            continue;
        }
        while(c){
            if(c%2) a++;
            c/=2;
        }
        // if(x==3){
        //     cout<<a<<" "<<n<<" ";
        // }
        if(a>=n){
            cout<<x<<endl;
            continue;
        }
        long q=n-a;
        if((q)%2){
            a=q+1;
        }else{
            a=q;
        }
        a+=x;
        cout<<a<<endl;
    }
    return 0;
}