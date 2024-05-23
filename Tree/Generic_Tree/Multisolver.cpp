#include <iostream>
#include <string>
#include <vector>
#include <stack>
#include <queue>
using namespace std;

int s;
int Min;
int Max;
int h;
struct node{
    int data;
    vector<node*> children;

    node(int val){
        data=val;
        children={};
    }
};

node* createTree(vector<int> input){
    stack<node*> st;
    node* root = NULL;
    for(int i=0;i<input.size();i++){
        if(input[i]==-1)
            st.pop();
        else {
            node *t = new node(input[i]);
            if(st.size()>0){
                st.top()->children.push_back(t);
            }else{
                root=t;
            }
            st.push(t);
        }
    }
    return root;
}


void multisolver(node* root,int d){

    s+=1;
    Min=min(Min,root->data);
    Max=max(Max,root->data);
    h=max(h,d);

    for(node* itr:root->children){
        multisolver(itr,d+1);
    }
}

int main()
{

    // Code for creating a generic tree
    vector<int> input = {10,20,50,-1,60,-1,-1,30,70,-1,80,110,-1,120,-1,-1,90,-1,-1,40,100,-1,-1,-1};
    node* root = createTree(input);

    s=0;
    Min=INT_MAX;
    Max=INT_MIN;
    h=0;

    multisolver(root,0);

    cout<<s<<endl;
    cout<<Min<<endl;
    cout<<Max<<endl;
    cout<<h<<endl;

    return 0;
}