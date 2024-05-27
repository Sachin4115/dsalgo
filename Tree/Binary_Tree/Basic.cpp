#include <iostream>
#include <vector>
#include <stack>
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
                node* newNode = new node(arr[i]);
                st.top().first->left=newNode;
                st.push({newNode,1});
                i++;
            }
        }
        else if(st.top().second==2){
            st.top().second++;
            if(arr[i]==-1){
                i++;
                continue;
            }else{
                node* newNode = new node(arr[i]);
                st.top().first->right=newNode;
                st.push({newNode,1});
                i++;
            }
        }
        else{
            st.pop();
        }
    }
    return root;
}

void display(node* root){
    if(root==NULL)
        return;
    string str;
    str += root->left!=NULL?to_string(root->left->data)+" ->":".  ->";
    str += to_string(root->data);
    str += root->right!=NULL?"<- "+to_string(root->right->data):"<-  .";
    cout<<str<<endl;
    display(root->left);
    display(root->right);
}

int main()
{
    vector<int> arr = {50,25,12,-1,-1,37,30,-1,-1,-1,75,62,-1,70,-1,-1,87,-1,-1};
    node* root = construct(arr);
    display(root);
    return 0;
}