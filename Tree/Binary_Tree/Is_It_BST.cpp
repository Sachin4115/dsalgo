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

bool ans;
pair<int,int> checkBST(node* root){
    if(!root)
        return {INT_MAX,INT_MIN};
    if(ans){
        pair l = checkBST(root->left);
        pair r = checkBST(root->right);

        if(root->data>r.first || root->data<l.second){
            ans=false;
        }else{
            int d=root->data;
            int a=min(d, min(l.first,r.first));
            int b=max(d, max(l.second,r.second));
            return {a,b};
        }
    }
    return {INT_MAX,INT_MIN};
}

bool isBST(node* root, long long max = LLONG_MAX, long long min = LLONG_MIN){
    if(root==NULL){
        return true;
    }
    if(root->data<=min || root->data>=max){
        return false;
    }

    return isBST(root->left,root->data,min) && isBST(root->right,max,root->data);
}

int main()
{
    vector<int> arr = {50,25,12,-1,-1,37,30,-1,-1,-1,75,62,-1,70,-1,-1,87,-1,-1};
    node* root = construct(arr);
    ans=true;
    checkBST(root);
    cout<<ans<<endl;
    cout<<isBST(root)<<endl;
    return 0;
}