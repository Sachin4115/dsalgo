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

bool compareTreeShape(node* root1, node* root2){
    if(root1->children.size()!=root2->children.size()){
        return false;
    }
    for(int i=0;i<root1->children.size();i++){
        if(!compareTreeShape(root1->children[i],root2->children[i])){
            return false;
        }
    }
    return true;
}

bool compareMirrorImage(node *root1,node *root2){
    if(root1->children.size()!=root2->children.size())
        return false;
    for(int i=0;i<root1->children.size();i++){
        if(!compareMirrorImage(root1->children[i],root2->children[root2->children.size()-i-1]))
            return false;
    }
    return true;
}

// Symmetric images are mirror image of themselves
bool checkSymmetric(node* root){
    return compareMirrorImage(root,root);
}

int main()
{

    // Code for creating a generic tree
    vector<int> input1 = {10,20,50,-1,60,-1,-1,30,70,-1,80,110,-1,120,-1,-1,90,-1,-1,40,100,-1,-1,-1};
    vector<int> input2 = {1,2,3,-1,-1,4,5,-1,6,7,-1,8,-1,-1,9,-1,-1,10,11,-1,12,-1,-1,-1};
    vector<int> input3 = {1,2,3,-1,-1,4,5,-1,6,7,-1,8,-1,-1,9,-1,-1,10,11,-1,-1,-1};
    node* root1 = createTree(input1);
    node* root2 = createTree(input2);
    node* root3 = createTree(input3);

    // cout<<compareTreeShape(root1,root2);

    // cout<<compareMirrorImage(root1,root2);

    cout<<checkSymmetric(root3);

    return 0;
}