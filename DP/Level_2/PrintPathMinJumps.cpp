#include <iostream>
#include <queue>
using namespace std;

class step{
    public:
    int index;
    // steps left
    int steps;
    // possible jumps
    int jumps;
    string pathSoFar;
    step(int i, int s, int j, string p){
        index = i;
        steps = s;
        jumps = j;
        pathSoFar = p;
    }

};

void fun(int n, int* arr){
    int dp[n];
    for(int i=0;i<n-1;i++) dp[i]=-1;
    dp[n-1]=0;
    for(int i=n-2;i>=0;i--){
        int m = INT32_MAX;
        for(int j=1;j<=arr[i] && i+j<n;j++){
            if(dp[i+j]==-1) continue;
            m=min(m,dp[i+j]);
        }
        if(m!=INT32_MAX) dp[i] = m+1;
    }
    cout<<dp[0]<<endl;
    queue<step*> q;
    q.push(new step(0,dp[0],arr[0],"0"));
    while(q.size()>0){
        step *s = q.front();
        q.pop();
        if(s->steps==0){
            cout<<s->pathSoFar<<"."<<endl;
        }
        for(int j=1;j<=s->jumps && s->index+j<n;j++){
            int currentIndex = j+s->index;
            if(dp[currentIndex] != -1 && dp[currentIndex] == s->steps-1){
                q.push(new step(currentIndex,dp[currentIndex],arr[currentIndex],s->pathSoFar+"->"+to_string(currentIndex)));
            }
        }
    }

    return;
}

int main()
{
    int n = 10;
    int arr[] = {3,3,0,2,1,2,4,2,0,0};
    fun(n,arr);
    return 0;
}