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

void preOrder(node* root){
    stack<node*>st;
    st.push(root);
    while(!st.empty()){
        cout<<st.top()->data<<" ";
        node* t = st.top();
        st.pop();
        if(t->children.size()>0){
            for(int i=t->children.size()-1;i>=0;i--){
                st.push(t->children[i]);
            }
        }
    }
}

// void postOrder(node* root){
//     stack<node*>st;
//     st.push(root);
//     while(!st.empty()){

//     }
// }

int main()
{

    vector<int> input = {1,2,3,-1,-1,4,5,-1,6,7,-1,-1,9,-1,-1,10,11,-1,12,-1,-1,-1};
    node* root = createTree(input);

    preOrder(root);
    cout<<endl;
    postOrder(root);
    cout<<endl;

    return 0;
}