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

vector<int> path;

bool find(node* root,int k){
    if(root==NULL)
        return false;
    if(root->data==k){
        path.insert(path.begin(),root->data);
        return true;
    }
    bool b1 = find(root->left,k);
    if(b1){
        path.insert(path.begin(),root->data);
        return true;
    }
    bool b2 = find(root->right,k);
    if(b2){
        path.insert(path.begin(),root->data);
        return true;
    }
    return false;

}

int main()
{
    vector<int> arr = {50,25,12,-1,-1,37,30,-1,-1,-1,75,62,-1,70,-1,-1,87,-1,-1};
    node* root = construct(arr);
    cout<<find(root,87)<<endl;
    for(int v:path){
        cout<<v<<" ";
    }
    cout<<endl;
    return 0;
}