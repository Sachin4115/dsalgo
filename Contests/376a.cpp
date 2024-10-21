// There is a mysterious button. When you press this button, you receive one candy, unless less than C seconds have
// elapsed since you last received a candy. Takahashi decided to press this button N times. He will press the button
// for the i-th time Ti seconds from now.

#include <iostream>
using namespace std;

int main()
{
    int n,c;
    cin>>n>>c;
    int arr[n];
    for(int i=0;i<n;i++)
        cin>>arr[i];
    int l = 0, a=1;
    for(int i=1;i<n;i++){
        if(arr[i]-arr[l]>=c){
            l=i;
            a++;
        }
    }
    cout<<a<<endl;
    return 0;
}