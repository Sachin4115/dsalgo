#include <bits/stdc++.h>

using namespace std;

pair<int, int> getFloorAndCeil(int arr[], int n, int x);

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n, x;
        cin >> n >> x;
        int arr[n];
        for (int i = 0; i < n; i++) {
            cin >> arr[i];
        }
        auto ans = getFloorAndCeil(arr, n, x);
        cout << ans.first << " " << ans.second << "\n";
    }
    return 0;
}

pair<int, int> getFloorAndCeil(int arr[], int n, int x) {
    int f=INT_MIN,c=INT_MAX;
    for(int i=0;i<n;i++){
        if(arr[i]<=x){
            f=max(f,arr[i]);
        }
        if(arr[i]>=x){
            c=min(c,arr[i]);
        }
    }
    if(f==INT_MIN)
        f=-1;
    if(c==INT_MAX)
        c=-1;
    pair<int,int> p={f,c};
    return p;

}