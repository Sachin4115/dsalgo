#include <iostream>
using namespace std;

int main()
{
    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        int arr[n];
        for(int i=0;i<n;i++) cin>>arr[i];
        int q=0,m=arr[0];
        int a=0,b=0,s=0,w=0,e=0;
        for(int i=1;i<n;i++){
            int c = arr[i];
            if(c>m) a++;
            else b++;
            if((c<m && -c>m)||(c>m && -c<m)){
                 s++;
            }
            else if(c>m && -c>m) w++;
            else e++;
        }
        // cout<<"\t"<<q<<endl;
        if(a==b) cout<<"Yes";
        else if(abs(w-e)<=s) cout<<"Yes";
        else if(abs(abs(w-e)-s)==1 && n%2==0) cout<<"Yes";
        else cout<<"No";
        cout<<endl;
    }
    return 0;
}