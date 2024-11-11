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

node* construct(vector <int> &arr, int l, int h){
    if(l>h)
        return NULL;
    int m = (l + h) / 2;
    int d = arr[m];
    node* lc = construct(arr,l,m-1);
    node* rc = construct(arr,m+1,h);
    node* t = new node(d);
    t->left = lc;
    t->right = rc;
    return t;
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

node* addNode(node* root, int v){
    if(root==NULL)
        return new node(v);
    if(root->data>v){
        root->left=addNode(root->left,v);
    }else{
        root->right=addNode(root->right,v);
    }
    return root;
}

int main()
{
    vector<int> arr = {12 , 25 , 37 , 50 , 62 , 75 , 87};
    node* root = construct(arr,0,arr.size()-1);
    display(root);
    cout<<endl;
    display(addNode(root,90));
    return 0;
}