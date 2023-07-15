#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
void printvector(vector <int> R){
    cout << "[";
    int n = R.size();
    for (int i: R) {
        cout << i;
        if (--n) {
            cout << ", ";
        }
    }
    cout << "]\n";
}
void powerset(vector<int> S,vector<int> R,int i){
    if(i<0){
        printvector(R);
        return;
    }
    R.push_back(S[i]);
    powerset(S,R,i-1);
    R.pop_back();
    while(S[i]==S[i-1])
        i--;
    powerset(S,R,i-1);


}

int main()
{
    vector<int> S={1,2,1};
    sort(S.begin(),S.end());
    vector <int> R;
    powerset(S,R,S.size()-1);
    return 0;
}