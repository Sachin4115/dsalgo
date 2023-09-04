#include <iostream>
#include <string>
using namespace std;
class student{
    string name;
    public:
    int age;
    bool gender;
    student(){
        cout<<"Default Constructor"<<endl;
    }//Default Constructor
    student(string s,int a,bool g){
        name=s;
        age=a;
        gender=g;
        cout<<"Parameterised Constructor"<<endl;
    }//Parameterised Constructor
    student(student &a){
        name=a.name;
        age=a.age;
        gender=a.gender;
        cout<<"Copy Constructor"<<endl;
    }//Copy Constructor

    void printinfo(){
        cout<<"Name = "<<name<<endl;
        cout<<"Age = "<<age<<endl;
        cout<<"Gender = "<<gender<<endl;
    }
    void setname(string s){
        name=s;
    }
    void getname(){
        cout<<name<<endl;
    }
    ~student(){
        cout<<"Destructor called"<<endl;
    }
    // Operator Overloading
    bool operator == (student &a){
        if(name==a.name && age==a.age && gender==a.gender)
            return true;
        return false;
    }
};
int main()
{
    // student arr[3];
    // for(int i=0;i<3;i++){
    //     cout<<"Name : ";
    //     string s;
    //     cin>>s;
    //     arr[i].setname(s);
    //     cout<<"Age : ";
    //     cin>>arr[i].age;
    //     cout<<"Gender : ";
    //     cin>>arr[i].gender;
    // }
    // for(int i=0;i<3;i++){
    //     arr[i].printinfo();
    // }

    student a("Sachin",17,0);
    // a.printinfo();
    student b("Sachdeva",18,1);
    student c=a;
    if(c==a){
        cout<<"same"<<endl;
    }
    else{
        cout<<"not same"<<endl;
    }
    if(b==a){
        cout<<"same"<<endl;
    }
    else{
        cout<<"not same"<<endl;
    }
    return 0;
}