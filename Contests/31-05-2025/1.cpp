#include <iostream>
using namespace std;

int main()
{
    int t;
    cin>>t;
    while(t--){
        int a,b,c,d;
        cin>>a>>b>>c>>d;
        if(a<d && b<=c){
            if(b<=a){
                cout<<"Gellyfish";
            }else{
                cout<<"Flower";
            }
        }else if(a>=d && b<=c){
            cout<<"Gellyfish";
        }else if(a<d && b>= c+1){
            cout<<"Flower";
        }else{
            if(d<=c){
                cout<<"Gellyfish";
            }else{
                cout<<"Flower";
            }
        }
        cout<<endl;
    }
    return 0;
}