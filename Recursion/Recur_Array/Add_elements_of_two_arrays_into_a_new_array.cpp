#include <iostream>
#include <vector>
using namespace std;
void split(int element, vector<int> &result){
    if(element>0){
        split(element/10,result);
        result.push_back(element%10);
    }
}
void add(vector<int> a,vector<int> b,vector<int> &result,int i){
    if(i==max(a.size(),b.size()))
        return;
    if(i<min(a.size(),b.size())){
        int element=a[i]+b[i];
        if(element>9)
            split(element,result);
        else
            result.push_back(element);
        add(a, b, result,i+1);
    }
    else{
        if(a.size()==min(a.size(),b.size())){
            int element=b[i];
            if(element>9)
            split(element,result);
            else
            result.push_back(element);
            add(a, b, result,i+1);
        }
        else{
            int element=a[i];
            if(element>9)
            split(element,result);
            else
            result.push_back(element);
            add(a, b, result,i+1);
        }
    }
}
int main()
{
    vector<int> a = { 23, 5, 2, 7, 87,5,10,785 };
    vector<int> b = { 4, 67, 2, 8 };
    vector<int> result;
    add(a, b, result,0);
    for (int i: result) {
        cout << i << " ";
    }
    return 0;
}