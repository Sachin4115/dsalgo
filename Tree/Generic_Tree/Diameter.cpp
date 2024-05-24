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

int di=0;
int diameter(node* root){
    int d1=-1;
    int d2=-1;
    for(node*itr:root->children){
        int d = diameter(itr);
        if(d>d1){
            d2=d1;
            d1=d;
        }else if(d>d2){
            d2=d;
        }
    }
    di=max(d1,d1+d2+2);
    return d1+1;


}

int main()
{

    vector<int> input = {10,20,50,-1,60,-1,-1,30,70,-1,80,110,-1,120,-1,-1,90,-1,-1,40,100,-1,-1,-1};
    node* root = createTree(input);

    int d= diameter(root);
    cout<<di<<endl;

    return 0;
}