#include <iostream>
#include <vector>
using namespace std;

int main()
{
    string s1,s2;
    cin>>s1>>s2;
    int n=s1.length();
    vector<vector<int>> a (n,vector<int>(n,0));
    vector<vector<int>> b (n,vector<int>(n,0));
    for(int g=0;g<n;g++){
        for(int i=0,j=g;j<n;i++,j++){
            if(g==0){
                if(s1[i]=='T') a[i][j]=1;
                else b[i][j]=1;
            }else{
                int t=0,f=0;
                for(int k=i;k<j;k++){
                    int l1=a[i][k];
                    int l2=b[i][k];
                    int r1=a[k+1][j];
                    int r2=b[k+1][j];
                    if(s2[k]=='&'){
                        t+=(l1*r1);
                        f+=(l1*r2)+(l2*r1)+(l2*r2);
                    }else if(s2[k]=='|'){
                        t+=(l1*r2)+(l2*r1)+(l1*r1);
                        f+=(l2*r2);
                    }else{
                        t+=(l1*r2)+(l2*r1);
                        f+=(l1*r1)+(l2*r2);
                    }
                }
                a[i][j]=t;
                b[i][j]=f;
            }
        }
    }
    cout<<a[0][n-1];
    return 0;
}