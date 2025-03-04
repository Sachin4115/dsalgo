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

void printKLevelDeep(node* root,int k,node* blocked){
    if(root==NULL || k<0 || root==blocked)
        return;
    if(k==0){
        cout<<root->data<<" ";
    }
    printKLevelDeep(root->left,k-1,blocked);
    printKLevelDeep(root->right,k-1,blocked);
}

vector<node*> path;

bool nodeToRootPath(node* root,int k){
    if(root==NULL)
        return false;
    if(root->data==k){
        path.push_back(root);
        return true;
    }
    bool b1 = nodeToRootPath(root->left,k);
    if(b1){
        path.push_back(root);
        return true;
    }
    bool b2 = nodeToRootPath(root->right,k);
    if(b2){
        path.push_back(root);
        return true;
    }
    return false;
}

void printKFar(node* root,int d,int k){
    nodeToRootPath(root,d);
    for(int i=0;i<path.size();i++){
        printKLevelDeep(path[i],k-i,i==0?NULL:path[i-1]);
    }
}

void pathToLeafFromRoot(node* root, string path, int sum, int low,int high){
    if(!root)
        return;
    if(root->left == NULL && root->right==NULL){
        sum+=root->data;
        if(sum<=high && sum>=low){
            cout<<path<<" : "<<sum<<endl;
        }
        return;
    }
    pathToLeafFromRoot(root->left,path + to_string(root->data)+" ",sum+root->data,low,high);
    pathToLeafFromRoot(root->right,path + to_string(root->data)+" ",sum+root->data,low,high);
}

int main()
{
    vector<int> arr = {50,25,12,-1,-1,37,30,-1,-1,-1,75,62,-1,70,-1,-1,87,-1,-1};
    node* root = construct(arr);
    printKLevelDeep(root,2,NULL);
    cout<<endl;
    printKFar(root,12,2);
    pathToLeafFromRoot(root,"",0,100,250);
    return 0;
}