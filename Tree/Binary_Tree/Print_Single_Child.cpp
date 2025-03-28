#include <iostream>
#include <vector>
#include <stack>
#include <queue>
using namespace std;

struct node{
    int data;
    node* left;
    node* right;
    node(int val){
        data=val;
        left=NULL;
        right=NULL;
    }
};

node* construct(vector <int> &arr){
    stack<pair<node* , int>>st;
    node* root = new node(arr[0]);
    pair <node* , int> p = {root,1};
    st.push(p);
    int i=1;
    while(!st.empty()){
        if(st.top().second==1){
            st.top().second++;
            if(arr[i]==-1){
                i++;
                continue;
            }else{
                node* newnode = new node(arr[i]);
                st.top().first->left=newnode;
                st.push({newnode,1});
                i++;
            }
        }
        else if(st.top().second==2){
            st.top().second++;
            if(arr[i]==-1){
                i++;
                continue;
            }else{
                node* newnode = new node(arr[i]);
                st.top().first->right=newnode;
                st.push({newnode,1});
                i++;
            }
        }
        else{
            st.pop();
        }
    }
    return root;
}

void singleChildnode(node* root){
    if(root==NULL)
        return;
    if(!root->left&&root->right){
        cout<<root->data<<" ";
    }if(root->left && !root->right){
        cout<<root->data<<" ";
    }
    singleChildnode(root->left);
    singleChildnode(root->right);
}

int main()
{
    vector<int> arr = {50,25,12,-1,-1,37,30,-1,-1,-1,75,62,-1,70,-1,-1,-1};
    node* root = construct(arr);
    singleChildnode(root);
    return 0;
}