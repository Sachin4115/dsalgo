#include <iostream>
#include <vector>
using namespace std;

int MinBitFlips(int n,int m){
    int res = n^m;
    int ans=0;
    while(res){
        ans++;
        res=(res&(res-1));
    }
    return ans;
}

vector<vector<int>> PowerSet(vector<int> arr){
    vector<vector<int>> ans;
    int n = 1<<arr.size();
    for(int i=0;i<n;i++){
        vector<int> res;
        for(int j=0;j<arr.size();j++){
            if(i&(1<<j))
                res.push_back(arr[j]);
        }
        ans.push_back(res);
    }
    return ans;
}

// No. that appears only ones, where every other element appears twice
int SingleNumber(vector<int> arr){
    int ans=arr[0];
    for(int i=1;i<arr.size();i++){
        ans^=arr[i];
    }
    // cout<<ans<<endl;
    return ans;
}

// No. that appears only ones, where every other element appears thrice
int SingleNumber2(vector<int> arr){
    int ans=0;
    for(int bit=0;bit<32;bit++){
        int k=0;
        for(int i=0;i<arr.size();i++){
            if((arr[i]&(1<<bit)))
                k++;
        }
        if(k%3==1)
            ans=(ans|(1<<bit));
    }
    return ans;
}

// No. that appears only ones, where every other element appears thrice
// Better Approach
// Time O(n) Space O(1)
int SingleNumber2_1(vector<int> arr){
    int ones=0;
    int twos=0;

    for(int i=0;i<arr.size();i++){
        ones = ((ones ^ arr[i]) & ~(twos));
        twos = ((twos ^ arr[i]) & ~(ones));
    }

    return ones;
}

// Two numbers that appears only ones, where every other element appears twice
vector<int> SingleNumber3(vector<int> arr){

    // If x = INT_MIN i.e., -2^31 the -x won't be saved in int format as it will me 2^31 but max
    // a int can store is INT_MAX i.e., 2^31-1. So we will use long long.
    long x = 0;
    for(int i=0;i<arr.size();i++){
        x = x^arr[i];
    }
    int RightBitMask = x & -x;
    int ans1=0,ans2=0;
    for(int i=0;i<arr.size();i++){
        if(arr[i]&RightBitMask)
            ans1 = ans1 ^ arr[i];
        else
            ans2 = ans2 ^ arr[i];
    }
    vector<int>ans;
    ans.push_back(ans1);
    ans.push_back(ans2);
    return ans;

}


// for n        Range XOR
// 1                1
// 2                3
// 3                0
// 4                4
//
// 5                1
// 6                7
// 7                0
// 8                8
int XorRangeTillN(int n){
    if(n<=0)
        return 0;
    int k=n%4;
    if(k==1)
        return 1;
    else if(k==2)
        return n+1;
    else if(k==3)
        return 0;
    else
        return n;
}

int XorRangeFromNtoM(int n,int m){
    // n<m always
    return (XorRangeTillN(n-1)^XorRangeTillN(m));
}

int main()
{
    cout<<MinBitFlips(7,8)<<endl;
    cout<<MinBitFlips(5,4)<<endl;
    cout<<MinBitFlips(1,11)<<endl;
    cout<<endl;
    vector<vector<int>> ans = PowerSet({1,2,3});
    cout<<"{";
    for(vector a:ans){
        cout<<"{";
        for(int e : a){
            cout<<" "<<e<<" ";
        }
        cout<<"}, ";
    }
    cout<<"}"<<endl;
    cout<<SingleNumber({1,2,3,4,5,6,7,7,6,5,3,2,1})<<endl;
    cout<<SingleNumber2({1,2,2,2,3,3,3,4,4,4,5,5,5,6,6,6})<<endl;
    cout<<SingleNumber2_1({1,2,2,2,3,3,3,4,4,4,5,5,5,6,6,6})<<endl;
    vector<int> res;
    res = SingleNumber3({1,2,3,4,5,6,7,7,6,5,INT_MIN,3,2,1});
    cout<<res[0]<<","<<res[1]<<endl;
    cout<<XorRangeTillN(15)<<endl;
    cout<<XorRangeFromNtoM(5,15)<<endl;
    return 0;
}