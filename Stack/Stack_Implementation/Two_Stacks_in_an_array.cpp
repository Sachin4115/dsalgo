#include <iostream>
using namespace std;

class customStack{

    int arr[5];
    int top1=-1;
    int top2=5;

    public:

    void push1(int val){
        if(top1+1<top2){
            arr[++top1]=val;
        }
        else{
            cout<<"Stack OverFlow"<<endl;
        }
    }

    void push2(int val){
        if(top2-1>top1){
            arr[--top2]=val;
        }
        else{
            cout<<"Stack OverFlow"<<endl;
        }
    }

    int pop1(){
        if(top1>-1)
            return arr[top1--];
        cout<<"Stack UnderFlow"<<endl;
        return -1;
    }

    int pop2(){
        if(top2<5)
            return arr[top2++];
        cout<<"Stack UnderFlow"<<endl;
        return -1;
    }

    int Top1(){
        if(top1>-1)
            return arr[top1];
        cout<<"Stack UnderFlow"<<endl;
        return -1;
    }

    int Top2(){
        if(top2<5)
            return arr[top2];
        cout<<"Stack UnderFlow"<<endl;
        return -1;
    }

    int size1(){
        return top1+1;
    }

    int size2(){
        return 5-top2;
    }
};


int main()
{
    customStack st = customStack();
    st.push1(10);
    st.push1(20);
    st.push2(30);
    st.push2(40);
    st.push2(50);
    st.push1(60);
    st.push2(60);

    cout<<st.Top1()<<endl;
    cout<<st.Top2()<<endl;

    cout<<st.size1()<<endl;
    cout<<st.size2()<<endl;

    cout<<st.pop1()<<endl;
    cout<<st.pop1()<<endl;
    cout<<st.pop1()<<endl;
    cout<<st.pop2()<<endl;
    cout<<st.pop2()<<endl;
    cout<<st.pop2()<<endl;
    cout<<st.pop2()<<endl;

    cout<<st.size1()<<endl;
    cout<<st.size2()<<endl;
    return 0;
}