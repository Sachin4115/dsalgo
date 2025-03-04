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

struct ans{
    bool isBST;
    int min;
    int max;
    node* largestBST;
    int size;
};

ans* biggestBST(node* root){
    if(root==NULL){
        ans* a = new ans();
        a->isBST=1;
        a->max=INT_MIN;
        a->min=INT_MAX;
        a->largestBST=NULL;
        a->size=0;
        return a;
    }

    ans* l = biggestBST(root->left);
    ans* r = biggestBST(root->right);

    ans* c = new ans();
    c->isBST = (root->data>l->max && root->data<r->min) && l->isBST && r->isBST;
    c->max=max(root->data,max(l->max,r->max));
    c->min=min(root->data,min(l->min,r->min));
    if(c->isBST){
        c->largestBST = root;
        c->size = l->size+r->size+1;
    }else if(l->size>r->size){
        c->size=l->size;
        c->largestBST=l->largestBST;
    }else{
        c->size=r->size;
        c->largestBST=r->largestBST;

    }
    return c;
}

int main()
{
    vector<int> arr = {50,25,12,-1,-1,37,30,-1,-1,-1,75,62,-1,700,-1,-1,87,-1,-1};
    node* root = construct(arr);

    ans* reqnode = biggestBST(root);

    cout<<reqnode->largestBST->data<<"@"<<reqnode->size<<endl;

    return 0;
}