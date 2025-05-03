#include <iostream>
using namespace std;

int main()
{
    int t;
    cin>>t;
    while(t--){
        int f[10];
        string s;
        cin>>s;
        for(int i=0;i<10;i++) {f[i]=0;}
        for(char i:s) f[i-'0']++;
        for(int i=0;i<10;i++){
            int w=9-i;
            for(int k=w;k<10;k++){
                if(f[k]>0){
                    f[k]--;
                    cout<<k;
                    break;
                }
            }
        }
        cout<<endl;
    }

    return 0;
}