#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int fenwickTree[200010],n;

void updateFenwickTree(int x){
    while(x<=n){
        fenwickTree[x]++;
        x+=(x&-x);
    }
}

int queryFenwickTree(int x){
    int ans=0;
    while(x){
        ans+=fenwickTree[x];
        x-=(x&-x);
    }
    return ans;
}

long long parityOfInversion(vector<int> &a){
    for(int i=0;i<=n;i++) fenwickTree[i]=0;
    long long ans=0;
    for(int i=a.size()-1;i>=0;i--){
        ans+=queryFenwickTree(a[i]);
        updateFenwickTree(a[i]);
    }
    return ans;
}

int main()
{
    int t;
    cin>>t;
    while(t--){
        // int n;
        cin>>n;
        int arr[n+1];
        arr[0]=0;
        for(int i=1;i<=n;i++) cin>>arr[i];
        // for(int i=0;i<n;i++) cout<<arr[i]<<" ";
        // cout<<endl;
        vector<int>a;
        vector<int>b;
        for(int i=1;i<=n;i++){
            if(i%2==1) a.push_back(arr[i]);
            else b.push_back(arr[i]);
        }
        bool v = (parityOfInversion(a)%2 != parityOfInversion(b)%2);
        sort(a.begin(),a.end());
        sort(b.begin(),b.end());
        // for(int i:a) cout<<i<<" ";
        // cout<<endl;
        // for(int i:b) cout<<i<<" ";
        // cout<<endl;
        int q=0,w=0;
        for(int i=1;i<=n;i++){
            if(i%2==1) arr[i]=a[q++];
            else arr[i]=b[w++];
        }
        if(v){
            swap(arr[n],arr[n-2]);
        }
        for(int i=1;i<=n;i++) cout<<arr[i]<<" ";
        cout<<endl;
    }
    return 0;
}