#include <iostream>
using namespace std;

class base{
    public:
    virtual void print(){
        cout<<"This is the base classes print function."<<endl;
    }
    void display(){
        cout<<"This is the base classes display function."<<endl;
    }

};
class derived: public base{
    public:
    void print(){
        cout<<"This is the derived classes print function."<<endl;
    }
    void display(){
        cout<<"This is the derived classes display function."<<endl;
    }

};

int main()
{
    base *baseptr;
    derived d;
    baseptr=&d;

    baseptr -> print();

    baseptr -> display();
    return 0;
}