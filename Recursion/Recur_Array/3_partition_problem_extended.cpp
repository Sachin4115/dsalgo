#include <iostream>
#include <vector>
#include <numeric>
using namespace std;
bool SubExists(vector <int> &S,int n, int a, int b, int c, vector<int> &arr){
    if(a==0&&b==0&&c==0){
        return true;
    }
    if(n<0){
        return false;
    }
    bool A=false;
    if(a-S[n]>=0){
        arr[n]=1;
        A=SubExists(S,n-1,a-S[n],b,c,arr);
    }
    bool B=false;
    if(!A&&(b-S[n]>=0)){
        arr[n]=2;
        B=SubExists(S,n-1,a,b-S[n],c,arr);
    }
    bool C=false;
    if((!A&&!B)&&(c-S[n]>=0)){
        arr[n]=3;
        C=SubExists(S,n-1,a,b,c-S[n],arr);
    }
    return A||B||C;
}
int main()
{
    vector<int> S={7,3,2,1,5,4,8};
    int sum=accumulate(S.begin(),S.end(),0);
    int n=S.size();
    vector<int> arr(n);
    bool result = (n>=3) && !(sum%3) && SubExists(S,n-1,sum/3,sum/3,sum/3,arr);
    if(!result){
        cout<<"The partitions does not exists.";
    }
    else{
        for (int i = 0; i < 3; i++){
        cout << "Partition " << i << " is ";
        for (int j = 0; j < n; j++){
            if (arr[j] == i + 1) {
                cout << S[j] << " ";
            }
        }
        cout << endl;
    }
    }
    return 0;
}