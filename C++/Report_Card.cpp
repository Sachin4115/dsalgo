#include<iostream>
using namespace std;
int main(){
    int num=0,sum=0,percentage=0;
    for(int i=1;i<=5;i++){
        cout<<"Enter the marks scored in subject "<<i<<" : ";
        cin>>num;
        sum+=num;
    }
    percentage=sum/5;
    if(percentage<=100&&percentage>=70){
        cout<<"First Division with "<<percentage<<"%.";
    }
    else if(percentage<=70&&percentage>=50){
        cout<<"Second Division with "<<percentage<<"%.";
    }
    else if(percentage<=50&&percentage>=35){
        cout<<"Third Division with "<<percentage<<"%.";
    }
    else if(percentage<=35&&percentage>=0){
        cout<<"You have not qualified the examination.";
    }
    else{
        cout<<"Please enter the correct marks";
    }
    return 0;
}