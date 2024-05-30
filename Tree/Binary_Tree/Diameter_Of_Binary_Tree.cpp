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

int di;
int diameter(node* root){
    if(!root)
        return -1;
    int d1=-1;
    int d2=-1;

    d1 = diameter(root->left);
    d2 = diameter(root->right);

    if(di<d1+d2+2)
        di=d1+d2+2;
    return d1>d2?d1+1:d2+1;
}

struct Pair{
    int diameter;
    int height;
    Pair(){
        diameter=0;
        height=-1;
    }
};

Pair* diameter2(node* root){
    if(!root)
        return new Pair();
    Pair* leftPair = diameter2(root->left);
    Pair* rightPair = diameter2(root->right);

    Pair* thisPair = new Pair();
    thisPair->diameter=leftPair->height+rightPair->height+2;
    thisPair->height=max(leftPair->height,rightPair->height)+1;

    thisPair->diameter = max(thisPair->diameter,max(leftPair->diameter,rightPair->diameter));

    return thisPair;
}

int main()
{
    vector<int> arr = {50,25,12,-1,-1,37,30,-1,-1,-1,75,62,-1,70,-1,-1,87,-1,-1};
    node* root = construct(arr);
    di=0;
    diameter(root);
    cout<<di<<endl;
    Pair* ans = diameter2(root);
    cout<<ans->diameter<<endl;
    return 0;
}