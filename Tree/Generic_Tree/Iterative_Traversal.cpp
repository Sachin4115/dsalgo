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

void preAndPostOpt(node* root){
    vector<int> pre;
    vector<int> post;
    pair<node*,int> p;
    stack<pair<node*,int>> st;
    p.first=root;
    p.second=-1;
    st.push(p);
    while(!st.empty()){
        if(st.top().second==-1){
            pre.push_back(st.top().first->data);
            st.top().second++;
        }else if(st.top().second<st.top().first->children.size()){
            st.push({st.top().first->children[st.top().second++],-1});
        }else{
            post.push_back(st.top().first->data);
            st.pop();
        }
    }
    for(int i:pre){
        cout<<i<<" ";
    }
    cout<<endl;
    for(int i:post){
        cout<<i<<" ";
    }
    cout<<endl;
}

// void postOrder(node* root){
//     stack<node*>st;
//     st.push(root);
//     while(!st.empty()){

//     }
// }

int main()
{

    vector<int> input = {1,2,3,-1,-1,4,5,-1,6,7,-1,8,-1,-1,9,-1,-1,10,11,-1,12,-1,-1,-1};
    node* root = createTree(input);

    preOrder(root);
    cout<<endl;
    preAndPostOpt(root);

    return 0;
}