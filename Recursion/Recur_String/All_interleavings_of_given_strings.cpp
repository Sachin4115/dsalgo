#include <iostream>
#include <string>
#include <unordered_set>
using namespace std;
void allinterleavings(string str, string X, string Y, auto &interleavings){
    if(!X.length()&&!Y.length()){
        interleavings.insert(str);
        return;
    }
    if(X.length()){
        allinterleavings(str+X[0],X.substr(1),Y,interleavings);
    }
    if(Y.length()){
        allinterleavings(str+Y[0],X,Y.substr(1),interleavings);
    }

}
int main()
{
    string X,Y;
    cout<<"Enter the first string : ";
    cin>>X;
    cout<<"Enter the second string : ";
    cin>>Y;
    unordered_set<string> interleavings;
    allinterleavings("",X,Y,interleavings);
    for(string s : interleavings){
        cout<< s <<endl;
    }

    return 0;
}