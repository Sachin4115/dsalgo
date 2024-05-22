#include <iostream>
#include <string>
#include <vector>
#include <stack>
#include <queue>
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

node* getTail(node* root){
    while(root->children.size()>0){
        root=root->children[0];
    }
    return root;
}

void linearize(node* root){
    for(node* itr:root->children){
        linearize(itr);
    }
    while(root->children.size()>1){
        node* lc = root->children[root->children.size()-1];
        root->children.pop_back();
        node* secondLastTail = getTail(root->children[root->children.size()-1]);
        secondLastTail->children.push_back(lc);

    }
}

node* linearizeEfficient(node* root){

    if(root->children.size()==0)
        return root;

    node* lastTail = linearizeEfficient(root->children[root->children.size()-1]);
    while(root->children.size()>1){
        node* last = root->children[root->children.size()-1];
        root->children.pop_back();
        node* secondLastTail = linearizeEfficient(root->children[root->children.size()-1]);
        secondLastTail->children.push_back(last);
    }
    return lastTail;

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
    cout<<endl;
    // linearize(root);
    // traversalWithLevel(root);
    linearizeEfficient(root);
    traversalWithLevel(root);


    return 0;
}