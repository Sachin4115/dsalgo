#include <iostream>
#include <vector>
#include <stack>
#include <algorithm>
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

int size(node* root){
    if(root==NULL)
        return 0;
    return 1 + size(root->left) + size(root->right);
}
int sum(node* root){
    if(root==NULL)
        return 0;
    return root->data + sum(root->left) + sum(root->right) ;
}
int Max(node* root){
    if(root==NULL){
        return 0;
    }
    int m = max(root->data,Max(root->left));
    m = max(m,Max(root->right));
    return m;
}
int height(node* root){
    if(root==NULL)
        return -1;
    return max(height(root->left)+1,height(root->right)+1);
}


int main()
{
    vector<int> arr = {50,25,12,-1,-1,37,30,-1,-1,-1,75,62,-1,70,-1,-1,87,-1,-1};
    node* root = construct(arr);
    cout<<size(root)<<endl;
    cout<<sum(root)<<endl;
    cout<<Max(root)<<endl;
    cout<<height(root)<<endl;
    return 0;
}