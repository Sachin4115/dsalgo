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

void preOrder(node* root){
    if(root==NULL){
        return;
    }
    cout<<root->data<<" ";
    preOrder(root->left);
    preOrder(root->right);
}
void inOrder(node* root){
    if(root==NULL){
        return;
    }
    inOrder(root->left);
    cout<<root->data<<" ";
    inOrder(root->right);

}
void postOrder(node* root){
    if(root==NULL){
        return;
    }
    postOrder(root->left);
    postOrder(root->right);
    cout<<root->data<<" ";

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

void iterativePreInPost(node* root){
    pair <node*, int> p = {root,1};
    stack<pair<node*,int>> st;
    st.push(p);
    vector<int>pre;
    vector<int>in;
    vector<int>post;
    while(!st.empty()){
        if(st.top().second==1){
            pre.push_back(st.top().first->data);
            st.top().second++;
            if(st.top().first->left!=NULL)
                st.push({st.top().first->left,1});
        }else if(st.top().second==2){
            in.push_back(st.top().first->data);
            st.top().second++;
            if(st.top().first->right!=NULL)
                st.push({st.top().first->right,1});
        }else if(st.top().second==3){
            post.push_back(st.top().first->data);
            st.pop();
        }
    }
    cout<<"Pre :";
    for(int i:pre){
        cout<<i<<" ";
    }
    cout<<endl;
    cout<<"In :";
    for(int i:in){
        cout<<i<<" ";
    }
    cout<<endl;
    cout<<"Post :";
    for(int i:post){
        cout<<i<<" ";
    }
    cout<<endl;
}

int main()
{
    vector<int> arr = {50,25,12,-1,-1,37,30,-1,-1,-1,75,62,-1,70,-1,-1,87,-1,-1};
    node* root = construct(arr);
    cout<<"Pre :";
    preOrder(root);
    cout<<endl;
    cout<<"In :";
    inOrder(root);
    cout<<endl;
    cout<<"Post :";
    postOrder(root);
    cout<<endl;
    cout<<"Level Order :"<<endl;
    levelOrder(root);
    cout<<endl;
    iterativePreInPost(root);
    return 0;
}