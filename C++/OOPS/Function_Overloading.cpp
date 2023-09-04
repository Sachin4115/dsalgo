#include <iostream>
#include <string>
using namespace std;

class Sachin{
    public:
    void fun(){
        cout<<"No Input"<<endl;
    }
    void fun(int x){
        cout<<"Int Input"<<endl;
    }
    void fun(double x){
        cout<<"Double Input"<<endl;
    }
    void fun(float x){
        cout<<"Float Input"<<endl;
    }
};

int main()
{
    Sachin sach;
    sach.fun();
    sach.fun(2);
    sach.fun(2.3);
    sach.fun(2.3f);
    return 0;
}