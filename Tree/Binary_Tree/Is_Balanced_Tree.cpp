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

pair<bool,int> isBBT(node* root){
    if(!root){
        return {1,0};
    }
    pair<bool,int> p1 = isBBT(root->left);
    pair<bool,int> p2 = isBBT(root->right);

    int h = max(p1.second,p2.second)+1;

    bool a = p1.first && p2.first && (abs(p1.second-p2.second)<=1);

    return {a,h};
}

int main()
{
    vector<int> arr = {50,10,20,30,-1,-1,-1,-1,60,-1,70,-1,80,-1,-1};
    node* root = construct(arr);
    pair<bool,int> ans = isBBT(root);
    cout<<ans.first<<endl;
    return 0;
}