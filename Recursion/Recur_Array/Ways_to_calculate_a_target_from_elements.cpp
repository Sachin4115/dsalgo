#include <iostream>
#include <vector>
using namespace std;
int countways(vector <int> arr,int i,int target){
    if(i==arr.size()&&target==0)
        return 1;
    if(i==arr.size())
        return 0;
    int ignore = countways(arr,i+1,target);
    int add = countways(arr,i+1,target+arr[i]);
    int minus = countways(arr,i+1,target-arr[i]);
    return ignore+add+minus;
}
int main()
{
    vector<int> arr = {5,3,-6,2};
    int target =6;
    cout << countways(arr,0,target);
    return 0;
}