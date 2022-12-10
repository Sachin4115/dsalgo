// Given a string S that represents a DNA sequence, return all the 10-letter-long sequences (substrings) that occur
// more than once in a DNA molecule. You may return the answer in any order.
#include <iostream>
#include <string>
#include <vector>
#include <unordered_map>
using namespace std;

int main()
{
    string s;
    unordered_map<string, int> map;
    unordered_map<string, int> :: iterator iter;
    cout<<"Enter the string : ";
    cin>>s;
        int left = 0;
        for (int i = 0; i < s.size(); i++)
        {
            if (i > 0 && (i - left) % 9 == 0)
            {
                map[s.substr(left, 10)]++;
                left++;
            }
        }

        vector<string> arr;
        for (iter=map.begin();iter!=map.end();iter++)
        {
            if ((*iter).second > 1)
                arr.push_back((*iter).first);
        }
    for(int i=0;i<arr.size();i++){
        cout<<arr[i]<<" ";
    }
}