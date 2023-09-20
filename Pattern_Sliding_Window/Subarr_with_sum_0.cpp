// Given an array of positive and negative numbers. Find if there is a
// subarray (of size at-least one) with 0 sum.

#include <iostream>
#include <unordered_set>

using namespace std;

class Solution{
    public:
    bool subArrayExists(int arr[], int n)
    {
        int sum=0;
        unordered_set<int>s;
        for(int i=0;i<n;i++){
            sum+=arr[i];
            if(sum==0 || s.find(sum)!=s.end())
                return 1;
            s.insert(sum);
        }
        return 0;
    }
};

int main()
{
	int t;
	cin>>t;
	while(t--)
	{
	    int n;
	    cin>>n;
	    int arr[n];
	    for(int i=0;i<n;i++)
	    cin>>arr[i];
	    Solution obj;
	    	if (obj.subArrayExists(arr, n))
		cout << "Yes\n";
	else
		cout << "No\n";
	}
	return 0;
}