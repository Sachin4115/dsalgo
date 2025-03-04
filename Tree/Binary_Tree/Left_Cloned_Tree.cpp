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

void leftclone(node* root){
    if(root==NULL)
        return;
    node* newLeft = new node(root->data);
    node* oldLeft = root->left;
    root->left=newLeft;
    newLeft->left=oldLeft;
    leftclone(oldLeft);
    leftclone(root->right);
}

void levelOrder(node* root){
    if(root==NULL)
        return;
    queue <node*> q;
    q.push(root);
    while(q.size()>0){
        int count = q.size();
        for(int i=0;i<count;i++){
            cout<<q.front()->data<<" ";
            if(q.front()->left!=NULL){
                q.push(q.front()->left);
            }
            if(q.front()->right!=NULL){
                q.push(q.front()->right);
            }
            q.pop();
        }
        cout<<endl;
    }
}

void backToNormal(node* root){
    if(root==NULL)
        return;
    if(root->left){
        root->left=root->left->left;
        backToNormal(root->left);
    }
    backToNormal(root->right);

}

int main()
{
    vector<int> arr = {50,25,12,-1,-1,37,30,-1,-1,-1,75,62,-1,70,-1,-1,87,-1,-1};
    node* root = construct(arr);
    levelOrder(root);
    cout<<endl;
    leftclone(root);
    levelOrder(root);
    cout<<endl;
    backToNormal(root);
    levelOrder(root);
    return 0;
}