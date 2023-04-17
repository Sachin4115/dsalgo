#include <iostream>
#include <vector>
#include <climits>
using namespace std;
int calc_max_V_by_including_and_excluding(vector <int> &v,vector <int> w,int n, int W){
    if(W<0)
        return INT_MIN;
    if(n<0||W==0)
        return 0;
//**
    int inc=v[n]+calc_max_V_by_including_and_excluding(v,w,n-1,W-w[n]);
    int exc=calc_max_V_by_including_and_excluding(v,w,n-1,W);
    return max(inc,exc);
}
int main()
{
    vector <int> v;
    vector <int> w;
    int W,n,element;
    cout<<"Enter the number of elements you want to enter in the v array : ";
    cin>>n;
    for(int i=0;i<n;i++){
        cout<<"Enter the element in the "<<i<<"th position : ";
        cin>>element;
        v.push_back(element);
    }
    cout<<"Enter the number of elements you want to enter in the w array : ";
    cin>>n;
    for(int i=0;i<n;i++){
        cout<<"Enter the element in the "<<i<<"th position : ";
        cin>>element;
        w.push_back(element);
    }
    cout<<"Enter the maximum value of weight : ";
    cin>>W;
    int max_V=calc_max_V_by_including_and_excluding(v,w,n,W);
    cout<<max_V;
    return 0;
}