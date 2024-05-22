#include <iostream>
#include <string>
#include <vector>
#include <stack>
#include <queue>
#include <algorithm>
using namespace std;

struct node{
    int data;
    vector<node*> children;

    node(int val){
        data=val;
        children={};
    }

};

void traversalWithLevel(node* root){
    queue<node*> mainQ;
    queue<node*> childQ;

    mainQ.push(root);

    while(!mainQ.empty()){
        cout<<mainQ.front()->data<<" ";
        for(node* itr:mainQ.front()->children){
            childQ.push(itr);
        }
        mainQ.pop();
        if(mainQ.empty()){
            cout<<endl;
            mainQ=childQ;
            childQ={};
        }
    }
}

void mirror(node* root){

    for(node* itr:root->children){
        mirror(itr);
    }
    reverse(root->children.begin(),root->children.end());
}

void remove_leaf(node* root){
    for(int i=root->children.size()-1;i>=0;i--){
        if(root->children[i]->children.size()==0){
            root->children.erase(root->children.begin()+i);
        }
    }

    for(node* itr:root->children){
        remove_leaf(itr);
    }
}

int main()
{

    // Code for creating a generic tree
    vector<int> input = {10,20,50,-1,60,-1,-1,30,70,-1,80,110,-1,120,-1,-1,90,-1,-1,40,100,-1,-1,-1};

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

    traversalWithLevel(root);
    mirror(root);
    cout<<endl;
    traversalWithLevel(root);
    remove_leaf(root);
    cout<<endl;
    traversalWithLevel(root);


    return 0;
}